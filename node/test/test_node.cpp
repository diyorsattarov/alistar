#include <iostream>
#include <node.hpp>
#include <test_suite.hpp>  // Include the test suite

int main() {
    tst_suite<int> suite;

    suite.add("Node value check", []() {
        node<int> n(5);
        tst_suite<int>::assert_eq(n.get(), 5, "Node value should be 5");
    });

    suite.add("Next node linkage", []() {
        node<int> n1(1);
        node<int> n2(2);
        n1.l(&n2);
        tst_suite<int>::assert_true(n1.next() == &n2, "Next node should be n2");
    });

    suite.run();

    return 0;
}

