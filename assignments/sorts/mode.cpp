#include <iostream>
#include <vector>
#include <climits>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

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

int largest(std::vector<int> v) {
  int size = v.size();
  int max = INT_MIN;
  for(int i = 0; i < size; i++) {
    if(v[i] > max) {
      max = v[i];
    }
  }

  return max;
}

int mode(std::vector<int> v) {
  std::vector<int> store;
  int size = v.size();
  for(int i = 0; i < size; i++) {
    store.push_back(count(v,v[i]));
  }

  return v[largest(store)];
}

int main(int argc, char const *argv[]) {
  std::cout << "mode stuff? JA" << '\n';

  int size=50;
  int max_val=1000;

  srand(time(nullptr));
  std::vector<int> vect(size);
  int i;
  for (i=0;i<size; i++){
    vect[i] = rand()%max_val;
  }

  for(auto i : vect) {
    std::cout << i << ',';
  }
  std::cout << "\n";

  std::cout << "Testing largest" << '\n';
  std::cout << largest(vect) << '\n';
  std::cout << "Testing count" << '\n';
  std::cout << count(vect, 100) << '\n';

  std::vector<int> vec = {1,5,4,6,4,4,8,6,4,12,6,22};
  for(auto i : vec) {
    std::cout << i << ',';
  }
  std::cout << "\n";

  std::cout << "Testing largest" << '\n';
  std::cout << largest(vec) << '\n';
  std::cout << "Testing count" << '\n';
  std::cout << count(vec, 100) << '\n';
  std::cout << "Testing mode" << '\n';
  std::cout << mode(vec) << '\n';

  return 0;
}
