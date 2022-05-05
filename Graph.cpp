#include "Graph.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using cs225::HSLAPixel;
using cs225::PNG;

// include cs 225 png class

Graph::Graph(PNG image){

  // get index and luminance vectors from image
  for(unsigned int i=0; i<image.width(); i++){
    for(unsigned int j=0; j<image.height(); j++){
      HSLAPixel & pixel = image.getPixel(i,j);
      
      index[i][j].push_back(i + j*image.width());
      luminance[i][j].push_back(pixel.l);
    }
  }

  // create list of adjacent indices & edges
  for(int i=0; index.size(); i++){
    for(int j=0; j<index[i].size(); j++){
      int width = image.width();
      int height = image.height();
      // int curr_luminance = luminance[i][j];
      list<Edge> adjnodes;
      Edge edgeup;
      int upindex = i + (j-1)*image.width();
      Edge edgedown;
      int downindex = i + (j+1)*image.width();
      Edge edgeright;
      int rightindex = (i+1) + j*image.width();
      Edge edgeleft;
      int leftindex = (i-1) + j*image.width();
      
      // edge cases
      if(i==0 && j!=0){ // far left
        // Edge edgeup;
        // Edge edgedown;
        // Edge edgeright;
        edgeup.index = upindex;
        edgeup.edge = getLuminanceDifference(string "up", i,j);
        edgedown.index = downindex;
        edgedown.edge = getLuminanceDifference(string "down", i,j);
        edgeright.index = rightindex;
        edgeright.edge = getLuminanceDifference(string "right", i,j);
        
        adjnodes.push_back(edgeup);
        adjnodes.push_back(edgedown);
        adjnodes.push_back(edgeright);
      }
      else if(j==0 && i!=0){ // far up
        // Edge edgedown;
        // Edge edgeright;
        // Edge edgeleft;
        edgedown.index = downindex;
        edgedown.edge = getLuminanceDifference(string "down", i,j);
        edgeleft.index = leftindex;
        edgeleft.edge = getLuminanceDifference(string "left", i,j);
        edgeright.index = rightindex;
        edgeright.edge = getLuminanceDifference(string"right", i,j);

        adjnodes.push_back(edgedown);
        adjnodes.push_back(edgeleft);
        adjnodes.push_back(edgeright);
        
      }
      else if(i==image.width() && j!=image.height()){ // far right
        // Edge edgeup;
        // Edge edgedown;
        // Edge edgeleft;
        edgeup.index = upindex;
        edgeup.edge = getLuminanceDifference(string "up", i,j);
        edgedown.index = downindex;
        edgedown.edge = getLuminanceDifference(string "down", i,j);
        edgeleft.index = leftindex;
        edgeleft.edge = getLuminanceDifference(string "left", i,j);
        
        adjnodes.push_back(edgeup);
        adjnodes.push_back(edgedown);
        adjnodes.push_back(edgeleft);
      }
      else if(j==image.height() && i!=image.width()){  // far down
        Edge edgeup;
        Edge edgeleft;
        Edge edgeright;
        edgeup.index = upindex;
        edgeup.edge = getLuminanceDifference(string "up", i,j);
        edgeright.index = rightindex;
        edgeright.edge = getLuminanceDifference(string"right", i,j);
        edgeleft.index = leftindex;
        edgeleft.edge = getLuminanceDifference(string "left", i,j);

        adjnodes.push_back(edgeup);
        adjnodes.push_back(edgeleft);
        adjnodes.push_back(edgeright);
      }
      else if(i==0 && j==0){ // upper left corner
        // Edge edgedown;
        // Edge edgeright;
        edgedown.index = downindex;
        edgedown.edge = getLuminanceDifference(string "down", i,j);
        edgeright.index = rightindex;
        edgeright.edge = getLuminanceDifference(string"right", i,j);

        adjnodes.push_back(edgedown);
        adjnodes.push_back(edgeright);
      }
      else if(j==image.height() && i==image.width()){ // lower right corner
        // Edge edgeup;
        // Edge edgeleft;
        edgeup.index = upindex;
        edgeup.edge = getLuminanceDifference(string "up", i,j);
        edgeleft.index = leftindex;
        edgeleft.edge = getLuminanceDifference(string "left", i,j);

        adjnodes.push_back(edgeup);
        adjnodes.push_back(edgeleft);
      }
      else if(j==0 && i==image.width()){ // upper right
        // Edge edgedown;
        // Edge edgeleft;
        edgedown.index = downindex;
        edgedown.edge = getLuminanceDifference(string "down", i,j);
        edgeleft.index = leftindex;
        edgeleft.edge = getLuminanceDifference(string "left", i,j);

        adjnodes.push_back(edgedown);
        adjnodes.push_back(edgeleft);
      }
      else if(j==image.height() && i==0){ // lower left
        // Edge edgeup;
        // Edge edgeright;
        edgeup.index = upindex;
        edgeup.edge = getLuminanceDifference(string "up", i,j);
        edgeright.index = rightindex;
        edgeright.edge = getLuminanceDifference(string"right", i,j);

        adjnodes.push_back(edgeup);
        adjnodes.push_back(edgeright);
      }
      else {
        // Edge edgeup;
        // Edge edgedown;
        // Edge edgeright;
        // Edge edgeleft;
        edgeup.index = upindex;
        edgeup.edge = getLuminanceDifference(string "up", i,j);
        adjnodes.push_back(edgeup);
        edgedown.index = downindex;
        edgedown.edge = getLuminanceDifference(string "down", i,j);
        adjnodes.push_back(edgedown);
        edgeright.index = rightindex;
        edgeright.edge = getLuminanceDifference(string"right", i,j);
        adjnodes.push_back(edgeright);
        edgeleft.index = leftindex;
        edgeleft.edge = getLuminanceDifference(string "left", i,j);
        adjnodes.push_back(edgeleft);
      }  
      adjacencyList[i] = adjnodes;
    }
  }
}

int Graph::getLuminanceDifference(string direction, int i, int j){
  int difference = 0;
  if(direction == "up"){
    difference = luminance[i][j-1] - luminance[i][j];
    if(difference < 0){
      difference *= -1;
    }
    return difference;
  }
  else if(direction == "down"){
    difference = luminance[i][j+1] - luminance[i][j];
    if(difference < 0){
      difference *= -1;
    }
    return difference;
  }
  else if(direction == "left"){
    difference = luminance[i-1][j] - luminance[i][j];
    if(difference < 0){
      difference *= -1;
    }
    return difference;
  }
  else if (direction == "right"){
    difference = luminance[i+1][j] - luminance[i][j];
    if(difference < 0){
      difference *= -1;
    }
    return difference;
  }
  else{
    return 0;
  }
}
  