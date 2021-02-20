/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite1_init = false;
#include "/Volumes/Cameron HDD/CSCIDATA/csci-315-fall-2019/lab16/test/heap-test.cpp"

static MyTestSuite1 suite_MyTestSuite1;

static CxxTest::List Tests_MyTestSuite1 = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite1( "test/heap-test.cpp", 7, "MyTestSuite1", suite_MyTestSuite1, Tests_MyTestSuite1 );

static class TestDescription_suite_MyTestSuite1_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_test1() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 9, "test1" ) {}
 void runTest() { suite_MyTestSuite1.test1(); }
} testDescription_suite_MyTestSuite1_test1;

static class TestDescription_suite_MyTestSuite1_test2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_test2() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 17, "test2" ) {}
 void runTest() { suite_MyTestSuite1.test2(); }
} testDescription_suite_MyTestSuite1_test2;

static class TestDescription_suite_MyTestSuite1_test3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_test3() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 26, "test3" ) {}
 void runTest() { suite_MyTestSuite1.test3(); }
} testDescription_suite_MyTestSuite1_test3;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
