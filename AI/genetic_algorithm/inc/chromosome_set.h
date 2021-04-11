/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-04-04 08:48:23
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-04-11 16:46:56
 * @Description  :
*********************************************/

#ifndef GENETIC_ALGORITHM_INC_CHROMOSOME_SET_H_
#define GENETIC_ALGORITHM_INC_CHROMOSOME_SET_H_

#include <vector>

#include "chromosome.h"

class ChromosomeSet {
private:
    // Using vector as a set.
    std::vector<Chromosome> _set;
    long long unsigned int _scale;

    double Function(double x1, double x2);

public:
    ChromosomeSet(int scale = 100);
    ~ChromosomeSet();

    // Create some chromosomes randomly then put them inside the set.
    void create(int chromosome_num);
    void generate(int num);

    void print(long long unsigned int num = 20);

    // Write the answer into a file.
    void write(std::string file_name);
};

#endif
