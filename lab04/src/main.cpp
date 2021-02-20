#include <iostream>
#include <time.h>
#include <fstream>
#include "sums.h"

long problem1(int n);
long problem2(int n);
long problem3(int n);
long problem4(int n);
long problem5(int n);

int main(int argc, char *argv[]) {

    clock_t start, diff;
    double timeAmount;

    std::ofstream /*p1FileOut, p2FileOut, p3FileOut, p4FileOut, */p5FileOut;
    // p1FileOut.open ("problem1/problem1.txt");
    // p2FileOut.open ("problem2/problem2.txt");
    // p3FileOut.open ("problem3/problem3.txt");
    // p4FileOut.open ("problem4/problem4.txt");
    p5FileOut.open ("problem5/problem5.txt");

    // for (int i = 100000; i < 1000000000; i += 100000){
    //     start = clock();
    //     problem1(i);
    //     diff = clock() - start;
    //     timeAmount = diff * 1.0 / CLOCKS_PER_SEC;
    //     p1FileOut << i << " " << timeAmount << "\n";
    //     p1FileOut << std::flush;
    // }

    // for (int i = 100000; i < 1000000000; i += 1000000){
    //     start = clock();
    //     problem2(i);
    //     diff = clock() - start;
    //     timeAmount = diff * 1.0 / CLOCKS_PER_SEC;
    //     p2FileOut << i << " " << timeAmount << "\n";
    //     p2FileOut << std::flush;
    // }

    // for (int i = 100; i < 1000000000; i += 100){
    //     start = clock();
    //     problem3(i);
    //     diff = clock() - start;
    //     timeAmount = diff * 1.0 / CLOCKS_PER_SEC;
    //     p3FileOut << i << " " << timeAmount << "\n";
    //     p3FileOut << std::flush;
    // }

    // for (int i = 100000; i < 1000000000; i += 1000){
    //     start = clock();
    //     problem4(i);
    //     diff = clock() - start;
    //     timeAmount = diff * 1.0 / CLOCKS_PER_SEC;
    //     p4FileOut << i << " " << timeAmount << "\n";
    //     p4FileOut << std::flush;
    // }

    for (int i = 100000; i < 1000000000; i += 100000){
        start = clock();
        problem5(i);
        diff = clock() - start;
        timeAmount = diff * 1.0 / CLOCKS_PER_SEC;
        p5FileOut << i << " " << timeAmount << "\n";
        p5FileOut << std::flush;
    }

    // p1FileOut.close();
    // p2FileOut.close();
    // p3FileOut.close();
    // p4FileOut.close();
    p5FileOut.close();
    return 0;
}

long problem1(int n) {
    long ret = 0;
    
    for (int i = 0; i < 50; i++) {
        ret += sumOfOneTo(n);
    }

    return ret;
}

long problem2(int n) {
    return sumOfOneToSquaredEnhanced(n);
}

long problem3(int n) {
    long ret = 0;

    ret += sumOfOneToSquared(n);

    for (int i = 0; i < 10; i++) {
        ret += sumOfOneTo(n);
    }

    return ret;
}

long problem4(int n) {
    int ret = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < n; j *= 2) {
            ret += j;
        }
    }

    return ret;
}

long problem5(int n) {
    int ret = 0;

    for (int i = 1; i < n; i *= 2) {
        ret += sumOfOneTo(n);
    }

    return ret;
}
