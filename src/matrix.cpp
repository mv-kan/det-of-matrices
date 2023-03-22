#include "matrix.h"

namespace dom
{
    template <size_t N>
    Matrix<N>::Matrix(int min, int max): _min{min}, _max{max}
    {

    }
    template <size_t N>
    int &Matrix<N>::At(ssize_t i, ssize_t j)
    {
        size_t dim = Dimension();
        return _arr.at((dim * (i % dim)) + (j % dim));
    }
    template <size_t N>
    int Matrix<N>::Determinant() const
    {
        size_t dim = _arr.size() / _arr.size();
        int subtrahend{}, subtractor{};
        size_t row{};
        for (size_t i{}; i < dim; i++) {
            int tmp{1};
            for (size_t j{i}; j < i + dim; j++)
            {
                tmp *= At(row, j);
                row++;
            }
            subtrahend += tmp;
            row = 0;
        }
        return 0;
    }

    // add one value to one cell and if overflow _max then add one value to next position cell and etc etc
    // this is for easier way going through all possible matrices within _min - _max values for N x N matrix
    template <size_t N>
    void Matrix<N>::NextMatrix() {

    }

    template <size_t N>
    void Matrix<N>::Print() const
    {
        size_t dim = Dimension();
        for (size_t i{}; i < dim; i ++) {
            std::cout << "[ ";
            for (size_t j{}; j < dim; j++) {
                std::cout << At(i, j) << " ";
            }
            std::cout << "]\n"; 
        }
        std::cout << "\n";
    }
} // namespace dom
