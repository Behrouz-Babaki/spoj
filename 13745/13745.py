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

def ways (n, pos, val):
    if pos == n:
        return 1;
    w = 0;
    for vv in nei[val]:
        w += ways (n, pos+1, vv)
    return w
    

def main():
    line = sys.stdin.readline()
    numCases = int(line)
    for i in range(numCases):
        line = sys.stdin.readline()
        n = int(line)
        w = 0
        for val in range(10):
            w += ways (n, 1, val)
        print (w % 1000000007)
        

if __name__ == "__main__":
    main()
    
    
