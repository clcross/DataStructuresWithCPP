#include "graphal.hpp"

int main(int argc, char *argv[]) {
    GraphAL<int> gal(10);
    // gal.fill();
    gal.addEdge(0, 2, 40);
    gal.addEdge(0, 5, 11);
    gal.addEdge(0, 4, 20);
    gal.addEdge(2, 3, 1);
    gal.addEdge(2, 5, 16);
    gal.addEdge(5, 1, 9);
    gal.addEdge(3, 6, 10);
    gal.addEdge(9, 0, 10);
    gal.addVertices(1);
    std::cout << gal.adjacent(9, 0) << "\n";
    gal.print();
}
