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
 * @brief Tests copy constructor functionality
 */
void test_copy_constructor() {
    lst<int> original;
    original.add(1);
    original.add(2);
    original.add(3);

    // Test copy constructor
    lst<int> copied(original);

    // Verify sizes are equal
    tst_suite<int>::assert_eq(copied.size(), original.size(), 
            "Copied list should have same size as original");

    // Verify all elements are copied
    for(size_t i = 0; i < original.size(); i++) {
        tst_suite<int>::assert_eq(copied.get(i), original.get(i), 
                "Copied elements should match original");
    }

    // Verify deep copy by modifying original
    original.rem();
    tst_suite<int>::assert_eq(copied.size(), 3, 
            "Copied list should remain unchanged when original is modified");
    tst_suite<int>::assert_eq(copied.get(2), 3, 
            "Last element of copy should still be 3");
}

/**
 * @brief Tests move constructor functionality
 */
void test_move_constructor() {
    lst<int> original;
    original.add(1);
    original.add(2);
    original.add(3);

    // Store original size for later comparison
    size_t original_size = original.size();

    // Test move constructor
    lst<int> moved(std::move(original));

    // Verify moved list has correct size and elements
    tst_suite<int>::assert_eq(moved.size(), original_size, 
            "Moved list should have original size");
    tst_suite<int>::assert_eq(moved.get(0), 1, "First element should be 1");
    tst_suite<int>::assert_eq(moved.get(2), 3, "Last element should be 3");

    // Verify original list is empty
    tst_suite<int>::assert_eq(original.size(), 0, 
            "Original list should be empty after move");
}

/**
 * @brief Tests copy assignment operator
 */
void test_copy_assignment() {
    lst<int> original;
    original.add(1);
    original.add(2);

    lst<int> assigned;
    assigned.add(5);  // Add something to ensure it's properly cleared

    // Test copy assignment
    assigned = original;

    // Verify sizes are equal
    tst_suite<int>::assert_eq(assigned.size(), original.size(), 
            "Assigned list should have same size as original");

    // Verify all elements are copied
    tst_suite<int>::assert_eq(assigned.get(0), 1, "First element should be 1");
    tst_suite<int>::assert_eq(assigned.get(1), 2, "Second element should be 2");

    // Verify deep copy
    original.add(3);
    tst_suite<int>::assert_eq(assigned.size(), 2, 
            "Assigned list should remain unchanged when original is modified");
}

/**
 * @brief Tests move assignment operator
 */
void test_move_assignment() {
    lst<int> original;
    original.add(1);
    original.add(2);

    lst<int> assigned;
    assigned.add(5);  // Add something to ensure it's properly cleared

    // Store original size
    size_t original_size = original.size();

    // Test move assignment
    assigned = std::move(original);

    // Verify assigned list has correct elements
    tst_suite<int>::assert_eq(assigned.size(), original_size, 
            "Assigned list should have original size");
    tst_suite<int>::assert_eq(assigned.get(0), 1, "First element should be 1");
    tst_suite<int>::assert_eq(assigned.get(1), 2, "Second element should be 2");

    // Verify original list is empty
    tst_suite<int>::assert_eq(original.size(), 0, 
            "Original list should be empty after move");
}

/**
 * @brief Tests self-assignment handling
 */
void test_self_assignment() {
    lst<int> list;
    list.add(1);
    list.add(2);

    // Test self copy-assignment
    list = list;

    // Verify list remains unchanged
    tst_suite<int>::assert_eq(list.size(), 2, 
            "Size should remain unchanged after self-assignment");
    tst_suite<int>::assert_eq(list.get(0), 1, "First element should still be 1");
    tst_suite<int>::assert_eq(list.get(1), 2, "Second element should still be 2");
}

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
    // New test cases for constructors and operators
    suite.add("Copy Constructor", test_copy_constructor);
    suite.add("Move Constructor", test_move_constructor);
    suite.add("Copy Assignment", test_copy_assignment);
    suite.add("Move Assignment", test_move_assignment);
    suite.add("Self Assignment", test_self_assignment);   
    // Run all tests
    suite.run();

    return 0;
}
