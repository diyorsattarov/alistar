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
         * @brief Copy constructor - creates a deep copy of another list
         * @param other The list to copy from
         * @post Creates a new list with identical contents but separate memory
         */
        lst(const lst& other) : hd(nullptr), t1(nullptr), sz(0) {
            // Copy each node from the other list
            node<T>* current = other.hd;
            while (current != nullptr) {
                add(current->get());
                current = current->next();
            }
        }

        /**
         * @brief Move constructor - transfers ownership of another lists's resources
         * @param other The list to move from
         * @post Takes ownership of other list's nodes, leaving other list empty
         */
        lst(lst&& other) noexcept : hd(other.hd), t1(other.t1), sz(other.sz) {
            // Clear the other list's pointers and size
            other.hd = nullptr;
            other.t1 = nullptr;
            other.sz = 0;
        }

        /**
         * @brief Copy assignment operator
         * @param other The list to copy from
         * @return Reference to this list
         */
        lst& operator=(const lst& other) {
            if (this != &other) {  // Prevent self-assignment
                                   // Clear existing list
                while (hd) {
                    node<T>* tmp = hd;
                    hd = hd->next();
                    delete tmp;
                }

                // Reset member variables
                hd = nullptr;
                t1 = nullptr;
                sz = 0;

                // Copy from other list
                node<T>* current = other.hd;
                while (current != nullptr) {
                    add(current->get());
                    current = current->next();
                }
            }
            return *this;
        }

        /**
         * @brief Move assignment operator
         * @param other The list to move from
         * @return Reference to this list
         */
        lst& operator=(lst&& other) noexcept {
            if (this != &other) {  // Prevent self-assignment
                                   // Clear existing list
                while (hd) {
                    node<T>* tmp = hd;
                    hd = hd->next();
                    delete tmp;
                }

                // Take ownership of other's resources
                hd = other.hd;
                t1 = other.t1;
                sz = other.sz;

                // Clear other list
                other.hd = nullptr;
                other.t1 = nullptr;
                other.sz = 0;
            }
            return *this;
        }

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
