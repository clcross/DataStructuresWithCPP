#include <iostream>
#include "arrays.hpp"

int main(int argc, char *argv[]) {
    int arr[] = {6, -2, -3, -76, -80, -6};

    std::cout << countNegatives(arr, 6) << "\n";
    std::cout << findMinOdd(arr, 6) << "\n";
    std::cout << search(arr, 6, 9) << "\n";
    for (int i = 0; i < 6; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    if (remove(arr, 6, 3) == true){
        std::cout << "true\n";
        for (int i = 0; i < 6; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    else if (remove(arr, 6, 1) == false){
        std::cout << "false\n";
    }
    else{
        std::cout << "nothing\n";
    }

    return 0;
}
