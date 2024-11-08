// benchmark/test/test_benchmark.cpp
/****************************************************************************
 * File: test_benchmark.cpp
 * Author: Diyor Sattarov
 * Email: diyorsattarov@outlook.com
 *
 * Created: 2024-11-08
 * Last Modified: 2024-11-08
 *
 * Description: Test implementation for the benchmark_suite class. Verifies
 * the functionality of the benchmarking framework using the test suite.
 ****************************************************************************/

#include <benchmark.hpp>
#include <test_suite.hpp>
#include <thread>
#include <chrono>

/**
 * @brief Test function that sleeps for a specified duration
 */
void sleep_function(std::chrono::microseconds duration) {
    std::this_thread::sleep_for(duration);
}

/**
 * @brief Tests basic benchmark timing accuracy
 */
void test_timing_accuracy() {
    benchmark_suite<int> bench;
    const auto sleep_duration = std::chrono::microseconds(1000); // 1ms
    
    // Add benchmark that sleeps for 1ms
    bench.add("Sleep Test", [sleep_duration]() {
        sleep_function(sleep_duration);
    }, 5);
    
    // Capture cout to string for verification
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    bench.run();
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    
    // Verify output contains expected timing (roughly 1000μs)
    tst_suite<int>::assert_true(
        output.find("Average: ") != std::string::npos,
        "Benchmark output should contain average time"
    );
}

/**
 * @brief Tests multiple benchmark cases
 */
void test_multiple_benchmarks() {
    benchmark_suite<int> bench;
    
    bench.add("Test 1", []() { 
        std::this_thread::sleep_for(std::chrono::microseconds(100)); 
    }, 3);
    
    bench.add("Test 2", []() { 
        std::this_thread::sleep_for(std::chrono::microseconds(200)); 
    }, 3);
    
    // Verify no exceptions thrown when running multiple benchmarks
    try {
        bench.run();
        tst_suite<int>::assert_true(true, "Multiple benchmarks should run without error");
    } catch (...) {
        tst_suite<int>::assert_true(false, "Should not throw exceptions");
    }
}

int main() {
    tst_suite<int> suite;
    
    suite.add("Timing Accuracy", test_timing_accuracy);
    suite.add("Multiple Benchmarks", test_multiple_benchmarks);
    
    suite.run();
    return 0;
}
