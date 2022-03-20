# 
# Makefile for tic-tac-toe
#
XCC=g++
LDFLAGS=-g
CPPFLAGS=-g -I./include
LDLIBS=-lstdc++ -lc -lm

all: ttt TicTacToe

clean:
	rm ttt TicTacToe target/ttt.o target/support.o target/TicTacToe.o

ttt: target/support.o target/ttt.o
	$(XCC) $(LDFLAGS) -o ttt target/ttt.o target/support.o $(LDLIBS)

target/ttt.o: src/ttt.cpp include/support.hh
	$(XCC) $(CPPFLAGS) -c src/ttt.cpp -o target/ttt.o

target/support.o: src/support.cpp include/support.hh
	$(XCC) $(CPPFLAGS) -c src/support.cpp -o target/support.o

target/TicTacToe.o: src/TicTacToe.cpp include/TicTacToe.hh
	$(XCC) $(CPPFLAGS) -c src/TicTacToe.cpp -o target/TicTacToe.o

TicTacToe: target/TicTacToe.o
	$(XCC) $(LDFLAGS) -o TicTacToe target/TicTacToe.o $(LDLIBS)
