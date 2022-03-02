#recipes
# VPATH = src
# SDIR = src
CC = g++
CFLAGS  = -std=c++11 #-Wall

main: main.o Node.o List.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp Node.h
	$(CC) $(CFLAGS) -c $<

List.o: List.cpp List.h Node.h
	$(CC) $(CFLAGS) -c $<

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm -f *o src/*o main tests a.out
