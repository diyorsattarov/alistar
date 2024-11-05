#include <iostream>

template <typename T>
class node {
public:
    T v;        //; Value of the n
    node* nxt;     //; Pointer to nxt n

    // Constructor to initialize the node with a value
    node(const T& val) : v(val), nxt(nullptr) {}

    // Destructor
    node() = default;
    
    // Method to set the nxt
    void l(node* node) { nxt = node; } 

   // Method to retrieve T v;
   T get() const { return v; }

   // Method to retrieve the nxt node
   node* next() const { return nxt; }
};
