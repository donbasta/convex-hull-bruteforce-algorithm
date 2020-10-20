# convex-hull-bruteforce-algorithm

This project contains an algorithm written in C++ to create the convex hull of a set of points using brute force.
The brute force approach is to try all possible pairs of points and check whether they make up the boundary of the convex hull by counting the number of points in its left and right side. It is based on the observation that an edge is one of the edge of the convex hull if and only if it has zero points in one of its side. Of course, one must handle the corner cases such as when some of the points are collinear, coincident, etc.

The program shows the image of the convex hull as well, using an extension of matplotlib library in C++.

The project is done to fulfill task given in course IF2211 (Strategi Algoritma/Algorithm Strategy) at Institut Teknologi Bandung.

## Running the program

`g++ [SOURCE_CODE_FILE_NAME] -I/[PYTHON_VERSION_PATH] -l[PYTHON_VERSION]`

Below is the example command with file name main.cpp, object file name main, and using python 2.7:

`g++ -o main main.cpp -I/usr/include/python2.7 -lpython2.7`

Tested using python2 only, not tested with python3.

## Result

You only need to input the number of the points. The program will generate random points as many as the number you input.
Then, it will show the matplotlib image, and the duration taken for executing the brute force algorithm.

Here is the matplotlib image generated when running the program.

![image](/bin/tc1.png)

