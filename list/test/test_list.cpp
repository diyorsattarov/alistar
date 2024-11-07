/****************************************************************************
 * File: test_list.cpp
 * Author: Diyor Sattarov
 * Email: diyorsattarov@outlook.com
 *
 * Created: 2024-10-05
 * Last Modified: 2024-10-07
 *
 * Description: Test implementation for the lst<T> class. Implements various
 * test cases to verify the functionality of the linked list implementation
 * including addition, removal, and access operations.
 ****************************************************************************/
#include <list.hpp>
#include <test_suite.hpp>

/**
 * @brief Tests basic addition and retrieval operations
 */
void test_add_and_get() {
    lst<int> test_lst;
    test_lst.add(1);
    test_lst.add(2);
    test_lst.add(3);
    
    tst_suite<int>::assert_eq(test_lst.get(0), 1, "First element should be 1");
    tst_suite<int>::assert_eq(test_lst.get(1), 2, "Second element should be 2");
    tst_suite<int>::assert_eq(test_lst.get(2), 3, "Third element should be 3");
}

/**
 * @brief Tests the size tracking of the list
 */
void test_size() {
    lst<int> test_lst;
    tst_suite<int>::assert_eq(test_lst.size(), 0, "Empty list should have size 0");
    
    test_lst.add(1);
    tst_suite<int>::assert_eq(test_lst.size(), 1, "Size should be 1 after adding one element");
    
    test_lst.add(2);
    tst_suite<int>::assert_eq(test_lst.size(), 2, "Size should be 2 after adding second element");
}

/**
 * @brief Tests the removal functionality
 */
void test_removal() {
    lst<int> test_lst;
    test_lst.add(1);
    test_lst.add(2);
    test_lst.add(3);
    
    test_lst.rem();
    tst_suite<int>::assert_eq(test_lst.size(), 2, "Size should be 2 after removal");
    tst_suite<int>::assert_eq(test_lst.get(0), 1, "First element should still be 1");
    tst_suite<int>::assert_eq(test_lst.get(1), 2, "Second element should be 2");
}

/**
 * @brief Tests exception handling for out-of-bounds access
 */
void test_out_of_bounds() {
    lst<int> test_lst;
    test_lst.add(1);
    
    try {
        test_lst.get(1);
        throw std::runtime_error("Should have thrown out_of_range exception");
    } catch (const std::out_of_range&) {
        // Expected behavior
    }
}

int main() {
    // Create and configure test suite
    tst_suite<int> suite;
    
    // Add test cases
    suite.add("Add and Get Operations", test_add_and_get);
    suite.add("Size Tracking", test_size);
    suite.add("Remove Operations", test_removal);
    suite.add("Out of Bounds Handling", test_out_of_bounds);
    
    // Run all tests
    suite.run();
    
    return 0;
}
