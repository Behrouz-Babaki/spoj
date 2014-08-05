#!/usr/bin/python3

# 13745 -- Crack the Safe -- Problem code: SAFECRAC
import sys
nei = {}
nei [1] = [2,4]
nei [2] = [1,3,5]
nei [3] = [2,6]
nei [4] = [1,5,7]
nei [5] = [2,4,6,8]
nei [6] = [3,5,9]
nei [7] = [4,8,0]
nei [8] = [5,7,9]
nei [9] = [8,6]
nei [0] = [7]

def ways (n):
    w = {};
    for i in range(10):
        w[(i,1)] = 1
    for j in range(2,n+1):
        for i in range(10):
          ww = 0
          for k in nei [i]:
              ww += w[(k,j-1)]
          w[(i,j)] = ww
    result = 0
    for i in range(10):
        result += w[(i,n)]
    return result
    

def main():
    line = sys.stdin.readline()
    numCases = int(line)
    for i in range(numCases):
        line = sys.stdin.readline()
        n = int(line)
        print (ways(n) % 1000000007)
        

if __name__ == "__main__":
    main()
    
    
