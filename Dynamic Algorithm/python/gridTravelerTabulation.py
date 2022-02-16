import numpy

def gridTravler(m,n):
    # memo=[[0 for j in range(n+2)] for i in range(m+2)]
    memo=numpy.zeros([m+2,n+2])
    # print(memo)
    memo[1][1]=1

    for i in range(m+1):
        for j in range(n+1):
            memo[i+1][j]+=memo[i][j]
            memo[i][j+1]+=memo[i][j]
    return memo[m][n]

print('{:.0f}'.format(gridTravler(4,3)))
print('{:.0f}'.format(gridTravler(256,180)))