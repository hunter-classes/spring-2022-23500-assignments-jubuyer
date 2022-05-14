#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>

#include "doctest.h"
#include "BSTree.h"

TEST_CASE("rsearch") {
  BSTree *t = new BSTree();
  int v = 5;
  try {
    int x  = t->rsearch(v);
    CHECK(x == 5);
  } catch (int e){
    CHECK(e == 1);
  }
  t->setup();
  CHECK(t->get_debug_string() == ", 3, , 5, , 8, , 10, , 15, , 20, , 30, ");
  try {
    int x  = t->rsearch(v);
    CHECK(x == 5);
  } catch (int e){
    CHECK(e == 2);
  }

  v = 22;
  try {
    int x  = t->rsearch(v);
    CHECK(x == 22);
  } catch (int e){
    CHECK(e == 1);
  }
  v = 22121;
  try {
    int x  = t->rsearch(v);
    CHECK(x == 22);
  } catch (int e){
    CHECK(e == 1);
  }
  v = 93242;
  try {
    int x  = t->rsearch(v);
    CHECK(x == 22);
  } catch (int e){
    CHECK(e == 1);
  }
  v = 15;
  try {
    int x  = t->rsearch(v);
    CHECK(x == 15);
  } catch (int e){
    CHECK(e == 1);
  }
}

TEST_CASE("rinsert") {
  BSTree *t = new BSTree();

  t->setup();
  t->rinsert(22);
  CHECK(t->get_debug_string() == ", 3, , 5, , 8, , 10, , 15, , 20, , 22, , 30, ");
  t->rinsert(126);
  CHECK(t->get_debug_string() == ", 3, , 5, , 8, , 10, , 15, , 20, , 22, , 30, , 126, ");
  int v = 93242;
  try {
    int x  = t->rsearch(v);
    CHECK(x == 22);
  } catch (int e){
    CHECK(e == 1);
  }
  v = 126;
  try {
    int x  = t->rsearch(v);
    CHECK(x == 126);
  } catch (int e){
    CHECK(e == 1);
  }
}

TEST_CASE("delete") {
  BSTree *tree = new BSTree();
  tree->insert(8);
  tree->insert(3);
  tree->insert(4);
  tree->insert(2);
  CHECK(tree->get_debug_string() == ", 2, , 3, , 4, , 8, ");
  tree->deleteValue(4);
  CHECK(tree->get_debug_string() == ", 2, , 3, , 8, ");
  tree->deleteValue(2);
  CHECK(tree->get_debug_string() == ", 3, , 8, ");

  BSTree *tree2 = new BSTree();
  tree2->insert(8);
  tree2->insert(3);
  tree2->insert(9);
  tree2->insert(4);
  tree2->insert(2);
  tree2->insert(1);
  tree2->insert(12);
  tree2->insert(10);
  tree2->insert(13);
  CHECK(tree2->get_debug_string() == ", 1, , 2, , 3, , 4, , 8, , 9, , 10, , 12, , 13, ");
  tree2->deleteValue(2);
  CHECK(tree2->get_debug_string() == ", 1, , 3, , 4, , 8, , 9, , 10, , 12, , 13, ");
  tree2->deleteValue(12);
  CHECK(tree2->get_debug_string() == ", 1, , 3, , 4, , 8, , 9, , 10, , 13, ");
  tree2->deleteValue(13);
  CHECK(tree2->get_debug_string() == ", 1, , 3, , 4, , 8, , 9, , 10, ");
  tree2->deleteValue(3);
  CHECK(tree2->get_debug_string() == ", 1, , 4, , 8, , 9, , 10, ");
  tree2->deleteValue(312);
  CHECK(tree2->get_debug_string() == ", 1, , 4, , 8, , 9, , 10, ");
}

TEST_CASE("height") {
  BSTree *tree2 = new BSTree();
  tree2->insert(8);
  tree2->insert(3);
  CHECK(tree2->height() == 2);
  tree2->insert(9);
  tree2->insert(4);
  CHECK(tree2->height() == 3);
  tree2->insert(2);
  tree2->insert(1);
  CHECK(tree2->height() == 4);
}

TEST_CASE("countLeaves") {
  BSTree *tree2 = new BSTree();
  tree2->insert(8);
  tree2->insert(3);
  CHECK(tree2->countLeaves() == 1);
  tree2->insert(9);
  CHECK(tree2->countLeaves() == 2);
  tree2->insert(4);
  tree2->insert(2);
  tree2->insert(1);
  CHECK(tree2->countLeaves() == 3);
  tree2->insert(12);
  tree2->insert(10);
  tree2->insert(13);
  CHECK(tree2->countLeaves() == 4);
}

TEST_CASE("cousins?!") {
  BSTree *tree2 = new BSTree();
  tree2->insert(8);
  tree2->insert(3);
  tree2->insert(9);
  tree2->insert(4);
  tree2->insert(2);
  tree2->insert(1);
  tree2->insert(12);
  tree2->insert(10);
  tree2->insert(13);
  CHECK(tree2->cousins(3,9));
  CHECK(tree2->cousins(4,2));
  CHECK(tree2->cousins(12,4));
  CHECK(!tree2->cousins(9,1));
  CHECK(tree2->cousins(2,12));
}
