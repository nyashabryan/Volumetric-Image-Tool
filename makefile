# Makefile for C++ programs
# Nyasha Bryan Katemauswa
# 24 February 2019

# include dependencies; rules below
ifeq ($(UNAME),incl.defs)
	include incl.defs
endif

# Directories
SRC=./src
BIN=./bin

CC=g++
CCFLAGS=-std=c++11
SOURCES=main.cpp database.cpp
OBJECTS=main.o database.o

main: $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -o main $(LIBS)

.cpp.o:
	$(CC) $(CCFLAGS) -c $<

# Type "make depend" to make dependencies
depend:
	$(CC) -M $(SOURCES) > incl.defs

run:
	./main

clean:
	rm *.o
	rm main
	rm incl.defs
	rm *.tar.gz

tar:
	tar -zcvf KTMNYA001.tar.gz makefile README.md *.cpp *.h .git .gitignore