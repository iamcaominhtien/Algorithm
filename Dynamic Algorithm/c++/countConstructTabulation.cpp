#include<bits/stdc++.h>
using namespace std;

int countConstruct(string target, vector<string>wordBank)
{
    int n_target=target.size(),n_wordB=wordBank.size(),n_memo;
    n_memo=n_target+1;
    vector<int>memo;
    memo.assign(n_memo,0);
    memo[0]=1;

    for (int i=0;i<n_memo;i++)
        if (memo[i])
        {
            for (int j=0;j<n_wordB;j++)
            {
                string compare="";
                int condition=i+wordBank[j].length();
                for (int k=i;k<n_target&&k<condition;k++)
                    compare+=target[k];
                if (compare==wordBank[j])
                    memo[condition]+=memo[i];
            }
        }

    return memo[n_memo-1];
}

int main()
{
    cout<<countConstruct("purple",{"purp","p","ur","le","purpl"})<<endl;
    cout<<countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"})<<endl; // true
    cout<<countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"})<<endl; // false
    cout<<countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"})<<endl; // true
    cout<<countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {
        "e",
        "ee",
        "еее",
        "eeee"
        "eeeee",
        "eеееее",
    })<<endl; // false
}

//https://www.youtube.com/watch?v=oBt53YbR9Kk&t=16686s
