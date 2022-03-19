# 
# Makefile for tic-tac-toe
#
XCC=g++
LDFLAGS=-g
CPPFLAGS=-g -I./include
LDLIBS=-lstdc++ -lc -lm

all: ttt
clean:
	rm ttt ttt.o support.o

ttt: target/support.o target/ttt.o
	$(XCC) $(LDFLAGS) -o ttt target/ttt.o target/support.o $(LDLIBS)

target/ttt.o: src/ttt.cpp include/support.hh
	$(XCC) $(CPPFLAGS) -c src/ttt.cpp -o target/ttt.o

target/support.o: src/support.cpp include/support.hh
	$(XCC) $(CPPFLAGS) -c src/support.cpp -o target/support.o
