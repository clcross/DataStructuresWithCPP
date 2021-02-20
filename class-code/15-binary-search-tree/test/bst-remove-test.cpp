#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "binary-search-tree.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            BST bst;
            bst.add(5);
            bst.add(14);
            bst.add(2);
            bst.add(-30);
            bst.add(7);
            bst.add(19);
            bst.add(-3);
            TS_ASSERT(bst.remove(-3) == true);
            bst.print();
        }
        void test2(void) {
            BST bst;
            bst.add(5);
            bst.add(14);
            bst.add(2);
            bst.add(-30);
            bst.add(7);
            bst.add(19);
            bst.add(-3);
            TS_ASSERT(bst.remove(-30) == true);
            bst.print();
        }
        void test3(void) {
            BST bst;
            bst.add(5);
            bst.add(14);
            bst.add(2);
            bst.add(-30);
            bst.add(7);
            bst.add(19);
            bst.add(-3);
            TS_ASSERT(bst.remove(2) == true);
            bst.print();
        }
        void test4(void) {
            BST bst;
            bst.add(5);
            bst.add(14);
            bst.add(2);
            bst.add(-30);
            bst.add(7);
            bst.add(19);
            bst.add(-3);
            TS_ASSERT(bst.remove(14) == true);
            bst.print();
        }
};

