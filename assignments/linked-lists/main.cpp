#include <iostream>

#include "OList.h"

int main(int argc, char const *argv[]) {
  std::cout << "Project 2 JA" << '\n';

  OList *list = new OList();

  std::cout << "Testing insert()" << '\n'; //works
  list->insert(1);
  std::cout << list->toString() << '\n';
  list->insert(-9);
  std::cout << list->toString() << '\n';
  list->insert(0);
  std::cout << list->toString() << '\n';
  list->insert(-2);
  std::cout << list->toString() << '\n';
  list->insert(41);
  std::cout << list->toString() << '\n';
  list->insert(9);
  std::cout << list->toString() << '\n';
  list->insert(11);
  std::cout << list->toString() << '\n';
  list->insert(1412);
  std::cout << list->toString() << '\n';
  list->insert(-1);
  std::cout << list->toString() << '\n';

  std::cout << "Testing contains()" << '\n'; //works
  std::cout << list->contains(11) << '\n';
  std::cout << list->contains(99) << '\n';
  std::cout << list->contains(41) << '\n';
  std::cout << list->contains(-1) << '\n';

  std::cout << "Testing get()" << '\n'; //works
  std::cout << list->get(0) << '\n';
  std::cout << list->get(2) << '\n';
  std::cout << list->get(5) << '\n';
  // std::cout << list->get(124) << '\n'; works

  std::cout << "Testing remove()" << '\n'; //works
  std::cout << list->toString() << '\n';
  list->remove(0);
  std::cout << list->toString() << '\n';
  list->remove(0);
  std::cout << list->toString() << '\n';
  list->remove(0);
  std::cout << list->toString() << '\n';
  // list->remove(-1); works
  // std::cout << list->toString() << '\n';
  // list->remove(100); works
  // std::cout << list->toString() << '\n';

  std::cout << "Testing reverse()" << '\n'; //works
  OList *test = new OList();
  OList *test2 = new OList();
  OList *test3 = new OList();
  test->insert(2);

  std::cout << test->toString() << '\n';
  test->reverse();
  std::cout << test->toString() << "\n\n";

  std::cout << test2->toString() << '\n';
  test2->reverse();
  std::cout << test2->toString() << "\n\n";

  std::cout << list->toString() << '\n';
  list->reverse();
  std::cout << list->toString() << "\n\n";

  test3->insert(5);
  test3->insert(6);
  std::cout << test3->toString() << '\n';
  test3->reverse();
  std::cout << test3->toString() << "\n\n";

  //tested with doctests
  //std::cout << "Testing destructor" << '\n'; //works
  //delete list;
  //std::cout << list->toString() << '\n';
  return 0;
}
