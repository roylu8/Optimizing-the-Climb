/*
Dijkstra(Graph, source, destination):

  initialize distances  // initialize tentative distance value
  initialize previous   // initialize a map that maps current node -> its previous node
  initialize priority_queue   // initialize the priority queue
  initialize visited

  while the top of priority_queue is not destination:
      get the current_node from priority_queue
      for neighbor in current_node's neighbors and not in visited:
          if update its neighbor's distances:
              previous[neighbor] = current_node
      save current_node into visited

  extract path from previous
  return path and distance
*/

#include "Dijkstra.h"

vector<int> Dijkstra::Dijkstras(int source, int destination)
{ // take in indices of source and d
  for (auto &v : visited)
  {
    v = false; // initialize visited bool to false
  }
  for (auto &i : distances)
  {
    i = 0x3f3f3f3f; // initialize distances to infinity except start
  }
  distances[source] = 0; // set source distance to zero
  int newdist = 0;

  pq.push(make_pair(source, 0)); // start priority queue

  while (pq.size() != 0)
  {
    // get current node
    int currindex = pq.top().first;
    pq.pop();
    // check if node is already visited
    if (visited[currindex] == true)
    {
      break;
    } // continue??
    // set as visited
    visited[currindex] = true; // if curr index visted break
    // get neighbors
    for (unsigned int i = currindex; i < adjanceyList.size(); i++)
    {
      for (unsigned int neighbor = 0; neighbor < adjacencyList[currindex].size(); neighbor++)
      {
        list<Edge> temp = adjacencyList[currindex];
        int neighborindex = temp[neighbor].index;

        if (visited[neighborindex] == true)
        {
          continue; // if visited go to next neighbor
        }
        else
        {
          int edgeweight = temp[neighbor].edge;
          newdist = distances[currindex] + edgeweight;

                    if(newdist < dist[neighborindex]])
                    {
                        distances[neighborindex]] = newdist;
                        pq.push(make_pair(distances[neighborindex], neighborindex));
                        previous[neighborindex] = currindex;
                    }
        }
      }
    }
    vector<int> solution;

    int curr = destination;
    solution.push_back(curr);
    while (curr != source)
    {
      int prev = previous[curr];
      solution.push_back(prev);
      curr = prev;
    }
    std::reverse(solution.begin(), solution.end());
    return solution;
  }
}
