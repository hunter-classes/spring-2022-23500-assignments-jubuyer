#pragma once

#define STACK_ERR_EMPTY 1
#define STACK_ERR_FULL 2
#define STACK_ERR_OTHER 4

#include <iostream>
#include "List.h"

class Stack{
private:
  List *stack;
  int length = 0;

public:
  Stack();
  void push(std::string data);
  std::string toString();
  bool is_empty();
  std::string pop();
  std::string top();
  ~Stack();
};