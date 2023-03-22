#if !defined(MATRIX_H)
#define MATRIX_H

#include <iostream>
#include <array>

// det of matrices (dom)
namespace dom
{
    class Test{};
    // N is dimension of matrix, set 2 for 2 x 2 matrix, or 3 for 3 x 3
    template<size_t N>
    class Matrix
    {
    private:
        std::array<int, N * N> _arr{};
        // min or max value of one number in matrix
        int _min{}, _max{};
    public:
        Matrix(int min, int max);
        
        ~Matrix() = default;

        // handles overflow by j and i, can enter negative values
        int &At(ssize_t i, ssize_t j);

        int Determinant() const;

        inline size_t Dimension() { return _arr.size() / _arr.size(); };
        // add one value to one cell and if overflow _max then add one value to next position cell and etc etc
        // this is for easier way going through all possible matrices within _min - _max values for N x N matrix
        void NextMatrix();

        void Print() const;
    };
} // namespace dom

#endif // MATRIX_H
