#include <stdio.h>
#include "heap.hpp"

int main(int argc, char *argv[]) {
    Heap<int> heap(10);

    heap.insert(20);
    heap.insert(19);
    heap.insert(10);
    heap.insert(-2);
    heap.insert(5);
    heap.insert(8);
    heap.insert(7);

    heap.print();
    std::cout << "height: " << heap.getHeight() << "\n";
    std::cout << "size: " << heap.getSize() << "\n";
    std::cout << "value at 3: " << heap.operator[](3) << "\n";
    std::cout << "has 10 at: " << heap.contains(10) << "\n";
    // std::cout << "front: " << heap.removeFirst() << "\n";
    // std::cout << "newsize: " << heap.getSize() << "\n";
    heap.heapSort();
    // std::cout << "sorted: " << heap.heapSort() << "\n";


    return 0;
}
