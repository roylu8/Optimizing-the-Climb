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
PNG image;
image.readFromFile("images/700by700.png");
Graph testgraph(image);
testgraph.Dijkstras(0,300000);
testgraph.Render(image);
//image.writeToFile("images/461by451output.png");

//testgraph.Render(shortest);
    REQUIRE (0==0);
}