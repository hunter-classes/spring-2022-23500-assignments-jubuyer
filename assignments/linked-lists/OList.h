#pragma once

#include <iostream>
#include "ONode.h"

class OList{
private:
  ONode *head;

public:
  OList();
  void insert(int data);
  std::string toString();
  ~OList();
};
