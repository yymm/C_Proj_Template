#!/usr/bin/env python

import re
import argparse
import subprocess

def create_source_for_CuTest():
    """Create a source code as unittest.cpp for CuTest.

    CuTest is unit test framework for c/c++.
    Target file is tests.cpp. In tests.cpp defined Test functions.  
    """
    filename = "tests.cpp"
    include = '''
/* This is auto-generated code. Edit at your own peril. */
#include <stdio.h>
#include <stdlib.h>

#include "CuTest/CuTest.h"

extern void Setup(CuTest* tc);
extern void Teardown(CuTest* tc);'''
    test = ""
    extern = ""
    with open(filename) as f:
        for line in f:
            if re.search(r"^void Test", line):
                extern += "extern " + line[:-1] + ";\n"
                test += "    SUITE_ADD_TEST(suite, " + line[5:].split('(')[0] + ");\n"
    head = '''
void RunAllTests(void) 
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, Setup);
    '''
    tail = '''
    SUITE_ADD_TEST(suite, Teardown);
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\\n", output->buffer);
    CuStringDelete(output);
    CuSuiteDelete(suite);
}
int main(void)
{
    RunAllTests();
}'''
    with open("unittest.cpp", "w") as f:
        f.write(include + extern + head + test + tail)

if '__main__' == __name__:
    parser = argparse.ArgumentParser(description='C-lang builder by python')
    parser.add_argument('target', type=str, nargs='?', default='jointest', help='target name in Makefile')
    args = parser.parse_args()
    target = unicode(args.target)

    if target != u'unittest' and target != u'jointest':
        print("Invalid argument. 'unittest' or 'jointest'")
    print('## Build target : "'+ target + '"\n')

    if target == u'unittest':
        create_source_for_CuTest()

    cmdline = "make clean && make " + target

    p = subprocess.Popen(cmdline, shell=True,
                         cwd='.',
                         stdin=subprocess.PIPE,
                         stdout=subprocess.PIPE,
                         stderr=subprocess.STDOUT,
                         close_fds=True)
    (stdout, stdin) = (p.stdout, p.stdin)
    while True:
        line = stdout.readline()
        if not line:
            break
        print line,
