#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>

#include "doctest.h"
#include "Dictionary.h"

TEST_CASE("get_id") {
  Person *test3 = new Person("andres", "castillo", 4);
  Person *test4 = new Person("johnny", "abshire", 5);
  Person *test5 = new Person("princess", "peach", 6);
  Person *test6 = new Person("mario", "figuero", 7);
  Person *test7 = new Person("luigi", "figuero", 8);
  Person *test8 = new Person("sir", "froggy", 9);
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

  CHECK(test3->get_id() == 4);
  CHECK(test4->get_id() == 5);
  CHECK(test5->get_id() == 6);
  CHECK(test6->get_id() == 7);
  CHECK(test7->get_id() == 8);
  CHECK(test8->get_id() == 9);
  CHECK(test9->get_id() == 11);
  CHECK(test10->get_id() == 12);
  CHECK(test11->get_id() == 13);
  CHECK(test12->get_id() == 14);
  CHECK(test13->get_id() == 15);
  CHECK(test14->get_id() == 16);
  CHECK(test15->get_id() == 17);
  CHECK(test16->get_id() == 18);
  CHECK(test17->get_id() == 19);
  CHECK(test18->get_id() == 10);
}

TEST_CASE("hash") {
  // returns: (((first + last) * 7) % 10)
  Dictionary *d = new Dictionary();
  Person *test3 = new Person("andres", "castillo", 4);
  Person *test4 = new Person("johnny", "abshire", 5);
  Person *test5 = new Person("princess", "peach", 6);
  Person *test6 = new Person("mario", "figuero", 7);
  Person *test7 = new Person("luigi", "figuero", 8);
  Person *test8 = new Person("sir", "froggy", 9);
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

  CHECK("this" == "this");
  CHECK(d->hash(test3) == 8);
  CHECK(d->hash(test4) == 1);
  CHECK(d->hash(test5) == 1);
  CHECK(d->hash(test6) == 4);
  CHECK(d->hash(test7) == 4);
  CHECK(d->hash(test8) == 3);
  CHECK(d->hash(test9) == 1);
  CHECK(d->hash(test10) == 6);
  CHECK(d->hash(test11) == 0);
  CHECK(d->hash(test12) == 9);
  CHECK(d->hash(test13) == 5);
  CHECK(d->hash(test14) == 0);
  CHECK(d->hash(test15) == 0);
  CHECK(d->hash(test16) == 1);
  CHECK(d->hash(test17) == 0);
  CHECK(d->hash(test18) == 6);
}

TEST_CASE("enter") {
  Dictionary *phonebook = new Dictionary();
  CHECK(phonebook->getKeys() == "\x1B[93mIndex\033[0m 1\nnullptr\n\x1B[93mIndex\033[0m 2\nnullptr\n\x1B[93mIndex\033[0m 3\nnullptr\n\x1B[93mIndex\033[0m 4\nnullptr\n\x1B[93mIndex\033[0m 5\nnullptr\n\x1B[93mIndex\033[0m 6\nnullptr\n\x1B[93mIndex\033[0m 7\nnullptr\n\x1B[93mIndex\033[0m 8\nnullptr\n\x1B[93mIndex\033[0m 9\nnullptr\n\x1B[93mIndex\033[0m 10\nnullptr\n");
  Person *test3 = new Person("andres", "castillo", 4);
  Person *test4 = new Person("johnny", "abshire", 5);
  Person *test5 = new Person("princess", "peach", 6);
  Person *test6 = new Person("mario", "figuero", 7);
  Person *test7 = new Person("luigi", "figuero", 8);
  Person *test8 = new Person("sir", "froggy", 9);
  phonebook->enter(test3);
  phonebook->enter(test4);
  phonebook->enter(test5);
  //std::cout << phonebook->getKeys() << '\n';
  CHECK(phonebook->getKeys() == "\x1B[93mIndex\033[0m 1\nnullptr\n\x1B[93mIndex\033[0m 2\npeach, princess-->abshire, johnny-->nullptr\n\x1B[93mIndex\033[0m 3\nnullptr\n\x1B[93mIndex\033[0m 4\nnullptr\n\x1B[93mIndex\033[0m 5\nnullptr\n\x1B[93mIndex\033[0m 6\nnullptr\n\x1B[93mIndex\033[0m 7\nnullptr\n\x1B[93mIndex\033[0m 8\nnullptr\n\x1B[93mIndex\033[0m 9\ncastillo, andres-->nullptr\n\x1B[93mIndex\033[0m 10\nnullptr\n");
  phonebook->enter(test6);
  phonebook->enter(test7);
  phonebook->enter(test8);
  //std::cout << phonebook->getKeys() << '\n';
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
  CHECK(phonebook->getKeys() == "\x1B[93mIndex\033[0m 1\nMouse, Jerry-->Wonka, Willy-->Blanc, Jenny-->Toliver, Don-->nullptr\n\x1B[93mIndex\033[0m 2\nPierce, Captain-->Xavier, Charles-->peach, princess-->abshire, johnny-->nullptr\n\x1B[93mIndex\033[0m 3\nnullptr\n\x1B[93mIndex\033[0m 4\nfroggy, sir-->nullptr\n\x1B[93mIndex\033[0m 5\nfiguero, luigi-->figuero, mario-->nullptr\n\x1B[93mIndex\033[0m 6\nP, Miss-->nullptr\n\x1B[93mIndex\033[0m 7\nkitty, sir-->Patron, El-->nullptr\n\x1B[93mIndex\033[0m 8\nnullptr\n\x1B[93mIndex\033[0m 9\ncastillo, andres-->nullptr\n\x1B[93mIndex\033[0m 10\nP, Mister-->nullptr\n");

}

