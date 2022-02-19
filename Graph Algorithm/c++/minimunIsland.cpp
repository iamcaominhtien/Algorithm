#include<bits/stdc++.h>
using namespace std;

int explore(std::vector<std::vector<char>> &grid, int x, int y)
{
    if ((x<0||x>=grid.size())||(y<0||(y>=grid[0].size()))||grid[x][y]=='W')
        return 0;
    grid[x][y]='W';
    int c=1;
    c+=explore(grid,x,y-1);
    c+=explore(grid,x-1,y);
    c+=explore(grid,x,y+1);
    c+=explore(grid,x+1,y);

    return c;
}

int minimumIsland(std::vector<std::vector<char>> grid)
{
    int row=grid.size(),col=grid[0].size();
    int c=INT_MAX;

    for (int i=0;i<row;i++)
        for (int j=0;j<col;j++)
            if (grid[i][j]=='L')
            {
                int re=explore(grid,i,j);
                if (c>re)
                    c=re;
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
    cout<<minimumIsland(grid); // -> 3
}

