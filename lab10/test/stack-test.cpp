#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "stack.hpp"
#include "queue.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            Stack<int> st;
            st.push(15);
            TS_ASSERT(st.top() == 15);
        }
        void test2(void) {
            Stack<int> st;
            st.push(110);
            st.push(1);
            st.push(2);
            st.push(25);
            TS_ASSERT(st.top() == 25);
        }
        void test3(void) {
            Stack<int> st;
            st.push(15);
            TS_ASSERT(st.isEmpty() == false);
        }
        void test4(void) {
            Stack<int> st;
            TS_ASSERT(st.isEmpty() == true);
        }
        void test5(void) {
            Stack<int> st;
            st.push(1);
            st.push(3);
            st.push(6);
            st.push(5);
            st.push(10);
            st.pop();
            st.pop();
            st.push(25);
            st.pop();
            TS_ASSERT(st.top() == 6);
        }
        void test6(void) {
            Stack<int> st;
            Stack<int> st2;
            st.push(15);
            st2.push(15);
            TS_ASSERT((st == st2) == true);
        }
        void test7(void) {
            Stack<int> st;
            Stack<int> st2;
            st2.push(15);
            TS_ASSERT((st == st2) == false);
        }
        void test8(void) {
            Stack<int> st;
            Stack<int> st2;
            TS_ASSERT((st == st2) == true);
        }
        void test9(void) {
            Stack<int> st;
            Stack<int> st2;
            st.push(15);
            TS_ASSERT((st == st2) == false);
        }
        void test10(void) {
            Stack<int> st;
            st.push(15);
            st.push(12);
            st.push(23);
            st.push(6);
            st.push(16);
            st.push(57);
            st.push(98);
            st.push(1);
            st.push(2);
            st.pop();
            TS_ASSERT(st.top() == 1);
        }

        void test12(void) {
            Queue<int> st;
            st.push(15);
            TS_ASSERT(st.first() == 15);
        }
        void test13(void) {
            Queue<int> st;
            st.push(110);
            st.push(1);
            st.push(2);
            st.push(25);
            TS_ASSERT(st.first() == 25);
        }
        void test14(void) {
            Queue<int> st;
            st.push(15);
            TS_ASSERT(st.isEmpty() == false);
        }
        void test15(void) {
            Queue<int> st;
            TS_ASSERT(st.isEmpty() == true);
        }
        void test16(void) {
            Queue<int> st;
            st.push(1);
            st.push(3);
            st.push(6);
            st.push(5);
            st.push(10);
            st.pop();
            st.pop();
            st.push(25);
            st.pop();
            TS_ASSERT(st.first() == 6);
        }
        void test17(void) {
            Queue<int> st;
            Queue<int> st2;
            st.push(15);
            st2.push(15);
            TS_ASSERT((st == st2) == true);
        }
        void test18(void) {
            Queue<int> st;
            Queue<int> st2;
            st2.push(15);
            TS_ASSERT((st == st2) == false);
        }
        void test19(void) {
            Queue<int> st;
            Queue<int> st2;
            TS_ASSERT((st == st2) == true);
        }
        void test20(void) {
            Queue<int> st;
            Queue<int> st2;
            st.push(15);
            TS_ASSERT((st == st2) == false);
        }
        void test21(void) {
            Queue<int> st;
            st.push(15);
            st.push(12);
            st.push(23);
            st.push(6);
            st.push(16);
            st.push(57);
            st.push(98);
            st.push(1);
            st.push(2);
            st.pop();
            TS_ASSERT(st.first() == 1);
        }
};

