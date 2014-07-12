#!/usr/bin/python3

import sys
import math

line = sys.stdin.readline().strip()
numCases = int(line)
g = math.sin(math.radians(60))

for i in range(numCases):
    line = sys.stdin.readline().strip()
    V = int(line)
    a = ((6*V) / (2*(g**2)))**(1/3)
    print ((a**2)*g + 3*(2*V)/(a*g))

