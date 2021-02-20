#include <iostream>
#include "sll.hpp"

int main(int argc, char *argv[]) {
    /*
    SLLNode node(17, NULL);
    std::cout << node.get_val() << "\n";
    SLLNode node2(20, NULL);
    node.set_next(&node2);
    std::cout << node.get_next()->get_val() << "\n";
    */
    SLL sll;
    sll.push_front(17);
    sll.print();
    sll.push_front(19);
    sll.print();
    sll.push_back(20);
    sll.print();
    sll.push_back(13);
    sll.print();
    sll.push_back(75);
    sll.print();
    sll.remove(17);
    sll.print();
    return 0;
}
