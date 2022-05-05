#include "../cs225/catch/catch.hpp"
#include "tests_helper.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

#include "../List.h"

using namespace cs225;


//
// Non-iterator Tests:
//
TEST_CASE("List::insertFront size", "[weight=1][part=1][valgrind]") {
    List<int> list;

    for (unsigned i = 0; i < 10; i++) { list.insertFront(i); }

    REQUIRE( 10 == list.size() );
}