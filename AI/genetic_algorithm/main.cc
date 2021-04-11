#include <iostream>

#include "./inc/chromosome_set.h"

using namespace std;

int main () {
    ChromosomeSet chromosome_set;
    chromosome_set.create(20);
    chromosome_set.write("g0.txt");

    chromosome_set.generate(1);
    chromosome_set.write("g1.txt");

    chromosome_set.generate(1);
    chromosome_set.write("g2.txt");

    chromosome_set.generate(1);
    chromosome_set.write("g3.txt");

    chromosome_set.generate(1);
    chromosome_set.write("g4.txt");

    chromosome_set.generate(1);
    chromosome_set.write("g5.txt");

    chromosome_set.generate(5);
    chromosome_set.write("g10.txt");

    return 0;
}