#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>

#include "../Graph.h"
#include "../Dijkstra.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

#include "../cs225/catch/catch.hpp"


using namespace cs225;

TEST_CASE("test"){
std::cout << "testing"<<std::endl;
PNG poopopo;
poopopo.readFromFile("images/5by5.png");
Graph hewo(poopopo);
    REQUIRE (0==0);
}