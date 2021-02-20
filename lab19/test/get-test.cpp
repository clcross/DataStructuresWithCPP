#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "hashtable.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            HashTable<int, int> ht(100, .80);
            ht.insert(47, 100);
            ht.insert(49, 200);
            ht.insert(1149, 300);
            TS_ASSERT_EQUALS(ht[47], 100);
            TS_ASSERT_EQUALS(ht[1149], 300);
            TS_ASSERT_EQUALS(ht[49], 200);
        }
};
