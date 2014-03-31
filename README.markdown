FizzBuzz
--------

The program prints the numbers from 1 to 100, one per line. But for multiples
of three it prints "Fizz" instead of the number, and for the multiples of five it prints "Buzz". 
For numbers which are multiples of both three and five it prints "FizzBuzz". This solution avoids 
using the modulo operator.

The Frog Mathematician Problem
------------------------------

Imagine that you are a frog and you want to find the best path to cross a river. 
You managed to map out the whole river, breaking it into a grid.
There are c possible points (c for "columns") to start your crossing and you will end up on 1 of c 
points on the other side. The river is r units to cross (r for "rows"). 
You give each unit an integer value between 1 and 1000, the greater the value, the easier it is to 
cross. Now that you have all the data you must find the best path. 
*This path is the one that has the highest score.*

Here is an example with c = 4 and r = 5 (crossing from top row to bottom):

	5		6		*13*	4
	9		*4*		1		3
	7		2		*10*	8
	12		*19*	2		19
	*22*	15		4		5

The maximum sum of the optimal path is:
	13 + 4 + 10 + 19 + 22 = 68.
The starting point is 3 and the ending point is 1.

From each unit there are 3 possible directions you can go. In the example below you start off with 
starting point 2 (value 6).  Watch out for values on the extreme left and right.

	5		*6*		7
	*10*	*5*		*12*

The input is a text file containing a grid of comma-separated integers. The program returns:

1. The maximum sum of the optimal path
2. The starting position from the top row
3. The ending point on  the bottom row

Triangle Puzzle
---------------
Similar to the [Frog Mathematician problem](#the-frog-mathematician-problem). 
Starting at the top of the triangle and moving to adjacent numbers on the row below, 
the maximum total from top to bottom is 27.

	      *5*
		*9*  6
	  4   *6*  8
	0   *7*  1   5

Therefore 5 + 9 + 6 + 7 = 27.

The program calculates the maximum total from top to bottom in a text file containing a triangle 
of space-separated integers.
