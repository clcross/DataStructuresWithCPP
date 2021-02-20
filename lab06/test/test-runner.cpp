/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

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
#include "/home/student/csci-315-fall-2019/lab06/test/remove-test.cpp"

static MyTestSuite1 suite_MyTestSuite1;

static CxxTest::List Tests_MyTestSuite1 = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite1( "test/remove-test.cpp", 6, "MyTestSuite1", suite_MyTestSuite1, Tests_MyTestSuite1 );

static class TestDescription_suite_MyTestSuite1_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_test1() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 13, "test1" ) {}
 void runTest() { suite_MyTestSuite1.test1(); }
} testDescription_suite_MyTestSuite1_test1;

static class TestDescription_suite_MyTestSuite1_test2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_test2() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 19, "test2" ) {}
 void runTest() { suite_MyTestSuite1.test2(); }
} testDescription_suite_MyTestSuite1_test2;

static class TestDescription_suite_MyTestSuite1_test3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_test3() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 25, "test3" ) {}
 void runTest() { suite_MyTestSuite1.test3(); }
} testDescription_suite_MyTestSuite1_test3;

static class TestDescription_suite_MyTestSuite1_test4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_test4() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 31, "test4" ) {}
 void runTest() { suite_MyTestSuite1.test4(); }
} testDescription_suite_MyTestSuite1_test4;

static class TestDescription_suite_MyTestSuite1_test5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_test5() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 37, "test5" ) {}
 void runTest() { suite_MyTestSuite1.test5(); }
} testDescription_suite_MyTestSuite1_test5;

static class TestDescription_suite_MyTestSuite1_test6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_test6() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 41, "test6" ) {}
 void runTest() { suite_MyTestSuite1.test6(); }
} testDescription_suite_MyTestSuite1_test6;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
