#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "arrays.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void validate(const int ary1[], const int ary2[], const int size) {
            for (int i = 0; i < size; i++) {
                TS_ASSERT(ary1[i] == ary2[i]);
            }
        }
        void test1(void) {
            int array[] = {5, 12, 33, 76, 89, -9};
            int ans[] = {5, 12, 33, 76, 89};
            TS_ASSERT(true == remove(array, 6, 5));
            validate(array, ans, 5);
        }
        void test2(void) {
            int array[] = {5, 12, 33, 76, 89, 9};
            int ans[]   = {5, 12, 33, 76, 89, 9};
            TS_ASSERT(false == remove(array, 6, -9));
            validate(array, ans, 6);
        }
        void test3(void) {
            int array[] = {5, 0, 33, 76, 89, -9};
            int ans[] =   {0, 33, 76, 89, -9};
            TS_ASSERT(true == remove(array, 6, 0));
            validate(array, ans, 5);
        }
        void test4(void) {
            int array[] = {5, 0, 33, 76, 89, -9};
            int ans[] =   {5, 33, 33, 76, 89, -9};
            TS_ASSERT(true == remove(array, 3, 1));
            validate(array, ans, 2);
        }
        void test5(void) {
            int array[] = {};
            TS_ASSERT(false == remove(array, 0, 0));
        }
        void test6(void) {
            int array[] = {-5, -0, -33, -76, -89, -9};
            int ans[] =   {-5, -0, -33, -76, -89, -9};
            TS_ASSERT(false == remove(array, 6, -89));
            validate(array, ans, 6);
        }
};

