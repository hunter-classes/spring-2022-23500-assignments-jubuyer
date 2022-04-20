#recipes
# VPATH = src
# SDIR = src
CC = g++
CFLAGS  = -std=c++11 #-Wall

main: main.o Queue.o Stack.o List.o Node.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp Stack.h
	$(CC) $(CFLAGS) -c $<

tests: tests.o Queue.o Stack.o List.o Node.o
	$(CC) $(CFLAGS) -o $@ $^

tests.o: tests.cpp doctest.h
	$(CC) $(CFLAGS) -c $<

Stack.o: Stack.cpp Stack.h List.h
	$(CC) $(CFLAGS) -c $<

Queue.o: Queue.cpp Queue.h
	$(CC) $(CFLAGS) -c $<

List.o: List.cpp List.h Node.h
	$(CC) $(CFLAGS) -c $<

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm -f *o src/*o main tests listTest a.out
