#recipes
# VPATH = src
# SDIR = src
CC = g++
CFLAGS  = -std=c++11 -Wall

main: main.o
	$(CC) $(CFLAGS) -o $@ $^

tests: tests.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^

.PHONY: clean

clean:
	rm -f *o src/*o main tests a.out
