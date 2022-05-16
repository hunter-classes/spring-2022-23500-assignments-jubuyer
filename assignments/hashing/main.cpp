#include <iostream>
#include "Person.h"
#include "Node.h"
#include "List.h"
#include "Dictionary.h"

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
  Person *prof = new Person("professor", "jub", 1);
  n->setData(prof);
  arr[0]->insert(n);
  std::cout << arr[0]->toString() << '\n';

  std::cout << "\n\x1B[31mtesting dictionary\033[0m" << '\n';
  Dictionary *phonebook = new Dictionary();
  Person *test3 = new Person("andres", "castillo", 4);
  Person *test4 = new Person("johnny", "abshire", 5);
  Person *test5 = new Person("princess", "peach", 6);
  Person *test6 = new Person("mario", "figuero", 7);
  Person *test7 = new Person("luigi", "figuero", 8);
  Person *test8 = new Person("sir", "froggy", 9);
  phonebook->enter(test3);
  phonebook->enter(test4);
  phonebook->enter(test5);
  std::cout << phonebook->getKeys() << '\n';
  phonebook->enter(test6);
  phonebook->enter(test7);
  phonebook->enter(test8);
  std::cout << phonebook->getKeys() << '\n';
  Person *test9 = new Person("Charles", "Xavier", 11);
  Person *test10 = new Person("El", "Patron", 12);
  Person *test11 = new Person("Don", "Toliver", 13);
  Person *test12 = new Person("Mister", "P", 14);
  Person *test13 = new Person("Miss", "P", 15);
  Person *test14 = new Person("Jenny", "Blanc", 16);
  Person *test15 = new Person("Willy", "Wonka", 17);
  Person *test16 = new Person("Captain", "Pierce", 18);
  Person *test17 = new Person("Jerry", "Mouse", 19);
  Person *test18 = new Person("sir", "kitty", 10);

  phonebook->enter(test9);
  phonebook->enter(test10);
  phonebook->enter(test11);
  phonebook->enter(test12);
  phonebook->enter(test13);
  phonebook->enter(test14);
  phonebook->enter(test15);
  phonebook->enter(test16);
  phonebook->enter(test17);
  phonebook->enter(test18);
  std::cout << "Phonebook: " << '\n';
  std::cout << phonebook->getKeys() << '\n';

  std::cout << phonebook->retrieve("sir", "kitty")->get_name();
  std::cout << " ID# " << phonebook->retrieve("sir", "kitty")->get_id() << '\n';

  std::cout << phonebook->retrieve("johnny", "abshire")->get_name();
  std::cout << " ID# " << phonebook->retrieve("johnny", "abshire")->get_id() << '\n';

  std::cout << "trying to retrieve NONEXISTENT_ENTRY" << '\n';
  try {
    phonebook->retrieve("non", "existent");

    std::cout << "this string will never reach the terminal" << '\n';
  } catch (int e) {
    std::cout << "Dictionary ERR: " << e << '\n';
  }
  return 0;
}
