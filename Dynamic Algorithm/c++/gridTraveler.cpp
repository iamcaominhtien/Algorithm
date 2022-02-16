#include <bits/stdc++.h>
#define ll long double
using namespace std;

struct dict
{
    int key1;
    int key2;
    ll val;
};

vector<dict>memo;

int findKey(int k1, int k2)
{
    if (k1>k2)
        swap(k1,k2);
    int n=memo.size();
    for (int i=0;i<n;i++)
        if (k1==memo[i].key1 && k2==memo[i].key2)
            return i;
    return -1;
}

ll gridTraveler(int m, int n)
{
    if (m==1&&n==1) return 1;
    if (m==0||n==0) return 0;

    int p=findKey(m,n);
    if (p!=-1)
        return memo[p].val;

    ll t=gridTraveler(m-1,n)+gridTraveler(m,n-1);

    if(m<n)
        memo.push_back({m,n,t});
    else memo.push_back({n,m,t});

    return t;
}

ll gridTraveler_ver2(int m, int n)
{
    ll memo2[m+1][n+1];
    for (int i=0;i<=m;i++)
        memo2[i][0]=0;
    for (int j=0;j<=n;j++)
        memo2[0][j]=0;
    memo2[1][1]=1;

    for (int i=1,j=2;i<=m;i++,j=1)
        for (;j<=n;j++)
            memo2[i][j]=memo2[i-1][j]+memo2[i][j-1];

//    cout<<endl;
//    for (int i=0;i<=m;i++)
//    {
//        for (int j=0;j<=n;j++)
//            printf("%.0Lf ",memo2[i][j]);
//        cout<<endl;
//    }

    return memo2[m][n];
}

int main ()
{
    int a=250,b=100;
    gridTraveler_ver2(a,b);

    //Ver2 is better than Ver1
    printf("%.0Lf - %.0Lf | memo-size = ",gridTraveler(a,b),gridTraveler_ver2(a,b));
    cout<<memo.size();
}

//https://www.youtube.com/watch?v=oBt53YbR9Kk&list=PL5P21V35wKDkzAOVpZ6qfqrVq_43yfc-J&index=1&t=2319s
