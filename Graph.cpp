#include "Graph.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using cs225::HSLAPixel;
using cs225::PNG;

// include cs 225 png class

Graph::Graph(PNG &image)
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
      luminance.push_back(pixel.l * 10);
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

  // for (auto &i : adjacencyList)
  // {
  //   std::cout << i.first << " ";
  //   for (Edge item : i.second)
  //   {
  //     std::cout << item.index << " ";
  //   }
  //   std::cout << endl;
  // }
  for (unsigned int i = 0; i < luminance.size(); i++)
  {
    std::cout << i << " " << luminance[i] << " " << std::endl;
  }

  PNG tester;
  tester.readFromFile("images/5by5.png");
  tester.getPixel(1, 2) = HSLAPixel(0, 1, 0.5, 1);
  tester.writeToFile("images/tester.png");
}

int Graph::getLuminanceDifference(string direction, int x, int y)
{
  int difference = 0;
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