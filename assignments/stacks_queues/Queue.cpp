#include <iostream>
#include <string>

#include "Queue.h"

Queue::Queue() {
  queue = new int [5];
  head = 0;
  tail = head;
  queued = 0;
}

void Queue::enqueue(int data) {
  if(this->is_full()) {
    throw QUEUE_ERR_FULL;
  }
  queue[tail] = data;
  tail++;

  if(tail > 5) {
    tail %= 5;
  }

  queued++;
}

int Queue::dequeue() {
  if(this->is_empty()) {
    throw QUEUE_ERR_EMPTY;
  }
  int data = queue[head];
  head++;

  if(head > 5) {
    head %= 5;
  }

  queued--;
  return data;
}

int Queue::front() {
  if(this->is_empty()) {
    throw QUEUE_ERR_EMPTY;
  }
  return queue[head];
}

std::string Queue::toString() {
  std::string s = "";
  if(this->is_empty()) {
    return "Queue is empty\n";
  }
  if(head < tail) {
    for(int i = head; i < tail; i++) {
      s += std::to_string(queue[i]);
      s += " --> ";
    }
  } else {
    for(int i = head; i < 5; i++) {
      s += std::to_string(queue[i]);
      s += " --> ";
    }
    for(int j = 0; j < tail; j++) {
      s += std::to_string(queue[j]);
      s += " --> ";
    }
  }
  s += "end";
  s += "\n";
  return s;
}

bool Queue::is_empty() {
  if(head == tail) {
    if(queued < 1) {
      return true;
    }
  }
  return false;
}

bool Queue::is_full() {
 if(head%5 == tail%5) {
   if(queued > 0) {
     return true;
   }
 }
 return false;
}

Queue::~Queue() {
  delete[] queue;
}

std::string Queue::parts() {
  std::string s = "head: ";
  s += std::to_string(this->head);
  s += "\ntail: ";
  s += std::to_string(this->tail);
  s += "\n";

  return s;
}
