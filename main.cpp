#include <iostream>
#include <vector>
#include <unordered_map>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include "Graph.h"

using namespace std;

int main()
{
  cout << "Pick a test heightmap:" << endl;
  cout << "(1) 5 by 5 Obvious" << endl;
  cout << "(2) 5 by 5" << endl;
  cout << "(3) 20 by 20" << endl;
  cout << "(4) 461 by 445" << endl;
  cout << "(5) 700 by 700" << endl;
  cout << "(6) Custom Heightmap" << endl;
  cout << "Enter value: ";
  int value;
  PNG input;
  cin >> value;
  switch (value)
  {
  case 1:
    input.readFromFile("images/5by5obvious.png");
    break;
  case 2:
    input.readFromFile("images/5by5test.png");
    break;
  case 3:
    input.readFromFile("images/20by20test.png");
    break;
  case 4:
    input.readFromFile("images/461by445test.png");
    break;
  case 5:
    input.readFromFile("images/700by700test.png");
    break;
  case 6:
    cout << "\nEnter file location: ";
    string location;
    cin >> location;
    input.readFromFile(location);
    break;
  }
  Graph generatedGraph(input);

  cout << "\nPick an algorithm: " << endl;
  cout << "(1) Dijkstra's Algorithm" << endl;
  cout << "(2) A* Search Algorithm" << endl;
  cout << "Enter value: ";
  cin >> value;

  unsigned startValue, endValue;
  cout << "\nEnter starting pixel index: ";
  cin >> startValue;
  cout << "Enter ending pixel index: ";
  cin >> endValue;

  switch (value)
  {
  case 1:
    generatedGraph.Dijkstras(startValue - 1, endValue - 1);
    generatedGraph.Render(input);
    break;
  case 2:
    generatedGraph.A_Star(startValue - 1, endValue - 1);
    generatedGraph.A_StarRender(input);
    break;
  }

  cout << "\nResult image at location images/result.png" << endl;

  return 0;
}