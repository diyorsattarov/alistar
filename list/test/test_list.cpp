#include <iostream>
#include <list.hpp>

int main() {
    lst<int> my_lst;
    my_lst.add(1);
    my_lst.add(2);
    my_lst.add(3);
    std::cout << "helloworld: " << my_lst.get(1) << std::endl;
    return 0;
}
