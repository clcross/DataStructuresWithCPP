#include <iostream>

int main(int argc, char *argv[]) {
    int b = 300;
    int *a = &b;
    double *d = (double*)a;
    *d = 3.14159;
    std::cout << "b = " << b << "\n";
    std::cout << "a = " << a << "\n";
    std::cout << "d = " << d << "\n";
    return 0;
}
