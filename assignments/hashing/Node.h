#pragma once

#include <iostream>
#include "Person.h"

class Node{
private:
  Person *data;
  Node *next;

public:
  Node();
  Node(Person *data);
  Node(Person *data, Node *next);

  void setData(Person *data);
  void setNext(Node *next);

  std::string getData();
  Node *getNext();
};
