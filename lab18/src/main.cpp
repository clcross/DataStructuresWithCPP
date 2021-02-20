#include <stdio.h>
#include "hashtable.hpp"

int main(int argc, char *argv[]) {
    HashTable<int, int> table(100);

    table.insert(58, 85);
    table.insert(38, 83);
    table.insert(34, 43);
    table.insert(134, 431);
    table.insert(34, 44);

    table.print();

    if (table.remove(34)) {
        std::cout << "removed\n";
    }
    else {
        std::cout << "not removed\n";
    }
    table.print();
    return 0;
}
