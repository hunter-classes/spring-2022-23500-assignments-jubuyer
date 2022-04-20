#pragma once

#define QUEUE_ERR_EMPTY 1
#define QUEUE_ERR_FULL 2
#define QUEUE_ERR_OTHER 4

#include <iostream>
#include <string>

class Queue{
private:
  std::string *queue;
  int head;
  int tail;

public:
  Queue();
  void enqueue(std::string data);
  std::string dequeue();
  std::string front();
  std::string toString();
  bool is_empty();
  bool is_full();
  ~Queue();
};
