#include <stdio.h>
#include <stdlib.h>

#include "CuTest/CuTest.h"

//
// Include module for test
//

#include "../Module.h"
#include "../Support.h"

//
// Global parameter
//

Module* module = NULL;

//
// Unittest method(Setup and Teardown)
//

void Setup(CuTest* tc)
{
	module = CreateModule(5);
}
void Teardown(CuTest* tc)
{
	DeleteModule(module);
}

//
// Test methods
//

void Test_CreateModule(CuTest* tc)
{
	Module* m = NULL;
	m = CreateModule(5);
	CuAssertNULL(tc, m);
}

void Test_DeleteModule(CuTest* tc)
{
	Module* m = NULL;
	m = CreateModule(5);
	DeleteModule(m);
	//CuAssertPtrEquals(tc, m, NULL);
}

void Test_Method(CuTest* tc)
{
	int ret = 0;
	ret = Method(module, 5);
	CuAssertIntEquals(tc, ret, 5);
}

void Test_SupportFunction(CuTest* tc)
{
	int ret = 0;
	ret = SupportFunction(5);
	CuAssertIntEquals(tc, ret, 5);
}
