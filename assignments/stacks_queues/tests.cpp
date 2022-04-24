#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>

#include "doctest.h"
#include "Stack.h"
#include "Queue.h"

// Stack Test Cases
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

// Queue Test Cases
TEST_CASE("enqueue") {
  Queue *q1 = new Queue();
  try {
    q1->dequeue();
  } catch (int e) {
    CHECK(e == 1);
  }
  q1->enqueue(1);
  CHECK(q1->toString() == "1 --> end\n");
  q1->enqueue(53);
  CHECK(q1->toString() == "1 --> 53 --> end\n");
  q1->enqueue(12);
  CHECK(q1->toString() == "1 --> 53 --> 12 --> end\n");
  q1->enqueue(412);
  CHECK(q1->toString() == "1 --> 53 --> 12 --> 412 --> end\n");
  q1->enqueue(91);
  CHECK(q1->toString() == "1 --> 53 --> 12 --> 412 --> 91 --> end\n");
  try {
    q1->enqueue(12);
  } catch (int e) {
    CHECK(e == 2);
  }

}

TEST_CASE("dequeue") {
  Queue *q1 = new Queue();
  try {
    q1->dequeue();
  } catch (int e) {
    CHECK(e == 1);
  }
  q1->enqueue(1);
  q1->enqueue(53);
  q1->enqueue(12);
  q1->enqueue(412);
  q1->enqueue(91);

  CHECK(q1->toString() == "1 --> 53 --> 12 --> 412 --> 91 --> end\n");
  q1->dequeue();
  CHECK(q1->toString() == "53 --> 12 --> 412 --> 91 --> end\n");
  q1->dequeue();
  CHECK(q1->toString() == "12 --> 412 --> 91 --> end\n");
  q1->dequeue();
  CHECK(q1->toString() == "412 --> 91 --> end\n");
  q1->dequeue();
  CHECK(q1->toString() == "91 --> end\n");
  q1->dequeue();
  CHECK(q1->toString() == "Queue is empty\n");
}

TEST_CASE("front") {
  Queue *q1 = new Queue();
  try {
    q1->dequeue();
  } catch (int e) {
    CHECK(e == 1);
  }
  try {
    q1->front();
  } catch (int e) {
    CHECK(e == 1);
  }
  q1->enqueue(1);
  CHECK(q1->front() == 1);
  q1->enqueue(53);
  CHECK(q1->front() == 1);
  q1->enqueue(12);
  CHECK(q1->front() == 1);
  q1->enqueue(412);
  CHECK(q1->front() == 1);
  q1->enqueue(91);
  CHECK(q1->front() == 1);
  q1->dequeue();
  CHECK(q1->front() == 53);
  q1->dequeue();
  CHECK(q1->front() == 12);
}

TEST_CASE("is_empty && is_full") {
  Queue *q1 = new Queue();
  CHECK(q1->is_empty() == true);
  try {
    q1->dequeue();
  } catch (int e) {
    CHECK(e == 1);
  }
  q1->enqueue(1);
  q1->enqueue(53);
  q1->enqueue(12);
  CHECK(q1->is_full() == false);
  q1->enqueue(412);
  q1->enqueue(91);

  try {
    q1->enqueue(5);
  } catch (int e) {
    CHECK(e == 2);
  }
  CHECK(q1->is_empty() == false);
  CHECK(q1->is_full() == true);

}
