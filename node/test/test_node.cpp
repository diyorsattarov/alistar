/****************************************************************************
* File: test_node.cpp
* Author: Diyor Sattarov
* Email: diyorsattarov@outlook.com
*
* Created: 2024-10-05
* Last Modified: 2024-10-07
*
* Description: Test implementation for the node<T> class. Contains unit tests
* to verify proper initialization, value storage, and node linking functionality
* of the templated node class using the test suite framework.
****************************************************************************/

#include <node.hpp>
#include <test_suite.hpp>

int main() {
   // Create test suite instance for integer tests
   tst_suite<int> suite;

   /**
    * @brief Tests node value initialization and retrieval
    * Verifies that:
    * 1. Node properly stores the initial value
    * 2. Value can be correctly retrieved using get()
    */
   suite.add("Node value check", []() {
       node<int> n(5);
       tst_suite<int>::assert_eq(n.get(), 5, "Node value should be 5");
   });

   /**
    * @brief Tests node linking functionality
    * Verifies that:
    * 1. Nodes can be properly linked together
    * 2. Next pointer is correctly set and retrieved
    * 3. Node relationships are properly maintained
    */
   suite.add("Next node linkage", []() {
       node<int> n1(1);
       node<int> n2(2);
       n1.l(&n2);
       tst_suite<int>::assert_true(n1.next() == &n2, "Next node should be n2");
   });

   // Execute all registered tests
   suite.run();
   
   return 0;
}
