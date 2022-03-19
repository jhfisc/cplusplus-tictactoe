# 
# Makefile for tic-tac-toe
#
XCC=g++
LDFLAGS=-g
CPPFLAGS=-g
LDLIBS=-lstdc++ -lc -lm

all: ttt
clean:
	rm ttt ttt.o support.o

ttt: support.o ttt.o
	$(XCC) $(LDFLAGS) -o ttt ttt.o support.o $(LDLIBS)

ttt.o: ttt.cpp support.hh
	$(XCC) $(CPPFLAGS) -c ttt.cpp

support.o: support.cpp support.hh
	$(XCC) $(CPPFLAGS) -c support.cpp