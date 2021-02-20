#include <iostream>
void selection_sort(int *ary, const int size) {
    // Look for the lowest in the remaining list and swap for the lowest index
    int minIndex;
    int temp;
    for (int i = 0; i < size; i++) {
        minIndex = i;
        for (int j = i; j < size; j++){
            if(ary[j] < ary[minIndex]) {
                minIndex = j;
            }
        }
        // minIndex = the index with the smallest number.
        // swap with the smallest
        //ary[0] = temp;
        temp = ary[i];
        ary[i] = ary[minIndex];
        ary[minIndex] = temp;
        //for (int j = 0; j < size; j++) {
            //std::cout << ary[j] << ", ";
        //}
        //std::cout << "\n";
    }
}