TEST_CASE("retrieve") {
  Dictionary *phonebook = new Dictionary();
  Person *test3 = new Person("andres", "castillo", 4);
  Person *test4 = new Person("johnny", "abshire", 5);
  Person *test5 = new Person("princess", "peach", 6);
  Person *test6 = new Person("mario", "figuero", 7);
  Person *test7 = new Person("luigi", "figuero", 8);
  Person *test8 = new Person("sir", "froggy", 9);
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
  phonebook->enter(test3);
  phonebook->enter(test4);
  phonebook->enter(test5);
  phonebook->enter(test6);
  phonebook->enter(test7);
  phonebook->enter(test8);
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

  CHECK(phonebook->retrieve("andres", "castillo")->get_name() == test3->get_name());
  CHECK(phonebook->retrieve("johnny", "abshire")->get_name() == test4->get_name());
  CHECK(phonebook->retrieve("princess", "peach")->get_name() == test5->get_name());
  CHECK(phonebook->retrieve("mario", "figuero")->get_name() == test6->get_name());
  CHECK(phonebook->retrieve("luigi", "figuero")->get_name() == test7->get_name());
  CHECK(phonebook->retrieve("sir", "froggy")->get_name() == test8->get_name());
  CHECK(phonebook->retrieve("Charles", "Xavier")->get_name() == test9->get_name());
  CHECK(phonebook->retrieve("El", "Patron")->get_name() == test10->get_name());
  CHECK(phonebook->retrieve("Don", "Toliver")->get_name() == test11->get_name());
  CHECK(phonebook->retrieve("Mister", "P")->get_name() == test12->get_name());
  CHECK(phonebook->retrieve("Miss", "P")->get_name() == test13->get_name());
  CHECK(phonebook->retrieve("Jenny", "Blanc")->get_name() == test14->get_name());
  CHECK(phonebook->retrieve("Willy", "Wonka")->get_name() == test15->get_name());
  CHECK(phonebook->retrieve("Captain", "Pierce")->get_name() == test16->get_name());
  CHECK(phonebook->retrieve("Jerry", "Mouse")->get_name() == test17->get_name());
  CHECK(phonebook->retrieve("sir", "kitty")->get_name() == test18->get_name());

  CHECK(phonebook->retrieve("andres", "castillo")->get_id() == test3->get_id());
  CHECK(phonebook->retrieve("johnny", "abshire")->get_id() == test4->get_id());
  CHECK(phonebook->retrieve("princess", "peach")->get_id() == test5->get_id());
  CHECK(phonebook->retrieve("mario", "figuero")->get_id() == test6->get_id());
  CHECK(phonebook->retrieve("luigi", "figuero")->get_id() == test7->get_id());
  CHECK(phonebook->retrieve("sir", "froggy")->get_id() == test8->get_id());
  CHECK(phonebook->retrieve("Charles", "Xavier")->get_id() == test9->get_id());
  CHECK(phonebook->retrieve("El", "Patron")->get_id() == test10->get_id());
  CHECK(phonebook->retrieve("Don", "Toliver")->get_id() == test11->get_id());
  CHECK(phonebook->retrieve("Mister", "P")->get_id() == test12->get_id());
  CHECK(phonebook->retrieve("Miss", "P")->get_id() == test13->get_id());
  CHECK(phonebook->retrieve("Jenny", "Blanc")->get_id() == test14->get_id());
  CHECK(phonebook->retrieve("Willy", "Wonka")->get_id() == test15->get_id());
  CHECK(phonebook->retrieve("Captain", "Pierce")->get_id() == test16->get_id());
  CHECK(phonebook->retrieve("Jerry", "Mouse")->get_id() == test17->get_id());
  CHECK(phonebook->retrieve("sir", "kitty")->get_id() == test18->get_id());
}

