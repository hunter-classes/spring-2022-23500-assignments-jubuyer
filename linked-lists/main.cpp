#include <iostream>

#include "List.h"

int main(int argc, char const *argv[]) {
  std::cout << "Linked Lists" << '\n';

  std::cout << "Test List:" << '\n';
  List *l1 = new List();
  l1->insert("a");
  l1->insert("b");
  l1->insert("c");

  std::cout << l1->toString() << "\n\n";

  std::cout << "Testing locate()" << '\n';
  l1->locate(0,"x");
  std::cout << l1->toString() << "\n\n";

  std::cout << "Testing remove()" << '\n';
  l1->remove(0);
  std::cout << l1->toString() << "\n\n";

  std::cout << "Testing destructor" << '\n';
  delete l1;
  std::cout << l1->toString() << '\n';

  return 0;
}
