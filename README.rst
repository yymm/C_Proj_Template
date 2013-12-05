A project template for C language
=================================

* using CuTest : `CuTest: The Cutest C Unit Testing Framework <http://cutest.sourceforge.net/>`_
* using Python2.x

Usage
-----

.. code-block:: bash

  $ cd test
  $ ./build.py unittest
  (Runing build for unittest)
  (At this time unittest.cpp automatically create.)
  $ ./unittest
  (Runing unittest)
  $ ./build.py
  (Runing build for jointest)
  $ ./jointest
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

The function start at "void Test\_"

"unittest.cpp" is automatically create from "tests.py".
