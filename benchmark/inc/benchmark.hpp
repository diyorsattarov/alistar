// benchmark/inc/benchmark.hpp
/****************************************************************************
 * File: benchmark.hpp
 * Author: Diyor Sattarov
 * Email: diyorsattarov@outlook.com
 *
 * Created: 2024-11-08
 * Last Modified: 2024-11-08
 *
 * Description: A templated benchmark suite for performance testing. Provides
 * functionality to measure and compare execution times of different operations
 * with configurable iterations and detailed timing reports.
 ****************************************************************************/

#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <chrono>
#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

template <typename T>
class benchmark_suite {
    public:
        using benchmark_case = std::function<void()>;
        using time_point = std::chrono::high_resolution_clock::time_point;
        using duration = std::chrono::microseconds;

        /**
         * @brief Adds a benchmark case to the suite
         * @param name Name of the benchmark
         * @param bc Function to benchmark
         * @param iterations Number of times to run the benchmark
         */
        void add(const std::string& name, benchmark_case bc, size_t iterations = 1000) {
            benchmarks.push_back({name, bc, iterations});
        }

        /**
         * @brief Executes all registered benchmarks
         * @post Prints timing results to stdout
         */
        void run() const {
            const std::string blue = "\033[34m";
            const std::string reset = "\033[0m";

            std::cout << "\nRunning Benchmarks...\n\n";

            for (const auto& [name, bc, iterations] : benchmarks) {
                // Warm-up run
                bc();

                auto [total_time, avg_time] = time_function(bc, iterations);

                std::cout << blue << "[BENCH] " << reset 
                    << std::left << std::setw(30) << name 
                    << "Average: " << std::fixed << std::setprecision(3) 
                    << avg_time << " μs "
                    << "(Total: " << total_time << " μs for " 
                    << iterations << " iterations)\n";
            }
            std::cout << "\nBenchmarking Complete!\n";
        }

    private:
        struct benchmark_info {
            std::string name;
            benchmark_case bc;
            size_t iterations;
        };

        /**
         * @brief Times the execution of a function
         * @param func Function to time
         * @param iterations Number of iterations
         * @return Pair of {time_span, avg_duration} in microseconds
         */
        std::pair<double, double> time_function(const benchmark_case& func, 
                size_t iterations) const {
            auto start = std::chrono::high_resolution_clock::now();

            for(size_t i = 0; i < iterations; ++i) {
                func();
            }

            auto end = std::chrono::high_resolution_clock::now();
            // Change variable name to avoid conflict with type alias
            auto time_span = std::chrono::duration_cast<duration>(end - start).count();

            double avg_duration = static_cast<double>(time_span) / iterations;
            return {time_span, avg_duration};
        }

        std::vector<benchmark_info> benchmarks;
};

#endif // BENCHMARK_HPP
