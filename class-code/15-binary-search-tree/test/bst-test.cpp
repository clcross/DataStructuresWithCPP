#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "binary-search-tree.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            BSTNode root(5, NULL, NULL);
            TS_ASSERT(root.get_val() == 5);
            TS_ASSERT(root.get_left() == NULL);
            TS_ASSERT(root.get_right() == NULL);
        }
        void test2(void) {
            BSTNode root(5, NULL, NULL);
            BSTNode left(2, NULL, NULL);
            BSTNode right(14, NULL, NULL);
            root.set_left(&left);
            root.set_right(&right);
            TS_ASSERT(root.get_val() == 5);
            TS_ASSERT(root.get_left() == &left);
            TS_ASSERT(root.get_right() == &right);
            TS_ASSERT(root.get_left()->get_val() == 2);
            TS_ASSERT(root.get_right()->get_val() == 14);
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
            bst.print();
        }
};

