#!/usr/bin/python3
# 402 -- Hike on a Graph -- Problem code: HIKE

import sys

def readGraph(n):
    graph = []
    for i in range(n):
        line = sys.stdin.readline().strip()
        edges = line.split()
        row = []
        for j in range(n):
            row.append(ord(edges[j])-97)
        graph.append(row)
    return graph

def readFirst(line):
    p1 = -1
    p2 = -1
    p3 = -1
    nums = line.split()
    n = int(nums[0])
    if len(nums) == 4:
        [p1,p2,p3] = [int(i) for i in nums[1:]]
    return [n,p1,p2,p3]
    

def main():
    line = sys.stdin.readline().strip()
    [n,p1,p2,p3] = readFirst(line)
    while (n != 0):
        graph = readGraph(n)
        print (graph)

        line = sys.stdin.readline().strip()
        [n,p1,p2,p3] = readFirst(line)


if __name__ == '__main__':
    main()
                
    
