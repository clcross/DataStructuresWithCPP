#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            Heap<int> heap(100);
            heap.insert(50);
            heap.insert(100);
            //heap.print();
            TS_ASSERT(heap[0] == 100);
            TS_ASSERT(heap[1] == 50);
        }
        void test2(void) {
            Heap<int> heap(100);
            heap.insert(50);
            heap.insert(100);
            heap.insert(150);
            heap.insert(250);
            //heap.print();
            TS_ASSERT(heap[0] == 250);
        }
        void test3(void) {
            srand(200);
            Heap<int> heap(1000);
            heap.insert(50);
            heap.insert(100);
            heap.insert(150);
            heap.insert(250);
            for (int i = 0; i < 100; i++) {
                heap.insert(rand() % 1000);
            }
            //heap.print();
        }
};
