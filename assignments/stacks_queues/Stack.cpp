#include <iostream>

#include "Stack.h"

Stack::Stack() {
	stack = new List();
	length = 0;
}

void Stack::push(std::string data) {
	if(length > 999999) {
		throw STACK_ERR_FULL;
	}

	stack->insert(data);
	length++;
}

std::string Stack::pop() {
	if(length == 0) {
		throw STACK_ERR_EMPTY;
	}
	std::string out = stack->getHead();
	stack->remove(0);
	length--;

	return out;
}

std::string Stack::top() {
	if(length == 0) {
		throw STACK_ERR_EMPTY;
	}

	return stack->getHead();;
}

bool Stack::is_empty() {
	if (length == 0) {
		return true;
	}

	return false;
}

std::string Stack::toString() {
	if(length == 0) {
		return "Stack is Empty";
	}
	return stack->toString();
}

Stack::~Stack() {
	delete stack;
}
