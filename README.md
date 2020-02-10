# convex-hull-greedy-algorithm

This repo contains an algorithm written in C++ to create convex hull from a set of points based on brute force.
The brute force approach is to try all possible pairs of points and check whether they make up the boundary of the convex hull by counting the number of points in its left and right side.

The program show the result of the convex hull as well, using an extension of matplotlib library in C++.

The project is done to fulfill task given in course IF2211 (Strategi Algoritma/Algorithm Strategy) at Institut Teknologi Bandung.

## Running the program

`g++ [SOURCE_CODE_FILE_NAME] -I/[PYTHON_VERSION_PATH] -l[PYTHON_VERSION]`

Below is the example command with file name main.cpp, object file name main, and using python 2.7:

`g++ -o main main.cpp -I/usr/include/python2.7 -lpython2.7`

Tested using python2 only, not tested with python3

