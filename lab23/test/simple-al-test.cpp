#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "graphal.hpp"

void visit(int node) {
    std::cout << "I'm at :" << node << "\n";
}

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            GraphAL<int> gal(10);
            gal.addEdge(0, 4, 100);
            TS_ASSERT_EQUALS(100, gal.adjacent(0, 4));
            gal.removeEdge(0, 4);
            TS_ASSERT_EQUALS(-1, gal.adjacent(0, 4));
        }
        void test2(void) {
            GraphAL<int> gal(10);
            gal.addEdge(0, 4, 100);
            gal.addEdge(0, 2, 100);
            gal.addEdge(2, 3, 100);
            gal.addEdge(2, 5, 100);
            gal.addEdge(5, 1, 100);
            gal.addEdge(3, 6, 10);
            gal.breadthFirstTraversal(visit);
        }
};
