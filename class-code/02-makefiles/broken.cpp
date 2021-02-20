#include <iostream>

int main(int argc, char *argv[]) {
    int *nums = new int[1024];

    for (int i = 0; i < 103000; i++) { 
        nums[i] = i;
    }
}
