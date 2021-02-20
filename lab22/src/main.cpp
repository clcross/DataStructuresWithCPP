#include "grapham.hpp"

int main(int argc, char *argv[]) {
    GraphAM<int> gam(10);
    // gam.fill(10);
    gam.print();
    gam.addEdge(0,8,56);
    gam.addEdge(8,5,26);
    gam.print();
    // gam.removeEdge(0,1);
    gam.print();
    std::cout << "vertices amt: " << gam.addVertices(4) << "\n";
    gam.print();

    gam.adjacent(0,1);
    // gam.depthFirstTraversal();
    gam.removeVertex(3);
    gam.print();
    std::cout << "shortest: " << gam.dijkstraShortestPath(0, 8) << "\n";
}
