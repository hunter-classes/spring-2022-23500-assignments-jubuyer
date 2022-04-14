#include <iostream>

#include "Stack.h"
#include "List.h"

Stack::Stack() {
	List *stack = new List();
}

void Stack::push(std::string data) {
	stack->insert(data);
	length++;
}

std::string Stack::pop() {
	if(length < 0) {
		throw STACK_ERR_EMPTY;
	}
	std::string out = stack->getHead();
	stack->remove(0);
	length--;

	return out;
}

std::string Stack::top() {
	if(length < 0) {
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
	return stack->toString();
}

Stack::~Stack() {
	delete stack;
}