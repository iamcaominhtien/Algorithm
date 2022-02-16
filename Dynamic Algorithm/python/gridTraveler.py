import time
start_time = time.time()

memo={}

def gridTraveler(n,m):
    if (n==1 and m==1): return 1
    if n==0 or m==0: return 0

    key=str(n)+','+str(m)
    if key in memo:
        return memo[key]

    t=gridTraveler(n-1,m)+gridTraveler(n,m-1)
    memo[key]=t

    return t

def gridTraveler2(n,m):
    if (n==1 and m==1): return 1
    if n==0 or m==0: return 0

    key1=str(n)+','+str(m)
    key2=str(m)+','+str(n)
    
    if key1 in memo:
        return memo[key1]
    if key2 in memo:
        return memo[key2]

    t=gridTraveler2(n-1,m)+gridTraveler2(n,m-1)
    if n<m:
        memo[key1]=t
    else: memo[key2]=t
    # print(memo)
    return t

print(gridTraveler2(250,100))
print(len(memo))
print(time.time() - start_time)
