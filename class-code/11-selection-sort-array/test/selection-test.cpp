#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "unit.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            int ary[] = {-5, -20, 12, 5, 14, 2, 53, 0};
            selection_sort(ary, 8);
            TS_ASSERT(ary[0] == -20);
            TS_ASSERT(ary[1] == -5);
            TS_ASSERT(ary[2] == 0);
            TS_ASSERT(ary[3] == 2);
            TS_ASSERT(ary[4] == 5);
            TS_ASSERT(ary[5] == 12);
            TS_ASSERT(ary[6] == 14);
            TS_ASSERT(ary[7] == 53);
            /* Fill in some test cases here for cxx test gen */
        }
        void test2(void) {
            int ary[] = {-5, -20, 12, 5, 14, 2, 53, 0};
            selection_sort(NULL, 0);
            /* Fill in some test cases here for cxx test gen */
        }
        void test3(void) {
            int ary[] = {-5, 0};
            selection_sort(ary, 2);
            TS_ASSERT(ary[0] == -5);
            TS_ASSERT(ary[1] == 0);
            /* Fill in some test cases here for cxx test gen */
        }
};

