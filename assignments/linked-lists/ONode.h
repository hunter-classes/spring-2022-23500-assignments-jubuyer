#pragma once

#include <iostream>

class ONode{
private:
  int data;
  ONode *next;

public:
  ONode();
  ONode(int data);
  ONode(int, ONode *next);

  void setData(int data);
  void setNext(ONode *next);

  int getData();
  ONode *getNext();
};
