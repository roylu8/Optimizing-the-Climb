#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using cs225::HSLAPixel;
using cs225::PNG;

using namespace std;

/*
Function that we would need:

Graph constructor that takes file

have a the key be the index for each node

Another fucntion for weights

*/

class Graph
{

public:
  struct Edge
  {
    int index;
    int edge; // = luminance diff = edge weight
    // AdjEdge(int index, int luminance){
    //   Edge edgeup = index +;
    // }
  };
  Graph(PNG &image); // take in image & read luminance values
  int getLuminanceDifference(string direction, int i, int j);
  unordered_map<int, list<Edge>> adjacencyList; // index, (node, luminace difference btwn nodes)
  // getAdjacent(); // get adjacent vertices & weighted edges

private:
  vector<int> index;
  vector<int> luminance;
  int width;  // PNG width
  int height; // PNG height
};
