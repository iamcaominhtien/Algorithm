#include <bits/stdc++.h>
#define ll long double
using namespace std;

struct dict
{
    int key;
    vector<int>val;
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

vector<int> howSum(int n, vector<int>num)
{
    if (n==0) return {0};
    if (n<0) return {};
    int fkey=findKey(n);
    if (fkey!=-1) return memo[fkey].val;

    for (int i=0;i<n_numbers;i++)
    {
        vector<int>re=howSum(n-num[i],num);
        if (re.size()>0)
        {
            re.push_back(num[i]);
            memo.push_back({n,re});
            return re;
        }
    }

    memo.push_back({n,{}});
    return {};
}

int main ()
{
    vector<int>num{7,13};
    n_numbers=num.size();

    vector<int>re=howSum(300,num);
    if (re.size()>0)
        for (int i=1;i<re.size();i++)
            cout<<re[i]<<" ";
    else cout<<"NULL";
    cout<<endl<<memo.size();
}

//https://www.youtube.com/watch?v=oBt53YbR9Kk&t=5369s
