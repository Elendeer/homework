#include <iostream>

#include "./inc/chromosome_set.h"

using namespace std;

int main () {
    ChromosomeSet chromosome_set;
    chromosome_set.create(20);
    chromosome_set.generate(100);
    chromosome_set.print();

    return 0;
}