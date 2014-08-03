#!/usr/bin/python3
# 8129 -- Sky Lift -- Problem code: SKY

import sys
import heapq

h = []
nodes = {}
visited = set()

def addNode (node , priority):
	if node in nodes:
		entry = nodes [node]
		if entry[0] > priority:
			nodes.pop(node)
			entry[-1] = 'REMOVED'
	else:
		entry = [priority, node]
		nodes [node] = entry
		heapq.heappush (h, entry)

def popNode ():
    while h:
        priority, node = heapq.heappop(h)
        if node is not 'REMOVED':
            nodes.pop(node)
            return node , priority
    raise KeyError ('pop from an empty queue')

def height (x,y):
    global N, A, B, C
    return (((x-1)*N+y-1)*A + B) % C

def main():
    global N, A, B, C
    line = sys.stdin.readline().strip()
    N = int(line);
    line = sys.stdin.readline()
    [xa, ya, xb, yb] = [int(i) for i in line.split()]
    line = sys.stdin.readline()
    [A, B, C] = [int(i) for i in line.split()]
    heightMap = {}
    for x in range(1,N+1):
        for y in range(1,N+1):
            heightMap [x,y] = (((x-1)*N+y-1)*A + B) % C 
    za = heightMap[xa,ya]
    zb = heightMap[xb,yb]

    bestCost = za + zb
    addNode ((xa,ya,za), 0)
    while True:
        try:
            node , cost = popNode()
            visited.add(node)
            if node is (xb, yb, zb) and cost < bestCost:
                bestCost = cost

            if cost < bestCost:
                (x,y,z) = node
                if x > 1 and heightMap[x-1,y] >= z and not (x-1, y, z) in visited:
                    addNode((x-1, y, z), cost)
                if x < N and heightMap[x+1, y] >= z and not (x+1, y, z) in visited:
                    addNode ((x+1, y, z), cost)
                if y > 1 and heightMap[x, y-1] >= z and not (x, y-1, z) in visited:
                    addNode((x, y-1, z), cost)
                if y < N and heightMap[x, y+1] >= z and not (x, y+1, z) in visited:
                    addNode((x, y+1, z), cost)
                if z > 1 and not (x, y, z-1) in visited:
                    addNode((x, y, z-1), cost+1)
                if z < heightMap[x,y] and not (x, y, z+1) in visited:
                    addNode((x,y,z+1), cost+1)

        except KeyError: 
            break
    print (bestCost)
        
if __name__ == '__main__':
    main()
                
    
