#include<bits/stdc++.h>
using namespace std;

bool canSum(int target, vector<int>numbers)
{
    vector<bool>memo;
    memo.assign(target+1,false);
    memo[0]=true;
    int n_numbers=numbers.size();

    for (int i=0;i<=target;i++)
        if (memo[i])
        {
            for (int j=0;j<n_numbers;j++)
                if (numbers[j]+i<=target)
                    memo[i+numbers[j]]=true;
        }

    return memo[target];
}

int main()
{
    cout<<canSum(7,{2,3})<<endl;
    cout<<canSum(7,{15, 3, 4, 7})<<endl;
    cout<<canSum(7,{2,4})<<endl;
}

//https://www.youtube.com/watch?v=oBt53YbR9Kk&t=13079s
