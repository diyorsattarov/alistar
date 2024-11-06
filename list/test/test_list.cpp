#include <iostream>
#include <list.hpp>

int main() {
    lst<int> my_lst;
    my_lst.add(1);
    my_lst.add(2);
    my_lst.add(3);
    std::cout << "List contents: ";
    for (size_t i = 0; i < my_lst.size(); ++i) { std::cout << my_lst.get(i) << " "; }
    std::cout << std::endl;

    my_lst.rem();
    my_lst.rem();
    std::cout << "After removal, list contents: ";
    for (size_t i = 0; i < my_lst.size(); ++i) { std::cout << my_lst.get(i) << " "; }
    std::cout << std::endl;
    std::cout << my_lst.get(my_lst.size()+1) << std::endl;
    return 0;
}
