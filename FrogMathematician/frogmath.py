#! /usr/bin/env python3
import numpy

## Solution to the frog mathematician problem.
#
# @param path The path to a file containing a grid of comma-separated integers.
# @return
# 1. The maximum sum of the optimal path
# 2. The starting point from the top row
# 3. The ending point on the bottom row
def frogmath(path):
	arr = numpy.loadtxt(path, dtype=int, delimiter=",")
	row,col = arr.shape
	st = numpy.empty(arr.shape, dtype=int)	#to find the starting point
	st[0,:] = numpy.arange(arr.shape[1])
	
	for i in range(1,arr.shape[0]):
		for j in range(arr.shape[1]):
			if j == 0:
				arr[i,j] += arr[i-1,j:j+2].max()
				st[i,j] = st[i-1, arr[i-1,j:j+2].argmax()]
			elif j == col-1:
				arr[i,j] += arr[i-1,j-1:j+1].max()
				st[i,j] = st[i-1, arr[i-1,j-1:j+1].argmax() + col-2]
			else:
				arr[i,j] += arr[i-1,j-1:j+2].max()
				st[i,j] = st[i-1, arr[i-1,j-1:j+2].argmax() +j-1]
				
	print("Maximum sum of optimal path is %d." %(arr[row-1,:].max()))
	print("Starting point is %d." %(st[row-1, arr[row-1,:].argmax()]+1))
	print("Ending point is %d." %(arr[row-1,:].argmax()+1))
	return arr[row-1,:].max(), st[row-1, arr[row-1,:].argmax()]+1, arr[row-1,:].argmax()+1
