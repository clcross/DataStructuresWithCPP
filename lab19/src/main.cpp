#include <stdio.h>
#include <iostream>
#include "hashtable.hpp"

int main(int argc, char *argv[]) {
    HashTable<int, int> table(3, .75);

    for (int i = 0; i < 3; i++) {
        table.insert((i+3)*3, (i+100));
        std::cout << "inserting: " << (i+3)*3 << "\n";
    }
    table.print();

    table.remove(21);

    std::cout << "removing: " << 21 << "\n";

    table.print();


    // Happy path
    /*
    for (int i = 0; i < 40; i++) {
        table.insert(i, i+100);
    }
    */

    //Sad path 1
    /*
    for (int i = 0; i < 40; i++) {
        table.insert(0, i+100);
    }
    */

    //Sad path 2
    // for (int i = 0; i < 140; i++) {
    //     table.insert(0, i+100);
    // }

    // std::cout << table.percentFull() << "\n";
    return 0;
}
