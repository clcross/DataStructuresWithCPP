#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "array.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            int array[] = {4, 7, 3, 19, 34, 2, 8, 13, 15, 20};
            Array<int> array1(array, 10);
            array1.msort();
            printf("\n");
            for (int i = 0; i < 10; i++) {
                printf("%d ", array1[i]);
            }
            printf("\n");
            TS_ASSERT(array1[0] == 2);
        }
        void test2(void) {
            int array[] = {47, 77, 73, 197, 374, 27, 78, 83, 25, 20};
            Array<int> array1(array, 10);
            array1.msort();
            printf("\n");
            for (int i = 0; i < 10; i++) {
                printf("%d ", array1[i]);
            }
            printf("\n");
            TS_ASSERT(array1[0] == 20);
        }
};

