DEBUG = ok 
FLAGS = 

CXX = g++
CC = gcc

OBJS = ../Module.o ../Support.o

UNIT_OBJS = CuTest/CuTest.o tests.o unittest.o $(OBJS)
JOIN_OBJS = jointest.o $(OBJS)

UNIT_TARGET = ./unittest
JOIN_TARGET = ./jointest

INCLUDE = 
LDLIBS =
CXXFLAGS = -O3 -Wall $(INCLUDE) $(FLAGS)

ifdef DEBUG
CXXFLAGS = -g -O0 -Wall -D_DEBUG $(INCLUDE) $(FLAGS)
endif

.SUFFIXES: .o.cpp
.PHONY: clean

all: $(JOIN_TARGET)

$(JOIN_TARGET): $(JOIN_OBJS)
	$(CC) $(JOIN_OBJS) -o $(JOIN_TARGET) $(CXXFLAGS) $(LDLIBS)

.cpp.o:
	$(CC) $(CXXFLAGS) -c $< -o $@


$(UNIT_TARGET): $(UNIT_OBJS)
	$(CC) $(UNIT_OBJS) -o $(UNIT_TARGET) $(CXXFLAGS) $(LDLIBS)

clean:
	rm -f $(UNIT_TARGET) $(JOIN_TARGET) $(UNIT_OBJS) $(JOIN_OBJS) *~
