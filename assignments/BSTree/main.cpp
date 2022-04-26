#include <iostream>
#include "Node.h"
#include "BSTree.h"

int main() {
  // Node *n = new Node(20);
  // std::cout << n->getData() << '\n';
  // Node *n2 = new Node(30);
  // n->setLeft(n2);
  // Node *n3 = new Node(40);
  // n->setRight(n3);
  //
  // std::cout << n->getLeft()->getData() << '\n';
  // std::cout << n->getRight()->getData() << '\n';

  Node *root = new Node(10);
  Node *n1 = new Node(20);
  root->setLeft(n1);
  Node *n2 = new Node(30);
  n1->setLeft(n2);
  Node *n3 = new Node(40);
  n2->setLeft(n3);

  Node *n4 = new Node(50);
  root->setRight(n4);
  Node *n5 = new Node(60);
  n4->setLeft(n5);
  Node *n6 = new Node(70);
  n4->setRight(n6);


  std::cout << root->getData() << '\n';
  std::cout << root->getLeft()->getData() << '\n';
  std::cout << root->getRight()->getData() << '\n';

  std::cout << "TREE" << '\n';
  BSTree *t = new BSTree();
  t->setup();
  std::cout << t->get_debug_string() << '\n';

  return 0;
}
