#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "priorityqueue.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            PriorityQueue<int> pq();
        }
};
