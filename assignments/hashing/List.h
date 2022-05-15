#pragma once

#include <iostream>
#include "Node.h"

class List{
private:
  Node *head;

public:
  List();
  void insert(std::string first, std::string last, int num);
  std::string toString();
  void locate(int location, std::string first, std::string last, int num);
  void remove(int location);
  ~List();
};
