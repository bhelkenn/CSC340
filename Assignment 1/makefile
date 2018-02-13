# Makefile entries are arranged as sets of targets to build, dependencies
# required to build that target, and the system command to build the target:
#
# target: dependencies
# [tab] system_command
#
# We can also use variables in our makefile, to make it easier to change
# compilers, or compilation flags.  The variable values are substituted
# wherever you see the $(VARIABLE) in the makefile
CC=g++
CFLAGS=-c -Wall -std=c++0x

all: driver

driver: main.o
	$(CC) main.o -o driver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o driver
