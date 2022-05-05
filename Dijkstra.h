#include <iostream>
#include "cs225/PNG.h"
#include <queue>
#include <vector>
#include <bits/stdc++.h>
#include <map>
#include <Edge>

using namespace std;
using namespace cs225;
using namespace vector;


/*
resources

https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

https://www.javatpoint.com/cpp-dijkstra-algorithm-using-priority-queue#:~:text=C%2B%2B%20Dijkstra%20Algorithm%20using%20the%20priority%20queue%20In,source%20to%20the%20destination%20in%20an%20undirected%20graph.

*/

class Dijkstras{
  public:

    //ImagetoVertices(vector<vector<int>> image);
    Dijkstras(int source, int destination);
    int Dijkstra::getAdjacentEdgeWeight()

    
  private:
    typedef int distance;
    unordered_map<int, distance> distances;
    unordered_map<int,int> previous;
    typedef pair<int,int> distanceNdindx;
    priority_queue<distanceNdindx> pq;
    unordered_map<int, bool> visited;

    
}