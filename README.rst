A project template for C language
=================================

* using CuTest : `CuTest: The Cutest C Unit Testing Framework <http://cutest.sourceforge.net/>`_
* using Python2.x
* using mtrace (Require: glibc)

Usage
-----

.. code-block:: bash

  $ cd test
  $ ./build.py unittest
  (Runing build for unittest)
  (At this time unittest.cpp automatically create.)
  (Runing unittest)
  $ ./build.py
  (Runing build for jointest)
  (Runing jointest)

Need to customize Makefile and tests.cpp for your project.

Makefile
^^^^^^^^

.. code-block:: makefile

    CXX = <compiler for c++ ex. g++>
    
    CC = <compiler for c++ ex. gcc>
    
    UNIT_OBJS = CuTest/CuTest.o tests.o unittest.o <ADD \*.o files here! ex. ../Module.o>

    JOIN_OBJS = jointest.o <ADD \*.o files here! ex. ../Module.o>

Optional.

.. code-block:: makefile

    DEBUG = <Empty is non debuging mode>
    
    FLAGS = <System library?>

    INCLUDE = -I<Include path>

    LDLIBS = -L<Library path> -l<Library name>

UnitTest
^^^^^^^^

Unittest function coding to "tests.py".

Each of function name start at "void Test\_"

"unittest.cpp" is automatically create from "tests.py".

Output Example
^^^^^^^^^^^^^^

.. code-block:: bash


    # Build target : "unittest"
    
    ## BUILD
    
    rm -f ./unittest ./jointest CuTest/CuTest.o tests.o unittest.o ../Module.o ../Support.o jointest.o ../Module.o ../Support.o *~
    icpc -g -O0 -Wall -D_DEBUG   -c CuTest/CuTest.cpp -o CuTest/CuTest.o
    icpc -g -O0 -Wall -D_DEBUG   -c tests.cpp -o tests.o
    icpc -g -O0 -Wall -D_DEBUG   -c unittest.cpp -o unittest.o
    icpc -g -O0 -Wall -D_DEBUG   -c ../Module.cpp -o ../Module.o
    icpc -g -O0 -Wall -D_DEBUG   -c ../Support.cpp -o ../Support.o
    icpc CuTest/CuTest.o tests.o unittest.o ../Module.o ../Support.o -o ./unittest -g -O0 -Wall -D_DEBUG
    
    ## UNIT TEST
    
    ......
    
    OK (6 tests)

.. code-block:: bash

    # Build target : "jointest"
    
    ## BUILD
    
    rm -f ./unittest ./jointest CuTest/CuTest.o tests.o unittest.o ../Module.o ../Support.o jointest.o ../Module.o ../Support.o *~
    icpc -g -O0 -Wall -D_DEBUG   -c jointest.cpp -o jointest.o
    icpc -g -O0 -Wall -D_DEBUG   -c ../Module.cpp -o ../Module.o
    icpc -g -O0 -Wall -D_DEBUG   -c ../Support.cpp -o ../Support.o
    icpc jointest.o ../Module.o ../Support.o -o ./jointest -g -O0 -Wall -D_DEBUG
    
    ## JOIN TEST
    
    This is DEBUG message defined '_DEBUG' env value.
    Method result : 5
    
    ## CHECK MEMORY LEAK
    
    No memory leaks.




