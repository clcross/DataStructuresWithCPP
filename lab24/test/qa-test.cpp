#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "quadtree.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            QuadTree qt(1000.0, 1000.0);
            qt.add(100, 100);
            qt.print();
            TS_ASSERT_EQUALS(true, qt.contains(100, 100));
        }
        void test2(void) {
            QuadTree qt(1000.0, 1000.0);
            qt.add(100, 100);
            qt.add(700, 100);
            qt.print();
            TS_ASSERT_EQUALS(true, qt.contains(100, 100));
            TS_ASSERT_EQUALS(true, qt.contains(700, 100));
        }
        void test3(void) {
            QuadTree qt(1000.0, 1000.0);
            qt.add(100, 100);
            qt.add(700, 100);
            qt.add(400, 400);
            qt.print();
            TS_ASSERT_EQUALS(true, qt.contains(100, 100));
            TS_ASSERT_EQUALS(true, qt.contains(700, 100));
            TS_ASSERT_EQUALS(true, qt.contains(400, 400));
        }
};
