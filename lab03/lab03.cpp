#include <iostream>

int main () {
    // int x = 7, arr[5] = {0, 10, 20, 30, 40};
    // // #1
    // int *p1 = &x;
    // std::cout << p1 << "\n";
    // // #2
    // *p1 = 63;
    // std::cout << x << "\n";
    // // #3
    // int *p2 = &arr[0];
    // std::cout << p2 << "\n";
    // std::cout << &arr[0] << "\n";
    // // #4
    // *p2 = 5;
    // std::cout << arr[0] << "\n";
    // // #5
    // 1[p2] = 15;
    // std::cout << arr[1] << "\n";
    // // #6
    // *(p2 + 3) = 35;
    // std::cout << arr[3] << "\n";
    // // #7###########################
    // p2 = &1[p2];
    // std::cout << p2 << "\n";
    // std::cout << &arr[1] << "\n";
    // // #8
    // *p2 = 77;
    // std::cout << *p2 << "\n";
    // // #9
    // // if(*p1 == *p2){return true;}
    // // #10
    // // if(p1 == p2){return true;}
    // // #11
    // std::cout << "start" << "\n";
    // p1 = new int;
    // std::cout << *p1 << "\n";
    // std::cout << p1 << "\n";
    // // #12
    // delete [] p1;
    // std::cout << *p1 << "\n";
    // std::cout << p1 << "\n";
    // // #13
    // p1 = new int[x];
    // std::cout << *p1 << "\n";
    // std::cout << p1 << "\n";
    // // #14
    // delete [] p1;
    // std::cout << *p1 << "\n";
    // std::cout << p1 << "\n";
    // // #15
    // // #16

    int *p;
    *p=5;
    std::cout << *p << "\n";
    std::cout << p << "\n";
    p=new int();
    *p=7;
    std::cout << *p << "\n";
    std::cout << p << "\n";
    delete [] p;
    p=new int();
    *p=9;
    std::cout << *p << "\n";
    std::cout << p << "\n";
    *p=15;
    std::cout << *p << "\n";
    std::cout << p << "\n";
    delete p;


    return 0;
}