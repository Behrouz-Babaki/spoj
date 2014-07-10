#!/usr/bin/python3

import sys

line = sys.stdin.readline().strip()
numCases = int(line)

# TODO think about small n and k values

def countStrings(n,k):
    c0 = dict()
    c1 = dict()

    c0[(2,1)] = 0
    c0[(2,0)] = 2
    c1[(2,1)] = 1
    c1[(2,0)] = 1

    for i in range(2,k+1):
        c0[(2,i)] = 0
        c1[(2,i)] = 0

    for i in range(3,n+1):
        c0[(i,0)] = c0[(i-1,0)] + c1[(i-1,0)]
        c1[(i,0)] = c0[(i-1,0)]
        for j in range(1,k+1):
            c0[(i,j)] = c0[(i-1,j)] + c1[(i-1,j)]
            c1[(i,j)] = c0[(i-1,j)] + c1[(i-1,j-1)]

    return c0[(n,k)] + c1[(n,k)]

for i in range(numCases):
    nums = sys.stdin.readline().strip().split()
    [caseNo, n, k] = [int(i) for i in nums]
    print ("{} {}".format(caseNo, countStrings(n,k)))
