#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "arrays.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            int array[] = {5, 12, 33, 76, 89, -9};
            TS_ASSERT(-9 == findMinOdd(array, 6));
        }
        void test2(void) {
            int array[] = {5, 12, 33, 76, 89, 9};
            TS_ASSERT(5 == findMinOdd(array, 6));
        }
        void test3(void) {
            int array[] = {5, 0, 33, 76, 89, -9};
            TS_ASSERT(-9 == findMinOdd(array, 6));
        }
        void test4(void) {
            int array[] = {5, 0, 33, 76, 89, -9};
            TS_ASSERT(5 == findMinOdd(array, 5));
        }
        void test5(void) {
            int array[] = {};
            TS_ASSERT(-1 == findMinOdd(array, 0));
        }
        void test6(void) {
            int array[] = {-5, -0, -33, -76, -89, -9};
            TS_ASSERT(-89 == findMinOdd(array, 6));
        }
        void test7(void) {
            int array[] = {6, -0, -32, -76, -80, -6};
            TS_ASSERT(-1 == findMinOdd(array, 6));
        }
};

