#include <iostream>

int main(int argc, char *argv[]) {
    int *nums = new int[1024];

    for (int i = 0; i < 1024; i++) { 
        nums[i] = i;
    }

    delete [] nums;
}
