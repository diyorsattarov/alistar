#include <test_suite.hpp>

int main() {
    tst_suite<int> suite;

    // Add test cases
    suite.add("Test equality", []() {
        tst_suite<int>::assert_eq(5, 5, "5 should be equal to 5");
    });

    suite.add("Test truthiness", []() {
        tst_suite<int>::assert_true(3 < 4, "3 is less than 4");
    });

    suite.add("Test inequality", []() {
        tst_suite<int>::assert_eq(2, 3, "2 should not be equal to 3"); // This will fail
    });

    // Run the tests
    suite.run();

    return 0;
}

