#include "sums.h"

long sumOfOneTo(int n) {
    long sum = 0;
    for (int i = 1; i < n; i++) {
        sum += i;
    }
    return sum;
}

long sumOfOneToSquared(int n) {
    long sum = 0;
    for (int i = 1; i < n; i++) {
        sum += sumOfOneTo(i);
    }
    return sum;
}

long sumOfOneToEnhanced(int n) {
    long sum = n + 1;
    sum *= n;
    sum /= 2;
    return sum;
}

long sumOfOneToSquaredEnhanced(int n) {
    long sum = 0;
    for (int i = 1; i < n; i++) {
        sum += sumOfOneToEnhanced(i);
    }
    return sum;
}
