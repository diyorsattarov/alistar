#ifndef LIST_HPP
#define LIST_HPP

#include <stdexcept>
#include <cstddef>
#include <node.hpp>

template <typename T>
class lst {
    public:
        // Constructor
        lst() : hd(nullptr), t1(nullptr), sz(0) {}

        // Destructor to free all nodes
        ~lst() {
            while (hd) {
                node<T>* tmp = hd;
                hd = hd->next();
                delete tmp;
            }
        }

        void add (const T& v) {
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

        T get(size_t idx) const {
            if (idx >= sz) { throw std::out_of_range("Index out of bounds"); }
            node<T>* cur = hd;
            for (size_t i = 0; i < idx && cur; ++i) { cur = cur->next(); }
            return cur ? cur->get() : T();
        }

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

        size_t size() const { return sz; }
    private:
        node<T>* hd;
        node<T>* t1;
        size_t sz;
};

#endif
