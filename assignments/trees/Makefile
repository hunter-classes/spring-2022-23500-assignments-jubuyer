OBJECTS=main.o BSTree.o Node.o
LDFLAGS=
CXXFLAGS= -std=c++11

main: $(OBJECTS)
	g++ $(CXXFLAGS) -o main $(OBJECTS)

tests: tests.o Node.h BSTree.h
	$(CC) $(CXXFLAGS) -o $@ $^

tests.o: tests.cpp doctest.h
	$(CC) $(CXXFLAGS) -c $<

BSTree.o: BSTree.cpp Node.h BSTree.h

main.o: main.cpp Node.h BSTree.h

Node.o: Node.cpp Node.h

clean:
	rm -f $(OBJECTS) main
