#include "Graph.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <cmath>

using cs225::HSLAPixel;
using cs225::PNG;

// include cs 225 png class
Graph::Graph_A(PNG image)
{
  width = image.width();
  height = image.height();

  // get index and luminance vectors from image
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      HSLAPixel &pixel = image.getPixel(j, i);

      index.push_back(i * width + j);
      int currlum = abs((pixel.l * 10)-10);
      luminance.push_back(currlum);
    }
  }
  
  // create list of adjacent indices & edges
  for (unsigned int currindex = 0; currindex < index.size(); currindex++)
  {
    int x = currindex % width;
    int y = currindex / width;

    list<Edge> adjnodes;
    Edge edgeup;
    int upindex = x + (y - 1) * width;
    Edge edgedown;
    int downindex = x + (y + 1) * width;
    Edge edgeright;
    int rightindex = (x + 1) + y * width;
    Edge edgeleft;
    int leftindex = (x - 1) + y * width;

    // edge cases

    if (x == 0 && y != 0 && y != height - 1)
    { // far left
      // Edge edgeup;
      // Edge edgedown;
      // Edge edgeright;
      edgeup.index = upindex;
      edgeup.edge = getLuminanceDifference("up", x, y);
      edgedown.index = downindex;
      edgedown.edge = getLuminanceDifference("down", x, y);
      edgeright.index = rightindex;
      edgeright.edge = getLuminanceDifference("right", x, y);

      adjnodes.push_back(edgeup);
      adjnodes.push_back(edgedown);
      adjnodes.push_back(edgeright);
    }
    else if (y == 0 && x != 0 && x != width - 1)
    { // far up
      // Edge edgedown;
      // Edge edgeright;
      // Edge edgeleft;
      edgedown.index = downindex;
      edgedown.edge = getLuminanceDifference("down", x, y);
      edgeleft.index = leftindex;
      edgeleft.edge = getLuminanceDifference("left", x, y);
      edgeright.index = rightindex;
      edgeright.edge = getLuminanceDifference("right", x, y);

      adjnodes.push_back(edgedown);
      adjnodes.push_back(edgeleft);
      adjnodes.push_back(edgeright);
    }
    else if (x == width - 1 && y != 0 && y != height - 1)
    { // far right
      // Edge edgeup;
      // Edge edgedown;
      // Edge edgeleft;
      edgeup.index = upindex;
      edgeup.edge = getLuminanceDifference("up", x, y);
      edgedown.index = downindex;
      edgedown.edge = getLuminanceDifference("down", x, y);
      edgeleft.index = leftindex;
      edgeleft.edge = getLuminanceDifference("left", x, y);

      adjnodes.push_back(edgeup);
      adjnodes.push_back(edgedown);
      adjnodes.push_back(edgeleft);
    }
    else if (y == height - 1 && x != width - 1 && x != 0)
    { // far down
      Edge edgeup;
      Edge edgeleft;
      Edge edgeright;
      edgeup.index = upindex;
      edgeup.edge = getLuminanceDifference("up", x, y);
      edgeright.index = rightindex;
      edgeright.edge = getLuminanceDifference("right", x, y);
      edgeleft.index = leftindex;
      edgeleft.edge = getLuminanceDifference("left", x, y);

      adjnodes.push_back(edgeup);
      adjnodes.push_back(edgeleft);
      adjnodes.push_back(edgeright);
    }
    else if (x == 0 && y == 0)
    { // upper left corner
      // Edge edgedown;
      // Edge edgeright;
      edgedown.index = downindex;
      edgedown.edge = getLuminanceDifference("down", x, y);
      edgeright.index = rightindex;
      edgeright.edge = getLuminanceDifference("right", x, y);

      // cout << edgeright.index << " " << edgeright.edge << endl;

      adjnodes.push_back(edgedown);
      adjnodes.push_back(edgeright);
    }
    else if (x == height - 1 && y == width - 1)
    { // lower right corner
      // Edge edgeup;
      // Edge edgeleft;
      edgeup.index = upindex;
      edgeup.edge = getLuminanceDifference("up", x, y);
      edgeleft.index = leftindex;
      edgeleft.edge = getLuminanceDifference("left", x, y);

      adjnodes.push_back(edgeup);
      adjnodes.push_back(edgeleft);
    }
    else if (x == width - 1 && y == 0)
    { // upper right corner
      // Edge edgedown;
      // Edge edgeleft;
      edgedown.index = downindex;
      edgedown.edge = getLuminanceDifference("down", x, y);
      edgeleft.index = leftindex;
      edgeleft.edge = getLuminanceDifference("left", x, y);

      adjnodes.push_back(edgedown);
      adjnodes.push_back(edgeleft);
    }
    else if (y == height - 1 && x == 0)
    { // lower left corner
      // Edge edgeup;
      // Edge edgeright;
      edgeup.index = upindex;
      edgeup.edge = getLuminanceDifference("up", x, y);
      edgeright.index = rightindex;
      edgeright.edge = getLuminanceDifference("right", x, y);

      adjnodes.push_back(edgeup);
      adjnodes.push_back(edgeright);
    }
    else
    { // middle
      // Edge edgeup;
      // Edge edgedown;
      // Edge edgeright;
      // Edge edgeleft;
      edgeup.index = upindex;
      edgeup.edge = getLuminanceDifference("up", x, y);
      adjnodes.push_back(edgeup);
      edgedown.index = downindex;
      edgedown.edge = getLuminanceDifference("down", x, y);
      adjnodes.push_back(edgedown);
      edgeright.index = rightindex;
      edgeright.edge = getLuminanceDifference("right", x, y);
      adjnodes.push_back(edgeright);
      edgeleft.index = leftindex;
      edgeleft.edge = getLuminanceDifference("left", x, y);
      adjnodes.push_back(edgeleft);
    }
    adjacencyList[x + y * width] = adjnodes;
  }

  // for(auto i = adjacencyList.begin(); i!=adjacencyList.end(); i++){
  //   list<Edge> temp = adjacencyList[0];
  //   for(list<Edge>::iterator it = temp.begin(); it !=temp.end(); ++it){
  //     cout << it->edge << " " << endl;
  //   }
  // }

  // for (auto &i : adjacencyList)
  // {
  //   //std::cout << i.first << " ";
  //   for (Edge item : i.second)
  //   {
  //     std::cout << item.edge << " ";
  //   }
  //   std::cout << endl;
  //   break;
  // }
  // for (unsigned int i = 0; i < luminance.size(); i++)
  // {
  //   std::cout << i << " " << luminance[i] << " " << std::endl;
  // }

  // PNG tester;
  // tester.readFromFile("images/5by5.png");
  // tester.getPixel(1, 2) = HSLAPixel(0, 1, 0.5, 1);
  // tester.writeToFile("images/tester.png");
}

