#include <iostream>
#include "matrix.h"
#include <cmath>
#include "calcnonzero.h"
#include <chrono> // for std::chrono functions
#include <thread>
class Timer
{
private:
    // Type aliases to make accessing nested type easier
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<Clock> m_beg{Clock::now()};

public:
    void reset()
    {
        m_beg = Clock::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
};

int main()
{
    const int min = 0;    // 0
    const int max = 3;   // 10
    const size_t dim = 4; // 3
#ifndef NDEBUG
    std::cout << "testing of det function" << std::endl;
    dom::matrix m2{3, {{6, 1, 1}, {4, -2, 5}, {2, 8, 7}}};
    m2.Print();
    std::cout << "result: " << m2.Det() << std::endl;
    std::cout << "true result: " << -306 << std::endl;
#endif
    // number of combinations that are non zero determinant
    size_t numOfAllPossibleCombinations{static_cast<size_t>(std::pow(max + 1, dim * dim))};
    std::cout << "\n";
    Timer t;

    std::cout << "all combinations: " << numOfAllPossibleCombinations << std::endl;
    std::cout << "min " << min << " max " << max << "\n";
    std::cout << "dimensions: " << dim << "x" << dim << "\n";
    std::cout << "available hardware concurrency: " << std::thread::hardware_concurrency() << "\n";

                                                           size_t numOfNonZero = dom::CalcNonZero(dim, min, max);
#ifndef NDEBUG
    std::cout << "Time: " << t.elapsed() << "\n";
#endif
    std::cout << "non zero: \t" << numOfNonZero << std::endl;

    std::cout << "all possible: \t" << numOfAllPossibleCombinations << std::endl;
    std::cout << "time: \t\t" << t.elapsed() << "\n";
    std::cout << "min " << min << " max " << max << "\n";
    std::cout << "dimensions: " << dim << "x" << dim << "\n";
    std::cout << "available hardware concurrency: " << std::thread::hardware_concurrency() << "\n";
}