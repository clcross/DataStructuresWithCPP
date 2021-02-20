#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
    int nums[] = {3, 40, 20, -3, 15, 104, 76, 11, 81, 9};
    std::vector<int> vec(nums, nums+10);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "\n";

    make_heap(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "\n";

    vec.push_back(60);
    push_heap(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "\n";

    pop_heap(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "\n";

    return 0;
}
