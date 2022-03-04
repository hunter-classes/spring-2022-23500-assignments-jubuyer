#pragma once

#include <iostream>

class ONode{
private:
  int data;
  ONode *next;

public:
  ONode();
  ONode(int data);
  ONode(int, Node *next);

  void setData(int data);
  void setNext(Node *next);

  int getData();
  Node *getNext();
};
