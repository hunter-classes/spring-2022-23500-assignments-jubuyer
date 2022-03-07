#pragma once

#include <iostream>
#include "ONode.h"

class OList{
private:
  ONode *head;

public:
  OList();
  void insert(int data);
  bool contains(int value);
  int value(int location);
  void remove(int location);
  void reverse();
  std::string toString();
  ~OList();
};
