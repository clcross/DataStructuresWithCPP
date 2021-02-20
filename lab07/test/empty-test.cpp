#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "array.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            TS_ASSERT(1 + 1 > 1);
            /* Fill in some test cases here for cxx test gen */
        }
};

