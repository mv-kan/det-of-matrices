#if !defined(MATRIX_H)
#define MATRIX_H

#include <iostream>
#include <array>
#include <vector>

// det of matrices (dom)
namespace dom
{
    class matrix
    {
    private:
        std::vector<int> _arr{};
        size_t _dimensions{};

        void InitMatrix(size_t dimensions);
    public:
        matrix(size_t dimensions);
        matrix(size_t dimensions, std::vector<std::vector<int>> mat);
        matrix(size_t dimensions, int initValue);
        ~matrix() = default;

        const int At(size_t i, size_t j) const;
        int &At(size_t i, size_t j);

        void Print() const;

        size_t Dimensions() const{ return _dimensions; }

        void Fill (int value);
    };
    // this function adds to matrix value 1 and if this value overflows max, reset overflowed value with min and add 1 to next cell
    void NextCombination(matrix& m, int min, int max);
} // namespace dom

#endif // MATRIX_H
