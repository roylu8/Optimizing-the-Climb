#include <iostream>
#include "cs225/PNG.h"
#include <queue>
#include <vector>
#include <map>
#include "Graph.h"

using namespace cs225;

/*
resources

https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

https://www.javatpoint.com/cpp-dijkstra-algorithm-using-priority-queue#:~:text=C%2B%2B%20Dijkstra%20Algorithm%20using%20the%20priority%20queue%20In,source%20to%20the%20destination%20in%20an%20undirected%20graph.

*/

class Dijkstra
{
public:
    // ImagetoVertices(vector<vector<int>> image);
    vector<int> Dijkstras(int source, int destination);
    void Render();
    // int Dijkstra::getAdjacentEdgeWeight()

private:
    typedef int distance;
    std::unordered_map<int, distance> distances;
    std::unordered_map<int, int> previous;
    typedef pair<int, int> distanceNdindx;
    priority_queue<distanceNdindx> pq;
    std::unordered_map<int, bool> visited;
};