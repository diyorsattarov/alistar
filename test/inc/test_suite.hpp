#ifndef TEST_SUITE_HPP
#define TEST_SUITE_HPP

#include <iostream>
#include <functional>
#include <vector>
#include <string>

template <typename T>
class tst_suite {
    public:
        using test_case = std::function<void()>;

        void add(const std::string& name, test_case tc) {
            tests.push_back({name, tc});
        }

        void run() const {
            size_t passed = 0;
            for (const auto& [name, tc] : tests) {
                try {
                    tc();
                    std::cout << "[PASS] " << name << std::endl;
                } catch (const std::exception &e) { 
                    std::cout << "[FAIL] " << name << ": " << e.what() << std::endl;
                }
            }
            std::cout << "\n" << passed << " out of " << tests.size() << " tests passed" << std::endl;
        }
        static void assert_eq(const T& a, const T& b, const std::string& msg = "") {
            if (a != b) throw std::runtime_error(msg.empty() ? "assert_eq failed" : msg);
        }

        static void assert_true(bool cond, const std::string& msg = "") {
            if (!cond) throw std::runtime_error(msg.empty() ? "assert_true failed" : msg);
        }
    private:
        std::vector<std::pair<std::string, test_case>> tests;
};

#endif