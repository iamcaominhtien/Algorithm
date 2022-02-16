#include<bits/stdc++.h>
using namespace std;

vector<int> howSum(int target, vector<int>numbers)
{
    vector<vector<int>>memo;
    memo.resize(target+1);
    memo[0]={0};
    int n_numbers=numbers.size();

    for (int i=0;i<=target;i++)
        if (memo[i].size()>0)
        {
            for (int j=0;j<n_numbers;j++)
                if (numbers[j]+i<=target)
                {
                    memo[i+numbers[j]]=memo[i];
                    memo[i+numbers[j]].push_back(numbers[j]);
                }
        }

    return memo[target];
}

ostream &operator<<(ostream &os, vector<int>s)
{
    int n=s.size();
    if (s.size()==0)
        cout<<"NULL";
    else
    {
        for (int i=1;i<n;i++)
            os<<s[i]<<" ";
    }

    return os;
}

int main()
{
    cout<<howSum(7,{2,3})<<endl;
    cout<<howSum(7,{15, 3, 4, 7})<<endl;
    cout<<howSum(7,{2,4})<<endl;
    cout<<howSum(8,{2,3,5})<<endl;
}

//https://www.youtube.com/watch?v=oBt53YbR9Kk&t=13981s
