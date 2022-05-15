OBJECTS=main.o List.o Node.o Person.o
CC = g++
LDFLAGS=
CXXFLAGS= -std=c++11

main: $(OBJECTS)
	g++ $(CXXFLAGS) -o main $(OBJECTS)

tests: tests.o List.o Node.o Person.o
	$(CC) $(CXXFLAGS) -o $@ $^

tests.o: tests.cpp doctest.h
	$(CC) $(CXXFLAGS) -c $<

BSTree.o: BSTree.cpp Node.h BSTree.h
	$(CC) $(CXXFLAGS) -c $<

main.o: main.cpp List.h Node.h Person.h
	$(CC) $(CXXFLAGS) -c $<

List.o: List.cpp List.h
	$(CC) $(CXXFLAGS) -c $<

Node.o: Node.cpp Node.h Person.h
	$(CC) $(CXXFLAGS) -c $<

Person.o: Person.cpp Person.h
	$(CC) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJECTS) main tests *o a.out
