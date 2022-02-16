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

vector<int> bestSum(int n, vector<int>num)
{
    if (n==0) return {0};
    if (n<0) return {};
    int fkey=findKey(n);
    if (fkey!=-1) return memo[fkey].val;

    for (int i=0;i<n_numbers;i++)
    {
        vector<int>re=bestSum(n-num[i],num);
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

vector<int> bestSum2(int n, vector<int>num)
{
    if (n==0) return {0};
    if (n<0) return {};
    int fkey=findKey(n);
    if (fkey!=-1) return memo[fkey].val;

    vector<int>bestCombination;

    for (int i=0;i<n_numbers;i++)
    {
        vector<int>re=bestSum2(n-num[i],num);
        if (re.size()>0)
        {
            re.push_back(num[i]);
            if (bestCombination.size()==0 || bestCombination.size()>re.size())
                bestCombination=re;
        }
    }

    memo.push_back({n,bestCombination});
    return bestCombination;
}

ostream &operator<<(ostream &os, vector<int>s)
{
    int n=s.size();
    for (int i=1;i<n;i++)
        os<<s[i]<<" ";
    return os;
}

long int sum(vector<int>s)
{
    int n=s.size(),S=0;
    for (int i=0;i<n;i++)
        S+=s[i];
    return S;
}

int main ()
{
    vector<int>num{4,47,5,2,3,6,89,12,11,19,22,36};
    n_numbers=num.size();

    vector<int>re=bestSum2(3500,num);
    if (re.size()>0)
        cout<<re<<" - "<<re.size()<<" - "<<sum(re);
    else cout<<"NULL";
    cout<<endl<<memo.size();
    cout<<endl;

    memo.clear();
    sort(num.begin(),num.end(),greater<int>());
    re=bestSum(3500,num);
    if (re.size()>0)
        cout<<re<<" - "<<re.size()<<" - "<<sum(re);
    else cout<<"NULL";
    cout<<endl<<memo.size();

}

//https://www.youtube.com/watch?v=oBt53YbR9Kk&t=6726s
