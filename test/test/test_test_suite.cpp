/****************************************************************************
* File: test_suite_demo.cpp
* Author: Diyor Sattarov
* Email: diyorsattarov@outlook.com
*
* Created: 2024-10-05
* Last Modified: 2024-10-07
*
* Description: Demonstration of the test suite framework functionality.
* Shows basic usage of assertions and test case creation using lambda
* functions. Includes examples of both passing and failing tests to
* demonstrate the test reporting system.
****************************************************************************/

#include <test_suite.hpp>

int main() {
   // Create a test suite instance for integer testing
   tst_suite<int> suite;

   /**
    * Test Case 1: Equality Testing
    * Uses: Lambda function syntax []() { ... }
    * Tests: assert_eq() functionality with equal values
    * Expected: PASS
    */
   suite.add("Test equality", []() {
       tst_suite<int>::assert_eq(5, 5, "5 should be equal to 5");
   });

   /**
    * Test Case 2: Boolean Condition Testing
    * Uses: Lambda function with assert_true
    * Tests: Basic boolean comparison
    * Expected: PASS
    */
   suite.add("Test truthiness", []() {
       tst_suite<int>::assert_true(3 < 4, "3 is less than 4");
   });

   /**
    * Test Case 3: Deliberate Failure Demonstration
    * Uses: assert_eq with unequal values
    * Tests: Error reporting functionality
    * Expected: FAIL (intentionally)
    */
   suite.add("Test inequality", []() {
       tst_suite<int>::assert_eq(2, 3, "2 should not be equal to 3"); // This will fail
   });

   // Execute all registered tests and display results
   suite.run();
   
   return 0;
}
