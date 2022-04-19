#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>

#include "doctest.h"
#include "Stack.h"

TEST_CASE("Push") {
  Stack *s1 = new Stack();
  s1->push("first");
  CHECK(s1->toString() == "first-->nullptr");
  s1->push("second");
  CHECK(s1->toString() == "second-->first-->nullptr");
  s1->push("third");
  CHECK(s1->toString() == "third-->second-->first-->nullptr");
  s1->push("fourth");
  CHECK(s1->toString() == "fourth-->third-->second-->first-->nullptr");
}

TEST_CASE("Pop") {
  Stack *s1 = new Stack();
  try {
    s1->pop();
  } catch (int e) {
    CHECK(e == 1);
  }
  s1->push("first");
  s1->push("second");
  s1->push("third");
  s1->push("fourth");

  CHECK(s1->toString() == "fourth-->third-->second-->first-->nullptr");
  s1->pop();
  CHECK(s1->toString() == "third-->second-->first-->nullptr");
  s1->pop();
  CHECK(s1->toString() == "second-->first-->nullptr");
  s1->pop();
  CHECK(s1->toString() == "first-->nullptr");
  s1->pop();
  CHECK(s1->toString() == "Stack is Empty");

}

TEST_CASE("Top") {
  Stack *s1 = new Stack();
  try {
    s1->top();
  } catch (int e) {
    CHECK(e == 1);
  }
  s1->push("first");
  CHECK(s1->top() == "first");
  s1->push("second");
  CHECK(s1->top() == "second");
  s1->push("third");
  CHECK(s1->top() == "third");
  s1->push("fourth");
  CHECK(s1->top() == "fourth");
}

TEST_CASE("is_empty") {
  Stack *s1 = new Stack();
  s1->push("first");
  CHECK(s1->is_empty() == false);
  Stack *s2 = new Stack();
  CHECK(s2->is_empty() == true);
}
