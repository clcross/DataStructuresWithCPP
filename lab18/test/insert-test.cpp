#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "hashtable.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            HashTable<int, int> ht(100);
            ht.insert(99, 9001);
            ht.insert(399, 9101);
            ht.insert(299, 9201);
            ht.insert(199, 9301);
            ht.print();
            TS_ASSERT_EQUALS(ht[99], 9001);
            TS_ASSERT_EQUALS(ht[399], 9101);
            TS_ASSERT_EQUALS(ht[299], 9201);
            TS_ASSERT_EQUALS(ht[199], 9301);
        }
};
