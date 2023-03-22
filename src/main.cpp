#include <iostream>
#include "matrix.h"
#include <cmath>
/*
TODO
rewrite matrix class so it can be passed and resized dynamically (be able to create objects of diffrenet dimensions))
use one dim vec to represent 2 dim matrix
use recursion for this task, creating new matrices along the way to 2 x 2 matrix to calc det
*/
int main() {
    const int min = 0;
    const int max = 10;
    const size_t dim = 2;
    dom::matrix m{
        dim,
        min
    };
    m.Print();
    for (int i = 0; i < std::pow(max + 1, dim * dim); i++) {
        dom::NextCombination(m, min, max);
        std::cout << "--- iteration n" << i << "---\n";
        m.Print();
        std::cout << "--------------------\n";
    }

    ;
}