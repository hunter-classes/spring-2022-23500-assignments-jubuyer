#include <iostream>

#include "Stack.h"

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


}
