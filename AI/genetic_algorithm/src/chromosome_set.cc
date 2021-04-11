/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-04-04 08:48:23
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-04-11 16:58:42
 * @Description  :
*********************************************/
#include <ctime>
#include <cmath>
#include <algorithm>

#include <iostream>
#include <fstream>

#include "../inc/chromosome_set.h"

using std::sort;

using std::default_random_engine;
using std::uniform_real_distribution;

using std::vector;

using std::cout;
using std::endl;

ChromosomeSet::ChromosomeSet(int scale) :
    _scale(scale) {
        _set.clear();
    }

ChromosomeSet::~ChromosomeSet() {}

double ChromosomeSet::Function(double x1, double x2) {
    const double pi = 3.14159;
    return 20 + x1 * x1 + x2 * x2 -
        10 * (cos(2 * pi * x1) + cos(2 * pi * x2));
}

// ====== ======

void ChromosomeSet::create(int chromosome_num) {
    for (int count = 0; count < chromosome_num; ++ count) {
        _set.push_back(Chromosome());
    }
}

void ChromosomeSet::generate(int num) {
    int generation = 0;

    do {
        cout << "G" << generation << " generating ..." << endl;

        double total_fit = 0;
        for (Chromosome & c : this->_set) {
            double x1 = c.getX1();
            double x2 = c.getX2();
            double result = Function(x1, x2);

            c.setFit(1 / result);
            total_fit += 1 / result;
        }

        // Sort by fit descendingly.
        sort(_set.begin(), _set.end(),
            [](const Chromosome & c1, const Chromosome & c2) {
                return c1.getFit() > c2.getFit();
            });


        default_random_engine engine(time(nullptr));
        uniform_real_distribution<double> distribution(0, 1);

        vector<Chromosome> parent;
        for (long long unsigned int i = 0; i < _set.size(); ++ i ) {
            double rand_num = distribution(engine);
            double add_up = 0;
            for (Chromosome c : _set) {
                if (rand_num <= add_up) {
                    parent.push_back(c);
                }
                else {
                    add_up += c.getFit() / total_fit;
                }
            }
        }

        if (parent.size() % 2 != 0 ) parent.pop_back();

        for (auto iter = parent.begin(); iter < parent.end(); iter += 2) {
            for (auto c : Chromosome::crossover(* iter, *(iter + 1))) {
                double rand_num = distribution(engine);
                if (rand_num <= 0.001) c.mutate();

                double x1 = c.getX1();
                double x2 = c.getX2();
                double result = Function(x1, x2);

                c.setFit(1 / result);

                _set.push_back(c);
            }
        }

        // Sort by fit descendingly.
        sort(_set.begin(), _set.end(),
            [](const Chromosome & c1, const Chromosome & c2) {
                return c1.getFit() > c2.getFit();
            });

        while (_set.size() > _scale) {
            _set.pop_back();
        }


        ++ generation;
        cout << "G" << generation << " generation created, "
            << "total chromosome number: " << _set.size() << endl;
    } while (generation < num);
}

void ChromosomeSet::print(long long unsigned int num) {
    if (num > _set.size()) {
        for (Chromosome c : _set) {
            c.print();
        }
    }
    else {
        for (long long unsigned int i = 0; i < num; ++ i) {
            _set.at(i).print();
        }
    }
}

void ChromosomeSet::write(std::string file_name) {
    std::ofstream output_file;
    output_file.open(file_name, std::ios::out | std::ios::trunc);

    output_file << "vector X1:"<< endl;
    for (Chromosome c : _set) {
        c.writeX1(output_file);
        output_file << endl;
    }
    output_file << endl;
    output_file << "vector X2:"<< endl;
    for (Chromosome c : _set) {
        c.writeX2(output_file);
        output_file << endl;
    }

    output_file.close();
}