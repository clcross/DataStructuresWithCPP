#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "unit.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            std::cout << "test1\n";
            int **ary = new int*[5];
            for (int i = 0; i < 5; i++) {
                ary[i] = new int[5];
                for (int j = 0; j < 5; j++) {
                    ary[i][j] = 0;
                }
            }
            ary[0][2] = 1;
            ary[1][2] = 1;
            ary[2][2] = 1;
            ary[3][2] = 1;
            ary[3][2] = 1;
            ary[2][1] = 1;
            ary[4][0] = 1;
            TS_ASSERT(DFS(ary, 5, 5, 0, 0, 4, 4) == true);
            /* Fill in some test cases here for cxx test gen */
        }
        void test2(void) {
            std::cout << "test2\n";
            int **ary = new int*[6];
            for (int i = 0; i < 6; i++) {
                ary[i] = new int[6];
                for (int j = 0; j < 6; j++) {
                    ary[i][j] = 0;
                }
            }
            ary[1][1] = 1;
            ary[1][3] = 1;
            ary[2][1] = 1;
            ary[2][3] = 1;
            ary[3][1] = 1;
            ary[3][2] = 1;
            ary[3][3] = 1;
            ary[3][4] = 1;
            ary[3][5] = 1;
            TS_ASSERT(DFS(ary, 6, 6, 0, 0, 5, 5) == true);
            /* Fill in some test cases here for cxx test gen */
        }
        void test3(void) {
            std::cout << "test3\n";
            int **ary = new int*[6];
            for (int i = 0; i < 6; i++) {
                ary[i] = new int[6];
                for (int j = 0; j < 6; j++) {
                    ary[i][j] = 0;
                }
            }
            ary[1][1] = 1;
            ary[1][3] = 1;
            ary[2][1] = 1;
            ary[2][3] = 1;
            ary[3][1] = 1;
            ary[3][2] = 1;
            ary[3][3] = 1;
            ary[3][4] = 1;
            ary[3][0] = 1;
            TS_ASSERT(DFS(ary, 6, 6, 0, 0, 2, 0) == true);
            /* Fill in some test cases here for cxx test gen */
        }
        void test4(void) {
            std::cout << "test1\n";
            int **ary = new int*[5];
            for (int i = 0; i < 5; i++) {
                ary[i] = new int[5];
                for (int j = 0; j < 5; j++) {
                    ary[i][j] = 0;
                }
            }
            ary[0][2] = 1;
            ary[1][2] = 1;
            ary[2][2] = 1;
            ary[3][2] = 1;
            ary[3][2] = 1;
            ary[2][1] = 1;
            ary[4][0] = 1;
            ary[4][1] = 1;
            TS_ASSERT(DFS(ary, 5, 5, 0, 0, 4, 4) == false);
            /* Fill in some test cases here for cxx test gen */
        }
};

