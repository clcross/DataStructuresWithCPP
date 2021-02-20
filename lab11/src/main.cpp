#include <stdlib.h>
#include <iostream>
#include "queue.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Queue<int> que;
    // que.push(4);
    // std::cout << que.first() << "\n";
    // que.push(3);
    // std::cout << que.first() << "\n";
    // que.pop();
    // std::cout << que.first() << "\n";
    // que.push(5);
    // que.push(7);
    // que.push(8);
    // que.push(9);
    // que.push(10);
    // que.print();
    // que.addWithPriority(0);
    que.addWithPriority(10);
    que.print();
    // std::cout << que.getShortestPathWithWarps() << "\n";
    /* You may write manual tests here. */
}

