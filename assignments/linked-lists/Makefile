#recipes
# VPATH = src
# SDIR = src
CC = g++
CFLAGS  = -std=c++11 #-Wall

main: main.o ONode.o OList.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp Node.h
	$(CC) $(CFLAGS) -c $<

tests: tests.o ONode.o OList.o
	$(CC) $(CFLAGS) -o $@ $^

tests.o: tests.cpp doctest.h
	$(CC) $(CFLAGS) -c $<

listTest: listTesting.o Node.o List.o
	$(CC) $(CFLAGS) -o $@ $^

listTesting.o: listTesting.cpp List.h Node.h
	$(CC) $(CFLAGS) -c $<

OList.o: OList.cpp OList.h ONode.h
	$(CC) $(CFLAGS) -c $<

ONode.o: ONode.cpp ONode.h
	$(CC) $(CFLAGS) -c $<

List.o: List.cpp List.h Node.h
	$(CC) $(CFLAGS) -c $<

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm -f *o src/*o main tests listTest a.out
