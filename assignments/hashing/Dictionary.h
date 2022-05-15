#pragma once

#include <iostream>
#include "List.h"

class Dictionary{
private:
  List *arr[10];

public:
  Dictionary();

  int hash(Person *p);

  void insert(Person *data);
  void insert(std::string first, std::string last, int num);
  Person* getEntry(std::string first, std::string last);
  std::string getKeys();

  ~Dictionary();
};
