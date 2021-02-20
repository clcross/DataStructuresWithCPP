#include "quadtree.hpp"
#include <iostream>


int main(int argc, char *argv[]) {
    QuadTree qt(1000.0, 1000.0);

    qt.add(100.0, 100.0);
    qt.add(110.0, 100.0);
    qt.add(100.0, 110.0);
    qt.add(105.0, 105.0);
    qt.add(100.0, 105.0);
    qt.print();
    qt.remove(100.0, 105.0);
    qt.print();

    return 0;
}
