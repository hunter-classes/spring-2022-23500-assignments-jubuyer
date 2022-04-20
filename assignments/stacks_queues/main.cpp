#include <iostream>

#include "Stack.h"
#include "Queue.h"

int main(int argc, char const *argv[])
{
	std::cout << "Stacks" << '\n';

	std::cout << "Test Stack:" << '\n';
	Stack *s1 = new Stack();
	s1->push("a");
	s1->push("b");
	s1->push("c");

	std::cout << "\nTop of the stack is: " << s1->top() << '\n';
	std::cout << s1->toString() << "\n\n";

	s1->pop();
	s1->pop();

	std::cout << s1->toString() << "\n\n";

	s1->pop();

	std::cout << s1->toString() << "\n\n";

	std::cout << "Testing Exceptions:" << '\n';
	try {
		s1->pop();
	} catch (int e) {
		std::cout << "ERR " << e << ": Empty stack\n";
	}

	std::cout << "Testing Destructor:" << '\n';
	delete s1;

	std::cout << "Test Queue:" << '\n';
	Queue *q1 = new Queue();
	std::cout << q1->toString();
	try {
		q1->dequeue();
	} catch (int e) {
		std::cout << "ERR " << e << ": Empty queue\n";
	}
	q1->enqueue(1);
	std::cout << q1->toString();
	q1->enqueue(53);
	q1->enqueue(12);
	std::cout << q1->toString();
	q1->dequeue();
	std::cout << q1->toString();
	q1->enqueue(21);
	q1->enqueue(5122);
	std::cout << q1->toString();
	q1->enqueue(902);
	std::cout << q1->toString();

	try {
		q1->enqueue(13);
	} catch (int e) {
		std::cout << "ERR " << e << ": Full queue\n";
	}
	q1->dequeue();
	q1->enqueue(21);
	std::cout << q1->toString();

}
