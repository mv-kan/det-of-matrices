#include <iostream>
#include "matrix.h"
#include <cmath>

#ifndef NDEBUG
#include <chrono> // for std::chrono functions
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
#endif
#include <chrono> // for std::chrono functions
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
    const int min = 0;
    const int max = 10;
    const size_t dim = 3;

    dom::matrix m{dim, min};
    // number of combinations that are non zero determinant
    size_t numOfNonZero{};
    size_t numOfAllPossibleCombinations{static_cast<size_t>(std::pow(max + 1, dim * dim))};
    
    Timer t;
#ifndef NDEBUG
    Timer t;
#endif
    std::cout << "all combinations: " << numOfAllPossibleCombinations << std::endl;
    std::cout << "min " << min << " max " << max << "\n";
    std::cout << "dimensions: " << dim << "x" << dim << "\n";
    int percentFinished{0};
    for (size_t i = 0; i < numOfAllPossibleCombinations; i++)
    {
        int det{m.Det()};
        if (det != 0)
            numOfNonZero++;

#ifndef NDEBUG
        std::cout << "Combination: \n";
        m.Print();
        std::cout << "Iteration: " << i << "\n";
        std::cout << "Det: " << det << "\n";
#endif
        // next combination
        dom::NextCombination(m, min, max);

        double percent { ((double)i * 100 / numOfAllPossibleCombinations) };
        if (percentFinished < percent) {
            percentFinished++;
            std::cout << "Progress " << percentFinished << "%, combination num " << i << "\n";
        }
    }

#ifndef NDEBUG
    std::cout << "Time: " << t.elapsed() << "\n";
#endif
    std::cout << "non zero: \t" << numOfNonZero << std::endl;
    std::cout << "all possible: \t" << numOfAllPossibleCombinations << std::endl;
    std::cout << "time: \t\t" << t.elapsed() << "\n";
    std::cout << "min " << min << " max " << max << "\n";
    std::cout << "dimensions: " << dim << "x" << dim << "\n";
}