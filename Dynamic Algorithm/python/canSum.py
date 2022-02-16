from math import fabs
from numpy import true_divide

memo={}

def canSum(n,numbers):
    if n==0: return True
    if n<0: return False
    if n in memo: return memo[n]

    for i in numbers:
        if canSum(n-i,numbers):
            memo[n]=True
            return True
    
    memo[n]=False
    return False

print(canSum(7,[2,3]),memo)
memo={}
print(canSum(7,[5,3,4,7]),memo)
memo={}
print(canSum(7,[2,4]),memo)