
/* This is auto-generated code. Edit at your own peril. */
#include <stdio.h>
#include <stdlib.h>

#include "CuTest/CuTest.h"

extern void Setup(CuTest* tc);
extern void Teardown(CuTest* tc);extern void Test_CreateModule(CuTest* tc);
extern void Test_DeleteModule(CuTest* tc);
extern void Test_Method(CuTest* tc);
extern void Test_SupportFunction(CuTest* tc);

void RunAllTests(void) 
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, Setup);
        SUITE_ADD_TEST(suite, Test_CreateModule);
    SUITE_ADD_TEST(suite, Test_DeleteModule);
    SUITE_ADD_TEST(suite, Test_Method);
    SUITE_ADD_TEST(suite, Test_SupportFunction);

    SUITE_ADD_TEST(suite, Teardown);
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    CuStringDelete(output);
    CuSuiteDelete(suite);
}
int main(void)
{
    RunAllTests();
}