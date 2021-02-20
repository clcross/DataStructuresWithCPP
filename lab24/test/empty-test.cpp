#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "quadtree.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            QuadTree qt(1000.0, 1000.0);
            TS_ASSERT_EQUALS(false, qt.contains(100, 100));
            qt.add(100, 100);
            TS_ASSERT_EQUALS(true, qt.contains(100, 100));
        }
};
