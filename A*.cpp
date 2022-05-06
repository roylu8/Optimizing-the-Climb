
#include "A*.h"

A_star::heuristic(int source, int destination){
    /*
    function heuristic(node) =
    dx = abs(node.x - goal.x)
    dy = abs(node.y - goal.y)
    return D * (dx + dy) + (D2 - 2 * D) * min(dx, dy)
    */
}

vector<int> A_star::A_star(int source, int destination)
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
    pq.pop(); //move onto next in Q
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
        //new distance calcluation for heurstic should go somewhere here
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
