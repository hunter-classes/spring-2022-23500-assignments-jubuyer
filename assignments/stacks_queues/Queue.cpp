#include <iostream>
#include <string>

#include "Queue.h"

Queue::Queue() {
  queue = std::string[5];
  head = 0;
  tail = head;
}

void Queue::enqueue(std::string data) {
  if(this->is_full()) {
    throw QUEUE_ERR_FULL;
  }
  queue[tail] = data;
  tail++;

  if(tail > 5) {
    tail %= 5;
  }
}

std::string Queue::dequeue() {
  if(this->is_empty()) {
    throw QUEUE_ERR_EMPTY;
  }
  std::string data = queue[head];
  head++;

  if(head > 5) {
    head %= 5;
  }
  return data;
}

std::string Queue::front() {
  if(this->is_empty()) {
    throw QUEUE_ERR_EMPTY;
  }
  return queue[head];
}

std::string Queue::toString() {
  std::string s = "";
  for(int i = head; i < ; )
}

bool Queue::is_empty() {

}

bool Queue::is_full() {

}

Queue::~Queue() {
  delete[] queue;
}
