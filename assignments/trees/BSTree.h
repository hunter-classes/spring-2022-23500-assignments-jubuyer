#pragma once

#define TREE_ERR_NULL 1
#define TREE_ERR_VALUE_DNE 2

#include <iostream>
#include <stdio.h>


class BSTree{
private:
  Node *root;
  std::string traverse(Node *n);

public:
  BSTree();

  void setup();

  std::string get_debug_string();


  // std::string traverse(Node *n);

  int search(int value);
  void insert(int value);

  // int treesum();
  // int treesum(Node *n);
  int rsearch(int value);
  int rsearch(int value, Node *n);

  void rinsert(int value);
  void rinsert(int value, Node *p);


};
