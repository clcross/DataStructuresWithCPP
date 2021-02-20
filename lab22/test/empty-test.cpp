#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "grapham.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            GraphAM<int> gam(100);
        }
};
