#include <iostream>

#include "Node.h"

int main(int argc, char const *argv[]) {
  Node *p1 = new Node();
  p1->setData("p1");

  Node *p2 = new Node("p2");

  p1->setNext(p2);

  std::cout << p1->getData() << '\n';
  std::cout << p2->getData() << '\n';
  std::cout << p1->getNext()->getData() << "\n\n";

  p2 = new Node("new");

  p1->getNext()->setNext(p2);

  std::cout << p1->getData() << '\n';
  std::cout << p1->getNext()->getData() << '\n';
  std::cout << p1->getNext()->getNext()->getData() << "\n\n";

  // Node *walker = p1;
  // std::cout << walker->getData() << '\n';
  //
  // walker = walker->getNext(); //walker = p1->getNext();
  // std::cout << walker->getData() << '\n';
  //
  // walker = walker->getNext();
  // std::cout << walker->getData() << '\n';

  Node *p3 = new Node("p3");

  p3->setNext(p1->getNext());
  p1->setNext(p3);

  Node *walker = p1;
  while(walker != nullptr){
    std::cout << walker->getData() << '\n';
    walker = walker->getNext();
  }

  // std::cout << walker->getData() << '\n'; **seg fault**

  return 0;
}
