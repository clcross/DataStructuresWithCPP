#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "stack.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            Stack stack;
            stack.push(4);
            TS_ASSERT(stack.peek() == 4);
        }
        void test2(void) {
            Stack stack;
            stack.push(4);
            stack.push(8);
            TS_ASSERT(stack.peek() == 8);
        }
        void test3(void) {
            Stack stack;
            stack.push(4);
            stack.push(8);
            stack.pop();
            TS_ASSERT(stack.peek() == 4);
        }
        void test4(void) {
            Stack stack;
            for (int i = 0; i < 1024; i++) {
                stack.push(i);
                TS_ASSERT(stack.peek() == i);
            }
            stack.push(4);
            stack.push(8);
            stack.pop();
            TS_ASSERT(stack.peek() == 4);
            stack.print();
        }
        void test5(void) {
            Stack stack;
            stack.push(4);
            stack.push(8);
            TS_ASSERT(stack.size() == 2);
        }
};

