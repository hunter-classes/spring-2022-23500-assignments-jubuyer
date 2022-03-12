#include <iostream>
#include <vector>
#include <climits>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

void print_vector(std::vector<int> a){
  int size = a.size();
  for(int i = 0; i < size; i++)  {
    std::cout << i << ':' << a[i] << '\n';
  }
}

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

int mode2(std::vector<int> v) {
  int size = v.size();
  std::vector<int> store(largest(v),0);
  for(int i = 0; i < size; i++) {
    store[v[i]] += 1;
  }

  //testing purposes
  // std::cout << "PRINTING STORE" << '\n';
  // print_vector(store);

  int max = INT_MIN;
  int index = 0;
  int storage = store.size();
  for(int i = 0; i < storage; i++) {
    if(store[i] > max) {
      max = store[i];
      index = i;
    }
  }

  return index;
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

  std::vector<int> vec = {1,5,4,6,4,4,4,8,12,12,12,12,12,12,12,12,12,6,4,12,6,22};
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
  std::cout << mode2(vec) << '\n';

  std::cout << "Testing mode2" << '\n';
  int size2 = 10000; // default vector size
  int max_val2 = 100; // default max value for entries

  srand(time(NULL));
  std::vector<int> a(size2);

  for(i=0;i<size2;i++){
    a[i] = rand()%max_val2;
  }

  // print_vector(a);

  std::cout << "\nmode2: " << mode2(a) << "\n";
  std::cout << "\nmode1: " << mode(a) << "\n"; //way slower haha

  return 0;
}
