#include <iostream>
#include "array.hpp"

template <class T>
T add (T a, T b);

int main(int argc, char *argv[]) {
    Array<char> ary(5);
    Array<float> fary(5);
    ary.set(2, 'O');
    fary.set(1, 3.14159);
    std::cout << ary.get(2) << "\n";
    std::cout << fary.get(1) << "\n";

    std::cout << add(1, 2) << "\n";
    std::cout << add(1.5, 2.6) << "\n";
    return 0;
}

template <class T>
T add (T a, T b) {
    return a + b;
}
