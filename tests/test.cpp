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
image.readFromFile("images/20by20test.png");
PNG output;
output.readFromFile("images/20by20test.png");
Graph testgraph(image);
testgraph.Dijkstras(0,399);
//testgraph.A_Star(0,399);
testgraph.Render(image, output);
//output.writeToFile("images/20by20testrender.png");
//image.writeToFile("images/461by451output.png");

//testgraph.Render(shortest);
    REQUIRE (0==0);
}