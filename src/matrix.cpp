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
    matrix::matrix(size_t dimensions, const std::vector<std::vector<int>>& mat)
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
    matrix::matrix(size_t dimensions, const std::vector<int>& mat) {
        InitMatrix(dimensions);

        for (size_t i = 0; i < mat.size(); i++) {
            At(i / dimensions, i % dimensions) = mat[i];
        }
    }

    int matrix::At(size_t i, size_t j) const {
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

    int matrix::Det() const {
        if (_dimensions == 2) {
            return At(0, 0) * At(1, 1) - At(0, 1) * At(1, 0);
        }
        int result{};

        // inner matrix
        size_t submat_size{(_dimensions - 1) * (_dimensions - 1)};
        std::vector<int> submat(submat_size);
        size_t submat_i{};
        for (size_t i = 0; i < _dimensions; i++)
        {
            if (At(0, i) == 0) {
                continue;
            }
            int tmp{};
            
            // fill the matrix
            for (size_t row = 1; row < _dimensions; row++)
            {
                for (size_t col = 0; col < _dimensions; col++)
                {
                    if (col == i)
                        continue;
                    submat[submat_i] = At(row, col);
                    submat_i++;
                }
            }
            submat_i = 0;
            tmp = matrix{_dimensions - 1, submat}.Det();

            result += (i % 2 == 0) ? tmp : -tmp;
        }
        return result;
    }
} // namespace dom