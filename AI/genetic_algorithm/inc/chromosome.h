/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-04-02 09:22:20
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-04-11 16:57:10
 * @Description  :
*********************************************/

#ifndef GENETIC_ALGORITHM_INC_CHROMOSOME_H_
#define GENETIC_ALGORITHM_INC_CHROMOSOME_H_

#include <random>
#include <vector>

class Chromosome {
private :
    double _x1, _x2;

    // This variable only meaningful when there are multiple chromosomes
    // needed to produce next generation.
    // Set to 0 by default.
    double _fit;

    static std::default_random_engine _engine;

public :
    Chromosome();
    Chromosome(double x1, double x2);
    Chromosome(const Chromosome & obj);
    ~Chromosome();

    // Two in, two out.
    static std::vector<Chromosome>
        crossover(Chromosome & c1, Chromosome & c2);

    void random();

    // Use random as mutation.
    void mutate();

    double getX1() const;
    double getX2() const;
    double getFit() const;

    void setFit(double rate);

    void print();

    void writeX1(std::ofstream & output_file);
    void writeX2(std::ofstream & output_file);
};

#endif