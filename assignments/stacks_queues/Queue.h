#pragma once

#define QUEUE_ERR_EMPTY 1
#define QUEUE_ERR_FULL 2
#define QUEUE_ERR_OTHER 4

#include <iostream>
#include <string>

class Queue{
private:
  int *queue;
  int head;
  int tail;
  int queued;
public:
  Queue();
  void enqueue(int data);
  int dequeue();
  int front();
  std::string toString();
  bool is_empty();
  bool is_full();
  std::string parts();
  ~Queue();
};
