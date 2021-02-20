#include <stdlib.h>
#include <iostream>
#include "sllist.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
    SLList<int> sll;
    sll.print();
    sll.append(2);
    sll.print();
    sll.append(3);
    sll.print();
    sll.append(4);
    sll.print();
    sll.append(5);
    sll.print();
    sll.append(6);
    sll.print();
    sll.remove(2);
    sll.print();
    std::cout << sll.getLength() << "\n";
    // sll.insert(9, 32);
    // sll.insert(2, 32);
    // sll.print();
    // std::cout << sll[3] << "\n";
    // DLList<int> newSLL = DLList<int>(sll);
    // std::cout << "new\n";
    // newSLL.print();
    // if (newSLL == sll){
    //     std::cout << "match\n";
    // }
    // else{
    //     std::cout << "not\n";
    // }

    // if (sll == newSLL){
    //     std::cout << "match\n";
    // }
    // else{
    //     std::cout << "not\n";
    // }

    // sll.append(22);
    // newSLL.append(10);
    // if (newSLL == sll){
    //     std::cout << "match\n";
    // }
    // else{
    //     std::cout << "not\n";
    // }

    // if (sll == newSLL){
    //     std::cout << "match\n";
    // }
    // else{
    //     std::cout << "not\n";
    // }
    // sll.print();
    // newSLL.print();
    // sll.~SLList();
    // newSLL.~SLList();

    return 0;
}

