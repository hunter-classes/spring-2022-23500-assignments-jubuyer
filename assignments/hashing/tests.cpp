#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>

#include "doctest.h"

TEST_CASE("hash") {
  CHECK("this" == "this");
}
