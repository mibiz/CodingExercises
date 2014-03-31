#! /usr/bin/env python3
import numpy

numpy.set_printoptions(linewidth=180)

def triangle(path):
    arr_prev = []
    with open(path) as f:
        for line in f:
            arr_curr = numpy.fromstring(line, dtype=int, sep=' ')
            for i in range(len(arr_curr)):
                if len(arr_curr) == 1:
                    pass
                else:
                    if i == 0:
                        arr_curr[i] += arr_prev[i]  #arr_curr[0] is only adjacent to arr_prev[0]
                    elif i == len(arr_curr)-1:
                        arr_curr[i] += arr_prev[i-1]    #arr_curr[<last>] is only adjacent to arr_prev[<last>]
                    else:
                        arr_curr[i] += arr_prev[i-1:i+1].max()  
            arr_prev = arr_curr
    print("The maximum is ", arr_prev.max(), sep='')
    return arr_prev.max()

