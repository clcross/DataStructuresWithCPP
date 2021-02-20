#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include "hashtable.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void test1(void) {
            HashTable<int, int> ht(100, .80);
            TS_ASSERT_EQUALS(ht.percentFull(), 0.0);
            ht.insert(47, 100);
            TS_ASSERT_DELTA(ht.percentFull(), 0.01, 0.001);
            ht.insert(49, 100);
            TS_ASSERT_DELTA(ht.percentFull(), 0.02, 0.001);
        }
};