TEST_CASE("getKeys") {
  Dictionary *phonebook = new Dictionary();
  CHECK(phonebook->getKeys() == "\x1B[93mIndex\033[0m 1\nnullptr\n\x1B[93mIndex\033[0m 2\nnullptr\n\x1B[93mIndex\033[0m 3\nnullptr\n\x1B[93mIndex\033[0m 4\nnullptr\n\x1B[93mIndex\033[0m 5\nnullptr\n\x1B[93mIndex\033[0m 6\nnullptr\n\x1B[93mIndex\033[0m 7\nnullptr\n\x1B[93mIndex\033[0m 8\nnullptr\n\x1B[93mIndex\033[0m 9\nnullptr\n\x1B[93mIndex\033[0m 10\nnullptr\n");
  Person *test3 = new Person("andres", "castillo", 4);
  Person *test4 = new Person("johnny", "abshire", 5);
  Person *test5 = new Person("princess", "peach", 6);
  Person *test6 = new Person("mario", "figuero", 7);
  Person *test7 = new Person("luigi", "figuero", 8);
  Person *test8 = new Person("sir", "froggy", 9);
  phonebook->enter(test3);
  phonebook->enter(test4);
  phonebook->enter(test5);
  //std::cout << phonebook->getKeys() << '\n';
  CHECK(phonebook->getKeys() == "\x1B[93mIndex\033[0m 1\nnullptr\n\x1B[93mIndex\033[0m 2\npeach, princess-->abshire, johnny-->nullptr\n\x1B[93mIndex\033[0m 3\nnullptr\n\x1B[93mIndex\033[0m 4\nnullptr\n\x1B[93mIndex\033[0m 5\nnullptr\n\x1B[93mIndex\033[0m 6\nnullptr\n\x1B[93mIndex\033[0m 7\nnullptr\n\x1B[93mIndex\033[0m 8\nnullptr\n\x1B[93mIndex\033[0m 9\ncastillo, andres-->nullptr\n\x1B[93mIndex\033[0m 10\nnullptr\n");
  phonebook->enter(test6);
  phonebook->enter(test7);
  phonebook->enter(test8);
  //std::cout << phonebook->getKeys() << '\n';
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
  CHECK(phonebook->getKeys() == "\x1B[93mIndex\033[0m 1\nMouse, Jerry-->Wonka, Willy-->Blanc, Jenny-->Toliver, Don-->nullptr\n\x1B[93mIndex\033[0m 2\nPierce, Captain-->Xavier, Charles-->peach, princess-->abshire, johnny-->nullptr\n\x1B[93mIndex\033[0m 3\nnullptr\n\x1B[93mIndex\033[0m 4\nfroggy, sir-->nullptr\n\x1B[93mIndex\033[0m 5\nfiguero, luigi-->figuero, mario-->nullptr\n\x1B[93mIndex\033[0m 6\nP, Miss-->nullptr\n\x1B[93mIndex\033[0m 7\nkitty, sir-->Patron, El-->nullptr\n\x1B[93mIndex\033[0m 8\nnullptr\n\x1B[93mIndex\033[0m 9\ncastillo, andres-->nullptr\n\x1B[93mIndex\033[0m 10\nP, Mister-->nullptr\n");
  
}
