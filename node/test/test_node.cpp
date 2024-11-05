#include <iostream>
#include <node.hpp>

int main(int argc, char** argv) {
    node<int> a(1);
    node<int> b(2);
    node<int> c(3);

    a.l(&b);
    b.l(&c);

    node<int>* cur = &a;

    while (cur != nullptr) {
        std::cout << cur->get() << " ";
        cur = cur->next();
    }
    return 0;
}
