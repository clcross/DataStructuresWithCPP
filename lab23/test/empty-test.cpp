#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "graphal.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            GraphAL<int> gal(100);
        }
};
