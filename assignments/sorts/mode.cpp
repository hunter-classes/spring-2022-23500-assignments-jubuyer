#include <iostream>

int count(std::vector<int> v, int value) {
  int size = v.size();
  int counter = 0;
  for(int i = 0; i < size; i++) {
    if(v[i] == value) {
      counter++;
    }
  }

  return counter;
}
