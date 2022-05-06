#include <iostream>
#include "cs225/PNG.h"
#include <queue>
#include <vector>
#include <map>
#include "Graph.h"


//similar Dijkstras but it gots a heurstic added to each node
//this is an extension of Dijkstras
//https://medium.com/@miguell.m/dijkstras-and-a-search-algorithm-2e67029d7749#:~:text=A%2A%20Search%20Algorithm%20is%20similar%20to%20Dijkstra%E2%80%99s%20in,the%20destination%2C%20and%20hopefully%20reducing%20the%20search%20space.
//overview of algorithm
//we need a heurstic funtion
//it should be a smell in maze

//we feed this search a node
//make that the starting node
//from there, the heurstic function should estimate the destination node

//need heurstic function:
//luminance difference is already used for building the map, so we cannot use that
//This acts as a precomputed heurstic
//

class A*
{
public:
    vector<int> Dijkstras(int source, int destination);
    void Render();
    //new heustic function based on

private:
    typedef int distance;
    std::unordered_map<int, distance> distances;
    std::unordered_map<int, int> previous;
    typedef pair<int, int> distanceNdindx;
    priority_queue<distanceNdindx> pq;
    std::unordered_map<int, bool> visited;
};