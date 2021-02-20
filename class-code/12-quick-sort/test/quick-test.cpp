#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "unit.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            int ary[] = {13, 7, 15, 2, 9, 0, -4, 8, 19, -21, 11, 10};
            quick_sort(ary, 12);
            TS_ASSERT(ary[0] == -21);
            TS_ASSERT(ary[1] == -4);
            TS_ASSERT(ary[2] == 0);
            TS_ASSERT(ary[3] == 2);
            TS_ASSERT(ary[4] == 7);
            TS_ASSERT(ary[5] == 8);
            TS_ASSERT(ary[6] == 9);
            TS_ASSERT(ary[7] == 10);
            TS_ASSERT(ary[8] == 11);
            TS_ASSERT(ary[9] == 13);
            TS_ASSERT(ary[10] == 15);
            TS_ASSERT(ary[11] == 19);
            for (int i = 0; i < 12; i++) {
                std::cout << ary[i] << ", ";
            }
            std::cout << "\n";
        }
};

