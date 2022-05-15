#include <iostream>
#include "Person.h"

int main() {
  std::cout << "hashing Project 7" << '\n';

  //just testing stuff ;)

  Person *test = new Person("jubayer", "ahmed", 2);
  std::cout << test->get_name() << '\n';
  std::cout << test->get_id() << '\n';

  return 0;
}
