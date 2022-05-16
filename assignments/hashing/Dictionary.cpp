#include <iostream>
#include <string>

#include "Dictionary.h"

Dictionary::Dictionary() {
  for(int i = 0; i < 10; i++) {
    table[i] = new List();
  }
}

int Dictionary::hash(Person *p) {
  int first = p->get_first().length();
  int last = p->get_last().length();

  return (((first + last) * 7) % 10);
}

void Dictionary::enter(Person *data) {
  int index = hash(data);

  table[index]->insert(data);

  return;
}

void Dictionary::enter(std::string first, std::string last, int num) {
  Person *data = new Person(first, last, num);
  this->enter(data);

  return;
}

Person* Dictionary::retrieve(std::string first, std::string last) {
  Person *data = new Person(first, last, 0);
  Person *out = nullptr;
  int search = hash(data);

  Node *walker = table[search]->getHead();

  while(walker != nullptr) {
    if(walker->getPerson()->get_name() == data->get_name()) {
      return walker->getPerson();
    }

    walker = walker->getNext();
  }

  //if we are here, the person is not in the dictionary
  throw NONEXISTENT_ENTRY;
  
  return out;
}

std::string Dictionary::getKeys() {
  std::string s = "";
  for(int i = 0; i < 10; i++) {
    s += "\x1B[93mIndex\033[0m ";
    s += std::to_string(i+1);
    s += "\n";
    s += table[i]->toString();
    s += "\n";
  }

  return s;
}

Dictionary::~Dictionary() {
  for(int i = 0; i < 10; i++) {
    delete table[i];
  }
}
