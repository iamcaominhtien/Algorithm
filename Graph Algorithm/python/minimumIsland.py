def explore(grid,x,y,row,col):
    if (x<0 or x>=row) or (y<0 or y>=col) or grid[x][y]=='W':
        return 0

    c=1
    grid[x][y]='W'
    c=c+explore(grid,x,y-1,row,col)+explore(grid,x-1,y,row,col)+explore(grid,x,y+1,row,col)+explore(grid,x+1,y,row,col)

    return c

def minimum_island(grid):
    row=len(grid)
    col=len(grid[0])

    minSize=float("inf")
    for i in range(row):
        for j in range(col):
            if grid[i][j]=='L':
                re=explore(grid,i,j,row,col)
                # print(re)
                if minSize>re:
                    minSize=re

    return minSize

grid = [
  ['W', 'L', 'W', 'W', 'W'],
  ['W', 'L', 'W', 'W', 'W'],
  ['W', 'W', 'W', 'L', 'W'],
  ['W', 'W', 'L', 'L', 'W'],
  ['L', 'W', 'W', 'L', 'L'],
  ['L', 'L', 'W', 'W', 'W'],
]

print(minimum_island(grid)) # -> 2