#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "OList.h"
#include "ONode.h"
#include "List.h"

//part1 commented out because it has overlapping functions

// List *list2 = new List();
//
// TEST_CASE("Regular Insert") {
//     list2->insert("z");
//     list2->insert("a");
//     list2->insert("c");
//     CHECK (list2->toString() == "c-->a-->z-->nullptr");
// }
//
// TEST_CASE("Insert at location") {
//     list2->insert("x", 2);
//     CHECK (list2->toString() == "c-->a-->x-->z-->nullptr");
//     list2->insert("why", 0);
//     CHECK (list2->toString() == "why-->c-->a-->x-->z-->nullptr");
//     list2->insert("me", 5);
//     CHECK (list2->toString() == "why-->c-->a-->x-->z-->me-->nullptr");
// }
//
// TEST_CASE("Remove") {
//     list2->remove(0);
//     CHECK (list2->toString() == "c-->a-->x-->z-->me-->nullptr");
//     list2->remove(4);
//     CHECK (list2->toString() == "c-->a-->x-->z-->nullptr");
//     list2->remove(2);
//     CHECK (list2->toString() == "c-->b-->z-->nullptr");
// }
//
// TEST_CASE("Destructor") {
//     delete list2;
//     CHECK (list2->toString() == "nullptr");
// }

//part 2 below :)

TEST_CASE("Testing insert()") {
  OList *list = new OList();
  list->insert(1);
  CHECK(list->toString() == "1 --> nullptr");
  list->insert(-9);
  CHECK(list->toString() == "-9 --> 1 --> nullptr");
  list->insert(0);
  CHECK(list->toString() == "-9 --> 0 --> 1 --> nullptr");
  list->insert(-2);
  CHECK(list->toString() == "-9 --> -2 --> 0 --> 1 --> nullptr");
  list->insert(41);
  CHECK(list->toString() == "-9 --> -2 --> 0 --> 1 --> 41 --> nullptr");
  list->insert(9);
  CHECK(list->toString() == "-9 --> -2 --> 0 --> 1 --> 9 --> 41 --> nullptr");
  list->insert(11);
  CHECK(list->toString() == "-9 --> -2 --> 0 --> 1 --> 9 --> 11 --> 41 --> nullptr");
  list->insert(1412);
  CHECK(list->toString() == "-9 --> -2 --> 0 --> 1 --> 9 --> 11 --> 41 --> 1412 --> nullptr");
  list->insert(-1);
  CHECK(list->toString() == "-9 --> -2 --> -1 --> 0 --> 1 --> 9 --> 11 --> 41 --> 1412 --> nullptr");
}

TEST_CASE("Testing contains()") {
  OList *list = new OList();
  list->insert(1);
  list->insert(-9);
  list->insert(0);
  list->insert(-2);
  list->insert(41);
  list->insert(9);
  list->insert(11);
  list->insert(1412);
  list->insert(-1);

  CHECK(list->contains(11) == 1);
  CHECK(list->contains(99) == 0);
  CHECK(list->contains(41) == 1);
  CHECK(list->contains(-1) == 1);
}

TEST_CASE("Testing get()") {
  OList *list = new OList();
  list->insert(1);
  list->insert(-9);
  list->insert(0);
  list->insert(-2);
  list->insert(41);
  list->insert(9);
  list->insert(11);
  list->insert(1412);
  list->insert(-1);

  CHECK(list->get(0) == -9);
  CHECK(list->get(2) == -1);
  CHECK(list->get(5) == 9);
  CHECK_THROWS_AS(list->get(124), std::out_of_range);
}

TEST_CASE("Testing remove()") {
  OList *list = new OList();
  list->insert(1);
  list->insert(0);
  list->insert(-2);
  list->insert(41);
  list->insert(9);
  list->insert(11);
  list->insert(1412);
  list->insert(-1);

  list->remove(0);
  CHECK(list->toString() == "-1 --> 0 --> 1 --> 9 --> 11 --> 41 --> 1412 --> nullptr");
  list->remove(0);
  CHECK(list->toString() == "0 --> 1 --> 9 --> 11 --> 41 --> 1412 --> nullptr");
  list->remove(0);
  CHECK(list->toString() == "1 --> 9 --> 11 --> 41 --> 1412 --> nullptr");
  CHECK_THROWS_AS(list->remove(124), std::out_of_range);
  CHECK_THROWS_AS(list->remove(-100), std::out_of_range);
}
//
TEST_CASE("Testing reverse()") {
  OList *test = new OList();
  OList *test2 = new OList();
  OList *test3 = new OList();
  OList *list = new OList();
  list->insert(1);
  list->insert(41);
  list->insert(9);
  list->insert(11);
  list->insert(1412);

  test->insert(2);

  CHECK(test->toString() == "2 --> nullptr");
  test->reverse();
  CHECK(test->toString() == "2 --> nullptr");

  CHECK(test2->toString() == "nullptr");
  test2->reverse();
  CHECK(test2->toString() == "nullptr");

  CHECK(list->toString() == "1 --> 9 --> 11 --> 41 --> 1412 --> nullptr");
  list->reverse();
  CHECK(list->toString() == "1412 --> 41 --> 11 --> 9 --> 1 --> nullptr");

  test3->insert(5);
  test3->insert(6);
  CHECK(test3->toString() == "5 --> 6 --> nullptr");
  test3->reverse();
  CHECK(test3->toString() == "6 --> 5 --> nullptr");
}

OList *Olist2 = new OList();

TEST_CASE("Destructor") {
    delete Olist2;
    CHECK (Olist2->toString() == "nullptr");
}
