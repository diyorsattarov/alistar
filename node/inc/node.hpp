/****************************************************************************
 * File: node.h
 * Author: Diyor Sattarov
 * Email: diyorsattarov@outlook.com
 *
 * Created: 2024-10-05
 * Last Modified: 2024-10-07
 *
 * Description: This header file defines a templated node class for linked data 
 * structures. Each node contains a value of generic type T and a pointer to 
 * the next node, forming the basic building block for linked list 
 * implementations.
 *
 * Copyright (c) 2024 diyorsattarov. All rights reserved.
 ****************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class node {
public:
    T v;             // Value stored in the node
    node* nxt;       // Pointer to the next node in the sequence

    /**
     * @brief Constructs a new node with the given value
     * @param val The value to store in the node
     * @post The node is initialized with the given value and a null next pointer
     */
    node(const T& val) : v(val), nxt(nullptr) {}

    /**
     * @brief Default constructor for the node
     */
    node() = default;
    
    /**
     * @brief Links this node to another node
     * @param node Pointer to the node that should follow this one
     * @post The next pointer is set to the provided node
     */
    void l(node* node) { nxt = node; }

    /**
     * @brief Retrieves the value stored in this node
     * @return The value of type T stored in the node
     */
    T get() const { return v; }

    /**
     * @brief Retrieves the pointer to the next node
     * @return Pointer to the next node in the sequence
     */
    node* next() const { return nxt; }
};

#endif // NODE_HPP
