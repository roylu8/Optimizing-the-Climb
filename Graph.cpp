#include "Graph.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using cs225::HSLAPixel;
using cs225::PNG;

// include cs 225 png class

Graph::Graph(PNG image){
  width = image.width();
  height = image.height();

  // get index and luminance vectors from image
  for(unsigned int i=0; i<width; i++){
    for(unsigned int j=0; j<height; j++){
      HSLAPixel & pixel = image.getPixel(i,j);
      
      index[i + j*width].push_back(i + j*width);
      luminance[i + j*image.width()].push_back(pixel.l);
    }
  }

  // create list of adjacent indices & edges
  for(int currindex=0; index.size(); currindex++){
      int x = currindex % width;
      int y = currindex / width;

      list<Edge> adjnodes;
      Edge edgeup;
      int upindex = x + (y-1)*width;
      Edge edgedown;
      int downindex = x + (y+1)*width;
      Edge edgeright;
      int rightindex = (x+1) + y*width;
      Edge edgeleft;
      int leftindex = (x-1) + y*width;
      
      // edge cases
      if(x==0 && y!=0 && y!=height){ // far left not corner
        // Edge edgeup;
        // Edge edgedown;
        // Edge edgeright;
        edgeup.index = upindex;
        edgeup.edge = getLuminanceDifference(string "up", x,y);
        edgedown.index = downindex;
        edgedown.edge = getLuminanceDifference(string "down", x,y);
        edgeright.index = rightindex;
        edgeright.edge = getLuminanceDifference(string "right", x,y);
        
        adjnodes.push_back(edgeup);
        adjnodes.push_back(edgedown);
        adjnodes.push_back(edgeright);
      }
      else if(y==0 && x!=0 && x!=width){ // far up
        // Edge edgedown;
        // Edge edgeright;
        // Edge edgeleft;
        edgedown.index = downindex;
        edgedown.edge = getLuminanceDifference(string "down", x,y);
        edgeleft.index = leftindex;
        edgeleft.edge = getLuminanceDifference(string "left", x,y);
        edgeright.index = rightindex;
        edgeright.edge = getLuminanceDifference(string"right", x,y);

        adjnodes.push_back(edgedown);
        adjnodes.push_back(edgeleft);
        adjnodes.push_back(edgeright);
        
      }
      else if(x==width && y!=0 && y!=height){ // far right
        // Edge edgeup;
        // Edge edgedown;
        // Edge edgeleft;
        edgeup.index = upindex;
        edgeup.edge = getLuminanceDifference(string "up", x,y);
        edgedown.index = downindex;
        edgedown.edge = getLuminanceDifference(string "down", x,y);
        edgeleft.index = leftindex;
        edgeleft.edge = getLuminanceDifference(string "left", x,y);
        
        adjnodes.push_back(edgeup);
        adjnodes.push_back(edgedown);
        adjnodes.push_back(edgeleft);
      }
      else if(y==height && x!=width && x!=0){  // far down
        Edge edgeup;
        Edge edgeleft;
        Edge edgeright;
        edgeup.index = upindex;
        edgeup.edge = getLuminanceDifference(string "up", x,y);
        edgeright.index = rightindex;
        edgeright.edge = getLuminanceDifference(string"right", x,y);
        edgeleft.index = leftindex;
        edgeleft.edge = getLuminanceDifference(string "left", x,y);

        adjnodes.push_back(edgeup);
        adjnodes.push_back(edgeleft);
        adjnodes.push_back(edgeright);
      }
      else if(x==0 && y==0){ // upper left corner
        // Edge edgedown;
        // Edge edgeright;
        edgedown.index = downindex;
        edgedown.edge = getLuminanceDifference(string "down", x,y);
        edgeright.index = rightindex;
        edgeright.edge = getLuminanceDifference(string"right", x,y);

        adjnodes.push_back(edgedown);
        adjnodes.push_back(edgeright);
      }
      else if(x==height && y==width){ // lower right corner
        // Edge edgeup;
        // Edge edgeleft;
        edgeup.index = upindex;
        edgeup.edge = getLuminanceDifference(string "up", x,y);
        edgeleft.index = leftindex;
        edgeleft.edge = getLuminanceDifference(string "left", x,y);

        adjnodes.push_back(edgeup);
        adjnodes.push_back(edgeleft);
      }
      else if(x==0 && y==width){ // upper right
        // Edge edgedown;
        // Edge edgeleft;
        edgedown.index = downindex;
        edgedown.edge = getLuminanceDifference(string "down", x,y);
        edgeleft.index = leftindex;
        edgeleft.edge = getLuminanceDifference(string "left", x,y);

        adjnodes.push_back(edgedown);
        adjnodes.push_back(edgeleft);
      }
      else if(y==height && x==0){ // lower left
        // Edge edgeup;
        // Edge edgeright;
        edgeup.index = upindex;
        edgeup.edge = getLuminanceDifference(string "up", x,y);
        edgeright.index = rightindex;
        edgeright.edge = getLuminanceDifference(string"right", x,y);

        adjnodes.push_back(edgeup);
        adjnodes.push_back(edgeright);
      }
      else {
        // Edge edgeup;
        // Edge edgedown;
        // Edge edgeright;
        // Edge edgeleft;
        edgeup.index = upindex;
        edgeup.edge = getLuminanceDifference(string("up"), x,y);
        adjnodes.push_back(edgeup);
        edgedown.index = downindex;
        edgedown.edge = getLuminanceDifference(string("down"), x,y);
        adjnodes.push_back(edgedown);
        edgeright.index = rightindex;
        edgeright.edge = getLuminanceDifference(string("right"), x,y);
        adjnodes.push_back(edgeright);
        edgeleft.index = leftindex;
        edgeleft.edge = getLuminanceDifference(string "left", x,y);
        adjnodes.push_back(edgeleft);
      }  
      adjacencyList[x + y*width] = adjnodes;
    }
  }
}

int Graph::getLuminanceDifference(string direction, int x, int y){
  int difference = 0;
  string "up"
  if(direction == "up"){
    difference = luminance[x + (y-1)*width] - luminance[x + y*width];
    if(difference < 0){
      difference *= -1;
    }
    return difference;
  }
  else if(direction == "down"){
    difference = luminance[x + (y+1)*width)] - luminance[x + y*width];
    if(difference < 0){
      difference *= -1;
    }
    return difference;
  }
  else if(direction == "left"){
    difference = luminance[(x-1) + y*width] - luminance[x + y*width];
    if(difference < 0){
      difference *= -1;
    }
    return difference;
  }
  else if (direction == "right"){
    difference = luminance[(x+1) + y*width] - luminance[x + y*width];
    if(difference < 0){
      difference *= -1;
    }
    return difference;
  }
  else{
    return 0;
  }
}
  