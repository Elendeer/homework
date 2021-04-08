/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-04-02 09:23:49
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-04-05 16:36:09
 * @Description  :
*********************************************/
#include <iostream>
#include <ctime>
#include <cmath>

#include "../inc/chromosome.h"

using std::default_random_engine;
using std::uniform_real_distribution;

using std::vector;

default_random_engine Chromosome::_engine(time(nullptr));

Chromosome::Chromosome() {
    _fit = 0;
    random();
}

Chromosome::Chromosome(double x1, double x2) :
    _x1(x1), _x2(x2) {

        _fit = 0;
    }

Chromosome::Chromosome(const Chromosome & obj) {
    _x1 = obj._x1;
    _x2 = obj._x2;

    _fit = obj._fit;
}

Chromosome::~Chromosome() {}


vector<Chromosome>
    Chromosome::crossover(Chromosome & c1, Chromosome & c2) {
    // A simulation of sigle-point-crossover.
    uniform_real_distribution<double> distribution(0, 1);
    double power_1 = distribution(_engine);
    double power_2 = distribution(_engine);

    Chromosome child_c1 = Chromosome(
        c1._x1 * power_1 + c2._x1 * (1 - power_1),
        c1._x2 * power_2 + c2._x2 * (1 - power_2));
    Chromosome child_c2 = Chromosome(
        c1._x1 * (1 - power_1) + c2._x1 * power_1,
        c1._x2 * (1 - power_2) + c2._x2 * power_2);

    return {child_c1, child_c2};
}

void Chromosome::random() {
    uniform_real_distribution<double> distribution(-5, 5);
    _x1 = distribution(_engine);
    _x2 = distribution(_engine);
}

void Chromosome::mutate() {
    random();
}

double Chromosome::getX1() const {
    return _x1;
}
double Chromosome::getX2() const {
    return _x2;
}
double Chromosome::getFit() const {
    return _fit;
}

void Chromosome::setFit(double rate) {
    _fit = rate;
}

void Chromosome::print() {
    using std::cout;
    using std::endl;
    cout << "x1: " << _x1 << "\tx2: " << _x2 << endl;
    cout << "fit: " << _fit << endl;
}