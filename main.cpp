#include <iostream>
#include <vector>
#include <unordered_map>

#include "Graph.h"

using namespace std;

int main()
{
  PNG input, inputA;
  input.readFromFile("images/700by700test.png");  // enter heightmap file
  inputA.readFromFile("images/700by700test.png"); // enter heightmap file
  Graph generatedGraph(input);
  Graph generatedGraphA(input);
  generatedGraph.Dijkstras(0, 290000);  // enter starting to ending pixel
  generatedGraph.Render(input);         // renders result to result.png
  generatedGraphA.A_Star(0, 290000);    // enter starting to ending pixel
  generatedGraphA.A_StarRender(inputA); // renders result to resultA.png

  return 0;
}