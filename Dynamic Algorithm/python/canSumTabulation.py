from cmath import pi

def canSum(target, numbers):
    memo=[False for i in range(target+1)]
    memo[0]=True

    for i in range(target+1):
        if memo[i]:
            for num in numbers:
                if i+num<=target:
                    memo[i+num]=True

    return memo[target]

print(canSum(7, [2, 3]))
print(canSum(7, [15, 3, 4, 7]))
print(canSum(7, [2, 4]))
print(canSum(8, [2, 3, 5]))
print(canSum(300, [7, 14]))