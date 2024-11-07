/****************************************************************************
* File: list.hpp
* Author: Diyor Sattarov
* Email: diyorsattarov@outlook.com
*
* Created: 2024-10-05
* Last Modified: 2024-10-07
*
* Description: This header file implements a templated singly linked list 
* data structure. The list maintains head and tail pointers for efficient
* operations and provides basic functionality including addition, removal,
* and element access. The list dynamically allocates nodes as needed and
* properly manages memory cleanup.
*
* Copyright (c) 2024 diyorsattarov. All rights reserved.
****************************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include <stdexcept>
#include <cstddef>
#include <node.hpp>

template <typename T>
class lst {
public:
   /**
    * @brief Constructs an empty list
    * @post Creates a list with no elements, null head/tail pointers, and size 0
    */
   lst() : hd(nullptr), t1(nullptr), sz(0) {}

   /**
    * @brief Destructor that cleans up all allocated nodes
    * @post All nodes are deleted and memory is freed
    */
   ~lst() {
       while (hd) {
           node<T>* tmp = hd;
           hd = hd->next();
           delete tmp;
       }
   }

   /**
    * @brief Adds a new element to the end of the list
    * @param v The value to add to the list
    * @post A new node containing v is added to the end of the list
    *       Size is incremented by 1
    */
   void add(const T& v) {
       node<T>* new_node = new node<T>(v);
       if (!hd) {
           hd = new_node;
           t1 = new_node;
       } else {
           t1->l(new_node);
           t1 = new_node;
       }
       ++sz;
   }

   /**
    * @brief Retrieves the element at the specified index
    * @param idx The zero-based index of the element to retrieve
    * @return The value at the specified index
    * @throws std::out_of_range if idx is >= size
    */
   T get(size_t idx) const {
       if (idx >= sz) { throw std::out_of_range("Index out of bounds"); }
       node<T>* cur = hd;
       for (size_t i = 0; i < idx && cur; ++i) { cur = cur->next(); }
       return cur ? cur->get() : T();
   }

   /**
    * @brief Removes the last element from the list
    * @post The last element is removed if the list is not empty
    *       Size is decremented by 1 if an element was removed
    */
   void rem() {
       if (!hd) return;
       if (hd == t1) {
           delete hd;
           hd = nullptr;
           t1 = nullptr;
       } else {
           node<T>* cur = hd;
           while (cur->next() != t1) { cur = cur->next(); }
           delete t1;
           t1 = cur;
           t1->l(nullptr);
       }
       --sz;
   }

   /**
    * @brief Returns the current number of elements in the list
    * @return The size of the list
    */
   size_t size() const { return sz; }

private:
   node<T>* hd;    // Pointer to the first node in the list
   node<T>* t1;    // Pointer to the last node in the list
   size_t sz;      // Number of elements in the list
};

#endif // LIST_HPP