int Graph_A::getLuminanceDifference(string direction, int x, int y)
{
  int difference;
  if (direction == "up")
  {
    difference = luminance[x + (y - 1) * width] - luminance[x + y * width];
    if (difference < 0)
    {
      difference *= -1;
    }
    return difference;
  }
  else if (direction == "down")
  {
    difference = luminance[x + (y + 1) * width] - luminance[x + y * width];
    if (difference < 0)
    {
      difference *= -1;
    }
    return difference;
  }
  else if (direction == "left")
  {
    difference = luminance[(x - 1) + y * width] - luminance[x + y * width];
    if (difference < 0)
    {
      difference *= -1;
    }
    return difference;
  }
  else if (direction == "right")
  {
    difference = luminance[(x + 1) + y * width] - luminance[x + y * width];
    if (difference < 0)
    {
      difference *= -1;
    }
    return difference;
  }
  else
  {
    return 0;
  }
}

A_star::heuristic(int currindex, int destination){
    /*
    back to 4d
    function heuristic(node) =
    dx = abs(node.x - goal.x)
    dy = abs(node.y - goal.y)
    return D *(dx+dy);
    */
    //D=1
    int x = currindex % width;
    int y = currindex / width;
    //nodes are the vertices we are comparing
    //current idex vs neightbor
    int x_d = destination % width;
    int y_d = destination / width; 

    //figure out D. Either 0 or 1;
    int D=1;
    dx = abs(x - x_d);
    dy = abs(y - y_d);
    return D*(dx+dy);

}
vector<int> Graph_A::A_star(unsigned int source, unsigned int destination){ // take in indices of source and d 
  const int INF = 0x3f3f3f3f;
  for(unsigned int i=0; i<numindex; i++){
    visited[i] = false; // initialize visited bool to false
  }
  for(unsigned int j=0; j<index.size(); j++){
    distances[j] = INF; // initialize distances
  }
  distances[source] = 0; // set source distance to zero
  int newdist = 0;

  pq.push(make_pair(0, source)); // start priority queue

  while(pq.size() != 0){
    // get current node
    unsigned int currindex = pq.top().second;
    //cout<< currindex << endl;
    pq.pop();
    // check if node is already visited
    
      list<Edge> temp = adjacencyList[currindex];

      for(list<Edge>::iterator it = temp.begin(); it !=temp.end(); ++it){ 
        int neighborindex = it->index;
        if(visited[neighborindex] == true){
          continue; // if visited go to next neighbor
        }
        else{
          int edgeweight = it->edge;
          newdist = distances[currindex] + edgeweight + heuristic(unsigned int source, unsigned int destination);
      
          if(distances.find(neighborindex) == distances.end() || newdist < distances[neighborindex]){
            cout << neighborindex << " " << edgeweight << " " << newdist << endl;
            distances[neighborindex] = newdist;
            pq.push(make_pair(distances[neighborindex], neighborindex));
            previous[neighborindex] = currindex;
          }
          
        }
      }
      visited[currindex] = true;
    }
    unsigned int curr = destination;
    solution.push_back(curr);
    while(curr != source){
      unsigned int prev = previous[curr];
      solution.push_back(prev);
      curr = prev;
    }

  std::reverse(solution.begin(), solution.end());
  for(unsigned int i=0; i<solution.size(); i++){
    std::cout<< solution[i] << " " << std::endl;
  }
  return solution;
}


// void Graph::Render(vector<int> shortestpath){
//     PNG rendered;
//     rendered.readFromFile("5by5.png");
    
//     for(unsigned int i=0; i<shortestpath.size(); i++){
//       int x = i % width;
//       int y = i / width;
//       HSLAPixel & pixel = rendered.getPixel(x,y);
//       pixel = HSLAPixel(0, 1, 0.5, 1);
//     }
//     rendered.writeToFile("5by5render.png");

//     // for(unsigned int i=0; i<shortestpath.size(); i++){
//     //   std::cout<< shortestpath[i] << " " << std::endl;
//     // }
// }