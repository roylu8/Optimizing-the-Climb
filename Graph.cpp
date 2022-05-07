#include "Graph.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <cmath>

using cs225::HSLAPixel;
using cs225::PNG;

// include cs 225 png class
Graph::Graph(PNG image)
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
      edgedown.index = downindex;
      edgedown.edge = getLuminanceDifference("down", x, y);
      edgeright.index = rightindex;
      edgeright.edge = getLuminanceDifference("right", x, y);

      adjnodes.push_back(edgedown);
      adjnodes.push_back(edgeright);
    }
    else if (x == height - 1 && y == width - 1)
    { // lower right corner
      edgeup.index = upindex;
      edgeup.edge = getLuminanceDifference("up", x, y);
      edgeleft.index = leftindex;
      edgeleft.edge = getLuminanceDifference("left", x, y);

      adjnodes.push_back(edgeup);
      adjnodes.push_back(edgeleft);
    }
    else if (x == width - 1 && y == 0)
    { // upper right corner
      edgedown.index = downindex;
      edgedown.edge = getLuminanceDifference("down", x, y);
      edgeleft.index = leftindex;
      edgeleft.edge = getLuminanceDifference("left", x, y);

      adjnodes.push_back(edgedown);
      adjnodes.push_back(edgeleft);
    }
    else if (y == height - 1 && x == 0)
    { // lower left corner
      edgeup.index = upindex;
      edgeup.edge = getLuminanceDifference("up", x, y);
      edgeright.index = rightindex;
      edgeright.edge = getLuminanceDifference("right", x, y);

      adjnodes.push_back(edgeup);
      adjnodes.push_back(edgeright);
    }
    else
    { // middle
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
}

int Graph::getLuminanceDifference(string direction, int x, int y)
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

vector<int> Graph::Dijkstras(unsigned int source, unsigned int destination){ // take in indices of source and d 
  for(unsigned int i=0; i<numindex; i++){
    visited[i] = false; // initialize visited bool to false
  }
  distances[source] = 0; // set source distance to zero
  int newdist = 0;

  pq.push(make_pair(0, source)); // start priority queue

  while(pq.size() != 0){
    // get current node
    unsigned int currindex = pq.top().second;
    pq.pop();

    list<Edge> temp = adjacencyList[currindex];
    for(list<Edge>::iterator it = temp.begin(); it !=temp.end(); ++it){ 
      int neighborindex = it->index;
      if(visited[neighborindex] == true){
        continue; // if visited go to next neighbor
      }
      else{
        int edgeweight = it->edge;
        newdist = distances[currindex] + edgeweight;
        if(distances.find(neighborindex) == distances.end() || newdist < distances[neighborindex]){
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

void Graph::Render(PNG image, PNG output){
    for(unsigned int i=0; i<solution.size(); i++){
      int x = solution[i] % width;
      int y = solution[i] / width;
      HSLAPixel & pixel = image.getPixel(x,y);
      pixel = HSLAPixel(0, 1, 0.5, 1);
    }
    output.writeToFile("images/20by20testrender.png");
}

int Graph::heuristic(int currindex, int destination){
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
    int dx = abs(x - x_d);
    int dy = abs(y - y_d);
    return D*(dx+dy);

}

vector<int> Graph::A_Star(unsigned int source, unsigned int destination){ // take in indices of source and d 
  for(unsigned int i=0; i<numindex; i++){
    visited[i] = false; // initialize visited bool to false
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
    // if(visited[currindex] == true){continue;} // if curr index visted break
    // visited[currindex] = true; // set current node as visited
    
    //for(auto i = adjacencyList.begin(); i!=adjacencyList.end(); i++){
      list<Edge> temp = adjacencyList[currindex];
      // if(currindex == destination){
      //   break;
      // }
      for(list<Edge>::iterator it = temp.begin(); it !=temp.end(); ++it){ 
        int neighborindex = it->index;
        //cout << neighborindex << endl;
        if(visited[neighborindex] == true){
          continue; // if visited go to next neighbor
        }
        else{
          int edgeweight = it->edge;
          //cout << "Edgeweight" << " " << edgeweight << endl;
          newdist = distances[currindex] + edgeweight;
         // cout << "newdist:" << " " << edgeweight << endl;
         // cout << "diasfindneighbor" << " " << distances.find(neighborindex) << endl;
          

          if(distances.find(neighborindex) == distances.end() || newdist < distances[neighborindex]){
            //cout << "nindex" << " " << neighborindex << endl;
            distances[neighborindex] = newdist;
            double f = heuristic(neighborindex, destination) + newdist;
            pq.push(make_pair(f, neighborindex));
            previous[neighborindex] = currindex;
            cout << heuristic(neighborindex, destination) << endl;
          }
          //cout<< newdist << " " << distances[neighborindex]<< " " << neighborindex << endl;
        }
        //if(currindex == destination){break;}
      }
      visited[currindex] = true;
    }
    // for(unsigned int w=0; w<previous.size(); w++){
    //   cout << previous[w] << endl;
    // }
    unsigned int curr = destination;
    astarsolution.push_back(curr);
    while(curr != source){
      unsigned int prev = previous[curr];
      astarsolution.push_back(prev);
      curr = prev;
    }

  std::reverse(solution.begin(), astarsolution.end());
  for(unsigned int i=0; i<solution.size(); i++){
    std::cout<< astarsolution[i] << " " << std::endl;
  }
  return astarsolution;
}