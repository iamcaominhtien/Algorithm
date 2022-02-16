#include <bits/stdc++.h>
#define ll long double
using namespace std;

ll gridTraveler(int m, int n)
{
    ll memo[m+2][n+2];

    for (int i=0;i<=m+1;i++)
        for (int j=0;j<=n+1;j++)
            memo[i][j]=0;

    memo[1][1]=1;

    for (int i=0;i<=m;i++)
        for (int j=0;j<=n;j++)
        {
            memo[i+1][j]+=memo[i][j];
            memo[i][j+1]+=memo[i][j];
        }

    return memo[m][n];
}

int main()
{
    cout<<fixed<<setprecision(0);
    cout<<gridTraveler(4,3)<<endl;
    cout<<gridTraveler(180,260)<<endl;
}

//https://www.youtube.com/watch?v=oBt53YbR9Kk&t=12137s
