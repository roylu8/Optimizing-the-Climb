

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using cs225::HSLAPixel;
using cs225::PNG;

using namespace std;

class Graph
{

public:
  Graph(PNG image); // take in image & read luminance values
  int getLuminanceDifference(string direction, int i, int j);
  vector<int> Dijkstras(unsigned int source, unsigned int destination);
  void Render(PNG image);
  vector<int> getIndex();
  vector<int> getLuminance();
  int getSize();
  vector<vector<int>> getAdjacency();
  vector<int> A_Star(unsigned int source, unsigned int destination);
  int heuristic(int currindex, int destination);
  void A_StarRender(PNG image);

private:
  struct Edge
  {
    int index;
    int edge; // = luminance diff = edge weight
  };

  PNG image;
  int width;  // PNG width
  int height; // PNG height

  vector<int> index;
  vector<int> luminance;
  unsigned int numindex = index.size();
  unordered_map<int, list<Edge>> adjacencyList; // index, (node, luminace difference btwn nodes)

  std::unordered_map<int, int> distances;
  std::unordered_map<int, int> previous;
  typedef pair<int, int> distanceNdindx;
  priority_queue<distanceNdindx, vector<distanceNdindx>, greater<distanceNdindx>> pq;
  std::unordered_map<int, bool> visited;
  vector<int> solution;
  vector<int> astarsolution;
};