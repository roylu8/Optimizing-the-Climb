# Optimizing the Climb
### Contributors: 
* Jumana Schmidt (jumanas2)
* David Medina (davidrm3)
* Roy Lu (roylu2)
* Will Marshall (wjm5)

## Deliverables (Also in main branch)
* [Report](https://docs.google.com/document/d/1k2o9qTrFY8THpSg8V40tUWD97CVE1SHbEtfRH16D10I/edit?usp=sharing)
* [Presentation Video](https://www.youtube.com/watch?v=3xf8mlpjxbE&ab_channel=WilliamMarshall)
* [Presentation Slides](https://docs.google.com/presentation/d/1FTFySXaA5yO_qtD9PHo1kwkYB0B3H1eW/edit?usp=sharing&ouid=102768588260919984611&rtpof=true&sd=true)

## Overview
In this project, we intend to find the shortest and most energy efficient path from one point to a specified destination. There are countless reasons as to why this project is not only useful but also extremely practical. Our program will virtually be able to take a black and white image of almost any land-based terrain, a destination, and a starting point, and be able to find the path of shortest distance and least resistance. This program is applicable for hikers, rescuers, GPS, real estate developers, and more. To be able to demonstrate the full ability of our project, we’ll be using a picture of a mountainous terrain as our input, as there is more variation in height. Additionally, we’ll be referring to the person/thing trying to find the best path as the hiker, in our code and our project’s description, but in reality, anyone with any purpose could find use for this program.

## File description
Below are some brief descriptions of the files in our codebase.  Function descriptions can be found in the individual files:
* Graph: The graph file is used for constructing edges between nodes of image pixels. It also includes the code for Dijkstra's and A* algorithm to compute most efficient path.
* main : Where the tests for the algorithms are located.
* images : Where example heightmaps are located.

## How to run the program
The program can be ran by using the 'finalproject' executable:
```
make all
./finalproject
```
1) The user would first choose a heightmap from the folder `images` (enter number 1-6). If the custom option was chosen, an example entry would be: `images/custom.png`.

2) Afterwards, the user needs to pick an algorithm (enter number 1-2). 

3) Lastly, enter start pixel (1-max pixels of image) and end pixel (1-max pixels of image). Please make sure the start pixel is less than the end pixel and that pixel values are in range. Pixels are counted from left to right and continues after every row. The starting index is 1. For example, if the image was 20 by 20 pixels, the index would range from 1-400.
 
4) After computation, the result image would be saved at `images/result.png`.  

To end the program anytime, use `Ctrl+C`.

## Main function description
Our main function consists of several cases where users can find the most efficient path from a starting location to an ending location on a height map.  
The user will be able to see the results of Djikstra's algorithm and A* search algorithm.

## Test Description
Our tests can be ran with
```
make test
./test
```  
Our tests test the functionality of
* assigning index to image
* assigning luminnance to each index
* setting adjacency list size
* running Dijkstra's algorithm
* running A* search algorithm