#include<bits/stdc++.h>
using namespace std;

void explore(std::vector<std::vector<char>> &grid, int x, int y)
{
    if ((x<0||x>=grid.size())||(y<0||(y>=grid[0].size()))||grid[x][y]=='W')
        return;
    grid[x][y]='W';
    explore(grid,x,y-1);
    explore(grid,x-1,y);
    explore(grid,x,y+1);
    explore(grid,x+1,y);
}

int islandCount(std::vector<std::vector<char>> grid)
{
    int row=grid.size(),col=grid[0].size();
    int c=0;

    for (int i=0;i<row;i++)
        for (int j=0;j<col;j++)
            if (grid[i][j]=='L')
            {
                c++;
                explore(grid,i,j);
            }

    return c;
}

int main()
{
    std::vector<std::vector<char>> grid {
      {'W', 'L', 'W', 'W', 'W'},
      {'W', 'L', 'W', 'W', 'W'},
      {'W', 'W', 'W', 'L', 'W'},
      {'W', 'W', 'L', 'L', 'W'},
      {'L', 'W', 'W', 'L', 'L'},
      {'L', 'L', 'W', 'W', 'W'}
    };
    cout<<islandCount(grid); // -> 3
}
