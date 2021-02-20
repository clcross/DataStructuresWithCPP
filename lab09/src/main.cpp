#include <stdlib.h>
#include <iostream>
#include "array.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    int ary[] = {0, 1, 2, 3, 4, 5, 6, 7}; 
    Array<int>mArray = Array<int>(ary, 8);
    for (int i = 0; i < mArray.getLength(); i++){
        std::cout << mArray[i] << ", ";
    }
    cout << "\n";
    std::cout << mArray.binarySearch(7) << "\n";

    int unAry[] = {5, 6, 2, 7, 4, 0, 1, 3}; 
    Array<int>unArray = Array<int>(unAry, 8);
    std::cout << "unsorted\n";
    for (int i = 0; i < unArray.getLength(); i++){
        std::cout << unArray[i] << ", ";
    }
    cout << "\n";

    std::cout << "sorted\n";
    unArray.bubbleSort();
    for (int i = 0; i < unArray.getLength(); i++){
        std::cout << unArray[i] << ", ";
    }
    cout << "\n";
    // std::cout << mArray[3] << "\n";
}

