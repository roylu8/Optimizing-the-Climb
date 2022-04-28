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

#include "Dijkstras.h"
#include<unordered_map>
using namespace std;

// Dijkstras::ImagetoVertices(vector<vector<int>> image){
//   // y+width_ +x
//   //vector<int> indices; // vertices' indices
//   int width = image.size();
//   int height = image[0].size();
//   int count = 0;
//   for(int i=0; i<width; i++){ //row
//     for(int j =0; j<height;j++){ //col
//       indices_[count] = image[i*width + j]; 
//       count++;
//     }
//   }
// }

Dijkstras::Dijkstras(int source, int destination){ // take in indices of source and d
    for(auto i : index){
        visited[index[i]] = false; // initialize visited bool to false
    }
    for(auto i : index){
        distances[index[i]] = 0x3f3f3f3f; // initialize distances to infinity except start
    }
    distances[source] = 0; // set source distance to zero

    pq.push(make_pair(source, 0)); // start priority queue

     while(pq.size() != 0){
        // get current node
        pq.pop();
        // get neighbors
        for(unsigned int i=0; i<adjacencyList.size(); i++){
            // if v

        }
        adjacencyList[]
  }
  
  
}

