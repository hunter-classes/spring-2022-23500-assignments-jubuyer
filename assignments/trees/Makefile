OBJECTS=main.o BSTree.o Node.o
CC = g++
LDFLAGS=
CXXFLAGS= -std=c++11

main: $(OBJECTS)
	g++ $(CXXFLAGS) -o main $(OBJECTS)

tests: tests.o BSTree.o Node.o
	$(CC) $(CXXFLAGS) -o $@ $^

tests.o: tests.cpp doctest.h
	$(CC) $(CXXFLAGS) -c $<

BSTree.o: BSTree.cpp Node.h BSTree.h
	$(CC) $(CXXFLAGS) -c $<

main.o: main.cpp Node.h BSTree.h
	$(CC) $(CXXFLAGS) -c $<

Node.o: Node.cpp Node.h
	$(CC) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJECTS) main tests *o a.out 
