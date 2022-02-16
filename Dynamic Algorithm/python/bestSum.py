from glob import glob
from numpy import sort
import time
start_time = time.time()

memo={}
c=0

def bestSum(n, numbers):
    global c
    c=c+1
    if n==0: return []
    if n<0: return None
    if n in memo: return memo[n]

    shorttestCombination=None

    for i in numbers:
        re=bestSum(n-i,numbers)
        if re!=None:
            re=re+[i]
            if shorttestCombination==None or len(re)<len(shorttestCombination):
                shorttestCombination=re

    memo[n]=shorttestCombination
    return shorttestCombination

def bestSum2(n,numbers):
    global c
    c+=1
    if n==0: return []
    if n<0: return None
    if n in memo: return memo[n]

    for i in numbers:
        re=bestSum2(n-i,numbers)
        if re!=None:
            memo[n]=re+[i]
            return re+[i]
    
    memo[n]=None
    return None

# print(bestSum(7,[2,5,7]))
# memo={}
# print(bestSum(8,[2,3]))
# memo={}
# numbers=[4,47,5,2,3,6,89,12,11,19,22,36]
numbers=[128, 256, 259, 132, 133, 134, 263, 11, 140, 270, 15, 274, 276, 21, 24, 29, 158, 287, 160, 289, 30, 291, 167, 168, 169, 41, 299, 171, 45, 47, 178, 53, 182, 57, 59, 60, 64, 194, 67, 68, 72, 200, 201, 204, 205, 79, 210, 211, 88, 94, 95, 227, 100, 99, 230, 102, 229, 234, 236, 108, 241, 117, 121, 250, 125, 254, 255]
temp=bestSum(3500,numbers)
print(temp,len(temp),sum(temp),len(memo),c)
memo={}
c=0
temp=bestSum2(3500,sorted(numbers,reverse=True))
print(temp,len(temp),sum(temp),len(memo),c)
# print(sorted(numbers,reverse=True))
print(time.time() - start_time)

# from enum import unique
# import numpy
# a=numpy.random.randint(10,300,75)
# print(set(a))
