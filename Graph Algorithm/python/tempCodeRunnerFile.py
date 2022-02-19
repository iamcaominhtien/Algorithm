#https://structy.net/problems/island-count

# def explore(grid,x,y,row,col):
#     if (x<0 or x>=row) or (y<0 or y>=col) or grid[x][y]=='W':
#         return

#     grid[x][y]='W'
#     explore(grid,x,y-1,row,col)
#     explore(grid,x-1,y,row,col)
#     explore(grid,x,y+1,row,col)
#     explore(grid,x+1,y,row,col)

# def out_put(grid):
#     for i in grid:
#         print(i)

# def island_count(grid):
#     row=len(grid)
#     col=len(grid[0])

#     re=0
#     for i in range(row):
#         for j in range(col):
#             if grid[i][j]=='L':
#                 re+=1
#                 # out_put(grid)
#                 explore(grid,i,j,row,col)
#                 # out_put(grid)
#                 # print('----------------------------')

#     return re

# grid = [
#   ['W', 'L', 'W', 'W', 'W'],
#   ['W', 'L', 'W', 'W', 'W'],
#   ['W', 'W', 'W', 'L', 'W'],
#   ['W', 'W', 'L', 'L', 'W'],
#   ['L', 'W', 'W', 'L', 'L'],
#   ['L', 'L', 'W', 'W', 'W'],
# ]
# print(island_count(grid))

# # grid=
# # print(island_count(grid))

# # print(grid)

# # row=len(grid)
# # col=len(grid[0])
# # print(row,col)

# # re=0
# # for i in range(row):
# #     for j in range(col):
# #         print(grid[i][j],end=' ')
# #     print('')
