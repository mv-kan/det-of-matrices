#if !defined(CALCNONZERO_H)
#define CALCNONZERO_H

#include <iostream>
#include "matrix.h"
namespace dom
{
    namespace details
    {
        // matrix m - starting point
        // combinations - how many combination to calculate
        // min max - min max value
        size_t CalcNonZeroWorker(matrix m, size_t combinations, int min, int max);
    } // namespace details

    // calculate all non zero det matrices of dimension x dimension
    // where value can be from min to max (inclusive)
    size_t CalcNonZero(size_t dimension, int min, int max);
} // namespace dom

#endif // CALCNONZERO_H
