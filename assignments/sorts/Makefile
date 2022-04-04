#recipes
# VPATH = src
# SDIR = src
CC = g++
CFLAGS  = -std=c++11 # -Wall

sorts: sorts.o
	$(CC) $(CFLAGS) -o $@ $^

tests: tests.o
	$(CC) $(CFLAGS) -o $@ $^

sorts.o: sorts.cpp
	$(CC) $(CFLAGS) -c $^

.PHONY: clean

clean:
	rm -f *o src/*o sorts tests a.out
