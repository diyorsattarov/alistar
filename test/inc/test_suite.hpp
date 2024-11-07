/****************************************************************************
 * File: test_suite.hpp
 * Author: Diyor Sattarov
 * Email: diyorsattarov@outlook.com
 *
 * Created: 2024-10-05
 * Last Modified: 2024-10-07
 *
 * Description: This header file implements a generic test suite framework for
 * unit testing. It provides functionality to add and run test cases with
 * colorized output reporting. The suite includes basic assertion utilities
 * for equality checking and condition verification.
 *
 * Copyright (c) 2024 diyorsattarov. All rights reserved.
 ****************************************************************************/

#ifndef TEST_SUITE_HPP
#define TEST_SUITE_HPP

#include <iostream>
#include <functional>
#include <vector>
#include <string>

template <typename T>
class tst_suite {
public:
    /**
     * @brief Defines the type for test case functions
     */
    using test_case = std::function<void()>;

    /**
     * @brief Adds a new test case to the suite
     * @param name The name/description of the test case
     * @param tc The test case function to execute
     */
    void add(const std::string& name, test_case tc) {
        tests.push_back({name, tc});
    }

    /**
     * @brief Runs all registered test cases and reports results
     * @post Displays colored output for pass/fail status of each test
     */
    void run() const {
        size_t passed = 0;
        // ANSI color codes for formatting
        const std::string green = "\033[32m";
        const std::string red = "\033[31m";
        const std::string reset = "\033[0m";

        for (const auto& [name, tc] : tests) {
            try {
                tc();
                std::cout << green << "[PASS] " << reset << name << std::endl;
                ++passed;
            } catch (const std::exception &e) { 
                std::cout << red << "[FAIL] " << reset << name << ": " << e.what() << std::endl;
            }
        }
        std::cout << "\n" << passed << " out of " << tests.size() << " tests passed" << std::endl;
    }

    /**
     * @brief Asserts that two values are equal
     * @param a First value to compare
     * @param b Second value to compare
     * @param msg Optional custom error message
     * @throws std::runtime_error if values are not equal
     */
    static void assert_eq(const T& a, const T& b, const std::string& msg = "") {
        if (a != b) throw std::runtime_error(msg.empty() ? "assert_eq failed" : msg);
    }

    /**
     * @brief Asserts that a condition is true
     * @param cond The condition to verify
     * @param msg Optional custom error message
     * @throws std::runtime_error if condition is false
     */
    static void assert_true(bool cond, const std::string& msg = "") {
        if (!cond) throw std::runtime_error(msg.empty() ? "assert_true failed" : msg);
    }

private:
    std::vector<std::pair<std::string, test_case>> tests;  // Storage for test cases
};

#endif // TEST_SUITE_HPP
