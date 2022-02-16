import time
start_time = time.time()

memo={}

def howSum(n,numbers):
    if n==0: return []
    if n<0: return None
    if n in memo: return memo[n]

    for i in numbers:
        re=howSum(n-i,numbers)
        if re!=None:
            memo[n]=re+[i]
            return re+[i]
    
    memo[n]=None
    return None

print(howSum(28,[3,5,2,1]))
print(time.time() - start_time)
