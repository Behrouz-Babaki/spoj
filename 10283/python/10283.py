#!/usr/bin/python
# 10283 -- ALL IZZ WELL -- Problem code: ALLIZWEL

import sys

def search (matrix, used, cell, position):
	if position is 9:
		return True

	used.add(cell)
	strg = 'ALLIZZWELL'
	#print ("{} --> {}".format(cell,strg[position]))
	x,y = cell
	if (x-1 >= 0):
		if (y-1 >= 0) and matrix[y-1][x-1] == strg[position+1] and not (x-1,y-1) in used:
			if search(matrix, used, (x-1, y-1), position+1): return True
		if matrix[y][x-1] == strg[position+1] and not (x-1,y) in used:
			if search(matrix ,used, (x-1, y) , position+1): return True
		if (y+1 < len(matrix)) and matrix[y+1][x-1] == strg[position+1] and not (x-1,y+1) in used:
			if search(matrix, used, (x-1, y+1), position+1): return True
	if (y-1 >= 0) and matrix[y-1][x] == strg[position+1] and not (x, y-1) in used:
		if search(matrix, used, (x, y-1), position+1): return True
	if (y+1 < len(matrix)) and matrix[y+1][x] == strg[position+1] and not (x,y+1) in used:
		if search(matrix, used, (x, y+1), position+1): return True
	if (x+1 < len(matrix[0])):
		if (y-1 >= 0) and matrix[y-1][x+1] == strg[position+1] and not (x+1,y-1) in used:
			if search(matrix, used, (x+1, y-1), position+1): return True
		if matrix[y][x+1] == strg[position+1] and not (x+1,y) in used:
			if search(matrix ,used, (x+1, y) , position+1): return True
		if (y+1 < len(matrix)) and matrix[y+1][x+1] == strg[position+1] and not (x+1,y+1) in used:
			if search(matrix, used, (x+1, y+1), position+1): return True
	used.remove(cell)
	#print ('{} failed'.format(cell))
	return False


def IzzAllWell (matrix, m, n):
	for x in range(n):
		for y in range(m):
			used = set()
			if matrix[y][x] == 'A' and search(matrix, used, (x,y), 0):
				return True
	return False


def main():
    numberOfCases = int(sys.stdin.readline())
    for i in range(numberOfCases):
	    line = sys.stdin.readline().strip()
	    [M,N] = [int(num) for num in line.split()]
	    lines = []
	    for j in range(M):
		    lines.append(sys.stdin.readline().strip())
	    if IzzAllWell (lines, M, N):
		    print ('YES')
	    else:
		    print ('NO')
	    sys.stdin.readline()
        

if __name__ == '__main__':
    main()
                
    
