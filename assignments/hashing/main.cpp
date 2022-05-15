#include <iostream>
#include "Person.h"
#include "Node.h"
#include "List.h"

int main() {
  std::cout << "hashing Project 7" << '\n';

  //just testing stuff ;)

  Person *test = new Person("jubayer", "ahmed", 2);
  std::cout << test->get_name() << '\n';
  std::cout << test->get_id() << '\n';

  Node *n = new Node(test);
  std::cout << n->getData() << '\n';

  Person *test2 = new Person("michael", "zamansky", 1);
  Node *n2 = new Node(test2);
  std::cout << n2->getData() << '\n';

  std::cout << "\ntesting list" << '\n';
  List *l1 = new List();
  l1->insert(n);
  l1->insert(n2);
  std::cout << l1->toString() << '\n';

  List *arr[5] = {};
  arr[0] = new List();
  Person *test3 = new Person("professor", "jub", 1);
  n->setData(test3);
  arr[0]->insert(n);
  std::cout << arr[0]->toString() << '\n';

  
  return 0;
}
