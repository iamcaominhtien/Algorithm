memo={0:1,1:1}

def fibo(n):
    if n==0 or n==1:
        return 1
    if n in memo:
        return memo[n]
    t=fibo(n-1)+fibo(n-2)
    memo[n]=t
    return t

for i in range(20):
    print(fibo(i),end=', ')

print('\n',fibo(100),sep='')

