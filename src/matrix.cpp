#include "matrix.h"

namespace dom
{
    void matrix::InitMatrix(size_t dimensions)
    {
        _dimensions = dimensions;
        _arr.resize(dimensions * dimensions);
    }
    matrix::matrix(size_t dimensions)
    {
        InitMatrix(dimensions);
    }
    matrix::matrix(size_t dimensions, std::vector<std::vector<int>> mat)
    {
        InitMatrix(dimensions);
        for (size_t i{}; i < dimensions; i++) {
            for (size_t j = 0; j < dimensions; j++)
            {
                At(i, j) = mat[i][j];
            }
        }
    }
    matrix::matrix(size_t dimensions, int initValue) {
        InitMatrix(dimensions);
        std::fill(_arr.begin(), _arr.end(), initValue);
    }

    const int matrix::At(size_t i, size_t j) const {
        return _arr[_dimensions * i + j];
    }
    int &matrix::At(size_t i, size_t j) {
        return _arr[_dimensions * i + j];
    }

    void matrix::Print() const {
        for (size_t i = 0; i < _dimensions; i++)
        {
            std::cout << "[ ";
            for (size_t j = 0; j < _dimensions; j++)
            {
                std::cout << At(i, j) << " ";
            }
            std::cout << "]\n";
        }
    }

    void matrix::Fill(int value) {
        std::fill(_arr.begin(), _arr.end(), value);
    }
    // max inclusive 
    void NextCombination(matrix& m, int min, int max) {
        if (min > max)
            throw std::runtime_error("min > max");
        
        size_t dim{m.Dimensions()};

        int carry{1};
        for (size_t i = 0; i < dim; i++)
        {
            for (size_t j = 0; j < dim; j++)
            {
                int& n = m.At(i, j);
                
                if (n + carry > max) {
                    n = min;
                    carry = 1;
                } else {
                    n += carry;
                    carry = 0;
                    return;
                }
            }
        }
        if (carry > 0) {
            m.Fill(min);
        }
    }
} // namespace dom