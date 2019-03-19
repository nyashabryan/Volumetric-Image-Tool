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
SOURCES=volimage.cpp vol.cpp
OBJECTS=volimage.o vol.o

main: $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -o volimage $(LIBS)

.cpp.o:
	$(CC) $(CCFLAGS) -c $<

# Type "make depend" to make dependencies
depend:
	$(CC) -M $(SOURCES) > incl.defs

run:
	./volimage ./brain_mri_raws/brain_mri_raws/MRI

extract:
	./volimage ./brain_mri_raws/brain_mri_raws/MRI -x 5 output

difference:
	./volimage ./brain_mri_raws/brain_mri_raws/MRI -d 10 5 output

extract_row:
	./volimage ./brain_mri_raws/brain_mri_raws/MRI -g 5 output

clean:
	rm *.o
	rm main
	rm incl.defs
	rm *.tar.gz

remove_output:
	rm *.raw
	rm *.dat

tar:
	tar -zcvf KTMNYA001.tar.gz makefile README.md *.cpp *.h .git .gitignore