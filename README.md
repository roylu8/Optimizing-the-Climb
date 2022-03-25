# Hydraulic Erosion Simulation
### Contributors: 
* Jumana Schmidt (jumanas2)
* David Medina (davidrm3)
* Roy Lu (roylu2)
* Will Marshall (wjm5)

## Overview
Our project is intended to simulate erosion from water on a given terrain. The program should take in a black and white image of a heightmap of some terrain, and this image will essentially be our dataset. It will then be proccessed through our algorithm which will include traversing and processing the image. Some abstract amount of water will be placed on a pixel, and the algorithm will look at the surrounding nine pixels for the pixel with the lowest elevation or darkest color/brightness value. As the water follows this path, it darkens and changes the height value of the pixels it passes through (ie. eroding the path).