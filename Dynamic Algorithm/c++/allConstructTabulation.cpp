#include<bits/stdc++.h>
using namespace std;

void addString(string x, vector<vector<string>>&des)
{
    int n=des.size();
    for (int i=0;i<n;i++)
        des[i].push_back(x);
}

void addVector(vector<vector<string>>source, vector<vector<string>>&des)
{
    int n=source.size();
    for (int i=0;i<n;i++)
        des.push_back(source[i]);
}

vector<vector<string>> allConstruct(string target, vector<string>wordBank)
{
    int n_target=target.size(),n_wordB=wordBank.size(),n_memo;
    n_memo=n_target+1;
    vector<vector<vector<string>>>memo;
    memo.resize(n_memo);
    memo[0]={{}};

    for (int i=0;i<n_memo;i++)
        if (memo[i].size()>0)
        {
            for (int j=0;j<n_wordB;j++)
            {
                string compare="";
                int condition=i+wordBank[j].length();
                for (int k=i;k<n_target&&k<condition;k++)
                    compare+=target[k];
                if (compare==wordBank[j])
                {
                    vector<vector<string>>temp=memo[i];
                    addString(wordBank[j],temp);
                    addVector(temp,memo[condition]);
                }
            }
        }

    return memo[n_memo-1];
}

ostream &operator<<(ostream &os, vector<string>s)
{
    int n=s.size();
    for (int i=0;i<n;i++)
        os<<s[i]<<" ";
    return os;
}

ostream &operator<<=(ostream &os, vector<vector<string>>s)
{
    int n=s.size();
    if (n==0)
        os<<"NULL"<<endl;
    else
    {
        for (int i=0;i<n;i++)
            os<<s[i]<<endl;
    }
    os<<endl;
    return os;
}

int main()
{
    cout<<=allConstruct("purple",{"purp","p","ur","le","purpl"});
    cout<<=allConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd","ef","c"}); // true
    cout<<=allConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}); // false
    cout<<=allConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}); // true
}

//https://www.youtube.com/watch?v=oBt53YbR9Kk&t=17423s
