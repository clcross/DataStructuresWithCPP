#include <iostream>

void quick_sort(int *ary, const int size) {
    int pivot = ary[0];
    int small_index = 0;
    if (size < 2) { return; }

    for (int i = 1; i < size; i++) {
        if (ary[i] < pivot) {
            int temp = ary[small_index + 1];
            ary[small_index + 1] = ary[i];
            ary[i] = temp;
            small_index++;
        }
    }

    ary[0] = ary[small_index];
    ary[small_index] = pivot;

    /*
    std::cout << "pivot = " << pivot << "\n";
    for (int i = 0; i < size; i++) {
        std::cout << ary[i] << ",";
    }
    std::cout << "\n";
    */
    quick_sort(ary, small_index);
    if (small_index == 0) {
        quick_sort(ary + 1, size - 1);
    } else {
        quick_sort(ary + small_index, size - small_index);
    }
}
