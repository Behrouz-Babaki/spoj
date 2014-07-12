#!/usr/bin/python3

# 1391 -- Summing to a Square Prime -- CZ_PROB1
import sys
import math

def generatePrimes (limit):
    nums = [True] * (limit+1)
    counter = 2;
    while (counter < limit):
        if (nums[counter]):
            ind = 2
            while (counter*ind <= limit):
                nums[counter*ind] = False
                ind += 1
        counter += 1;
    primes = set()
    for i in range(2,limit+1):
        if nums[i]:
            primes.add(i)
    return (primes)

def findp2 (primes):
    p2 = []
    for p in primes:
        for j in range(1,math.floor(p**(1/2))+1):
            firstQ = j**2;
            secondQ = p - firstQ;
            secondq = secondQ**(1/2)
            if (secondq == int(secondq)):
                p2.append(p)
                break
    return sorted(p2)

ppArr = dict()
# Give total a with b as the largest integer
def pp(a,b):
    if b == 1 or b == 0:
        return 1
    if b > a:
        return pp(a,a)

    return ppArr[(a,b)]

def initppArr():
    for a in range(2,7994):
        for b in range(2,4):
            if a >= b:
                ppArr[(a,b)] = pp(a-b, b) + pp(a, b-1)
            
        

def main():
    line = sys.stdin.readline().strip()
    numCases = int(line)
    (primes) = generatePrimes(8000)
    p2 = findp2 (primes)
    initppArr()

    for i in range(numCases):
        line = sys.stdin.readline().strip().split()
        [n,k] = [int(j) for j in line]
        sp2n = p2[n-1]
        print ("{}".format(pp(sp2n, k)))

if __name__ == "__main__":
    main()
    
    
