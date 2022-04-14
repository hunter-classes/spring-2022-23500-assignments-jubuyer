#pragma once

#include <iostream>
#include "Node.h"

class List{
private:
  Node *head;

public:
  List();
  void insert(std::string data);
  std::string toString();
  void locate(int location, std::string data);
  void remove(int location);
  ~List();
};
