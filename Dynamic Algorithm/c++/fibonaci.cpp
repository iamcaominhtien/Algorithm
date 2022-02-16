#include <bits/stdc++.h>
#define ll long double
using namespace std;

struct dict
{
    int key;
    ll val;
};

vector<dict>memo;

int findKey(int x)
{
    int n=memo.size();
    for (int i=0;i<n;i++)
        if (x==memo[i].key)
            return i;
    return -1;
}

ll fibo(int n)
{
    if (n==1||n==0) return 1;
    int fkey=findKey(n);
    if (fkey!=-1) return memo[fkey].val;

    ll t=fibo(n-1)+fibo(n-2);
    memo.push_back({n,t});
    return t;
}

int main ()
{
    for (int i=0;i<100;i++)
        printf("%.0Lf ",fibo(i));
}

//https://www.youtube.com/watch?v=oBt53YbR9Kk&list=PL5P21V35wKDkzAOVpZ6qfqrVq_43yfc-J&index=1&t=210s
