#include "calcnonzero.h"
#include <thread>
#include <cmath>
#include "matrix.h"
#include <vector>
#include <future>
namespace dom
{
    namespace details
    {
        size_t CalcNonZeroWorker(matrix m, size_t combinations, int min, int max)
        {
            auto thread_id = std::this_thread::get_id();

            size_t numOfNonZero{};

            int percentFinished{0};
            for (size_t i = 0; i < combinations; i++)
            {
                int det{m.Det()};
                if (det != 0)
                    numOfNonZero++;

                // next combination
                dom::NextCombination(m, min, max);

                double percent{((double)i * 100 / combinations)};
                if (percentFinished < percent)
                {
                    percentFinished++;
                    std::cout << "thread " << thread_id << ": Progress " << percentFinished << "%,\tcombination num " << i << "\n";
                }
            }
            return numOfNonZero;
        }

    } // namespace details

    // calculate all non zero det matrices of dimension x dimension
    // where value can be from min to max (inclusive)
    size_t CalcNonZero(size_t dimension, int min, int max)
    {
        const unsigned int numCores = std::thread::hardware_concurrency();
        size_t numOfAllPossibleCombinations{static_cast<size_t>(std::pow(max + 1, dimension * dimension))};
        // signle thread
        if (numCores == 0 || numCores == 1)
        {
            size_t numOfNonZero{};
            matrix m{dimension, min};
            numOfNonZero = details::CalcNonZeroWorker(m, numOfAllPossibleCombinations, min, max);
            return numOfNonZero;
        }
        // multithread
        else
        {
            std::vector<std::thread> threads{};
            std::vector<std::future<size_t>> promises{};
            promises.reserve(numCores);
            threads.reserve(numCores);

            matrix m{dimension, min};
            size_t combPerThread{numOfAllPossibleCombinations / numCores};

            for (size_t i = 0; i < numCores; i++)
            {
                // on last iter
                std::packaged_task<size_t(matrix, size_t, int, int)> task{&details::CalcNonZeroWorker};
                promises.push_back(task.get_future());
                if (i + 1 == numCores)
                {
                    threads.push_back(std::thread{std::move(task), m, combPerThread + (numOfAllPossibleCombinations % numCores), min, max});
                }
                else
                {
                    threads.push_back(std::thread{std::move(task), m, combPerThread, min, max});
                    NextCombination(m, min, max, combPerThread);
                }
            }
            for (auto& it: threads) {
                it.join();
            }
            size_t nonzero{};
            for (auto& it: promises) {
                nonzero += it.get();
            }
            return nonzero;
        }
    }
} // namespace dom
