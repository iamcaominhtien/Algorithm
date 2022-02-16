#include <bits/stdc++.h>
#define ll long double
using namespace std;

struct dict
{
    int key;
    bool val;
};

vector<dict>memo;
int n_numbers;

int findKey(int k)
{
    int n=memo.size();
    for (int i=0;i<n;i++)
        if (k==memo[i].key)
            return i;
    return -1;
}

bool canSum(int n, vector<int>num)
{
    if (n==0) return true;
    if (n<0) return false;
    int fkey=findKey(n);
    if (fkey!=-1) return memo[fkey].val;

    for (int i=0;i<n_numbers;i++)
    {
        if (canSum(n-num[i],num))
        {
            memo.push_back({n,true});
            return true;
        }
    }

    memo.push_back({n,false});
    return false;
}

int main ()
{
    vector<int>num{7,13};
    n_numbers=num.size();

    cout<<canSum(300,num)<<endl;
    cout<<memo.size();
}

//https://www.youtube.com/watch?v=oBt53YbR9Kk&t=4196s
