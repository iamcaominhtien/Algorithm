def howSum(target,numbers):
    memo=[None for i in range(target+1)]
    memo[0]=[]

    for i in range(target+1):
        if memo[i]!=None:
            for j in numbers:
                if j+i<=target:
                    if memo[j+i]==None or len(memo[i])+1<len(memo[i+j]):
                        memo[j+i]=memo[i]+[j]
    
    return memo[target]

print(howSum(7, [2, 3]))
print(howSum(7, [15, 3, 4, 7]))
print(howSum(7, [2, 4]))
print(howSum(8, [2, 3, 5]))
print(howSum(300, [7, 14]))
print(howSum(100,[25,20,1,2,5]))