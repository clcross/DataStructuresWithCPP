#include <iostream>

void set2x(int *num, int val) {
    *num = 2 * val;
    val = 2 * val;
}

int main(int argc, char *argv[]) {
    int a = 4;
    int b = 25;
    int ary[3] = { 55, 78, 99};
    int *i = new int;
    *i = 5;
    //std::cout << "i = " << i << "\n";
    //std::cout << "*i = " << *i << "\n";

    delete i;

    i = new int[b];
    delete[] i;
    //i = NULL;
    //std::cout << "i = " << i << "\n";
    //std::cout << "*i = " << *i << "\n"; // SHOULD FAIL!!!

    i = &a;
    //std::cout << "i = " << i << "\n";
    //std::cout << "*i = " << *i << "\n";
    *i = 20;
    //std::cout << "a = " << a << "\n";

    set2x(&a, b);
    //std::cout << "a = " << a << "\n";
    //std::cout << "b = " << b << "\n";

    std::cout << "ary[0] = " << ary[0] << "\n";
    std::cout << "ary = " << ary << "\n";
    std::cout << "*ary = " << *ary << "\n";
    std::cout << "ary + 1 = " << ary + 1 << "\n";
    std::cout << "*(ary + 1) = " << *(ary + 1) << "\n";
    std::cout << "ary[1] = " << ary[1] << "\n";
    int *p2 = ary; // p2 is a pointer and holds the memory address of ary
    p2 += 1; // goes to the next pointer (AKA p2 now points to the next element of ary.)
    std::cout << "*p2 = " << *p2 << "\n";
    return 0;
}
