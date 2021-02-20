#include <iostream>

// Returns the index of key in the ary.
// Resturns -1 if not found.
int bsearch(const int *ary, const int size, const int key) {
    //Base case
    if (ary == NULL || size < 1) {
        return -1;
    }
    int even_offset = (size+1) % 2;
    int mid_position = size/2;

    if(ary[mid_position] == key){
        return mid_position;
    }

    if(ary[mid_position] > key){
        return bsearch(ary, mid_position, key);
    }

    return mid_position + 1 
        + bsearch(ary +(mid_position + 1), mid_position - even_offset, key);
}

int bubble_sort(int *ary, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if ( ary[j] > ary[j+1]) {
                int temp = ary[j];
                ary[j] = ary[j+1];
                ary[j+1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {

    int ary[] = {-42,-32,-3,0,1,5,27,42,84};
    int size = 8;
    std::cout << bsearch(ary, size, 5) << "\n";
    int to_sort[] = {47, -23, 0, 46, 153, 27, -34, 671};
    bubble_sort(to_sort, 8);
    for (int i = 0; i < 8; i++) {
        std::cout << to_sort[i] << ", ";
    }
    std::cout << "\n";
    return 0;
}
