#include<bits/stdc++.h>
using namespace std;

struct dict
{
    string key;
    int val;
};

vector<dict>memo;
int n_wordB;

int findKey(string k)
{
    int n=memo.size();
    for (int i=0;i<n;i++)
        if (k==memo[i].key)
            return i;
    return -1;
}

int countConstruct(string target, vector<string>wordBank)
{
    if (target=="") return 1;
    int fkey=findKey(target);
    if (fkey!=-1) return memo[fkey].val;

    int totalCount=0;
    for (int i=0;i<n_wordB;i++)
        if (target.find(wordBank[i])==0)
        {
            string temp=target;
            int re=countConstruct(temp.replace(0,wordBank[i].length(),""),wordBank);
            totalCount+=re;
        }

    memo.push_back({target,totalCount});
    return totalCount;
}

ostream &operator<<(ostream &os, vector<int>s)
{
    int n=s.size();
    for (int i=0;i<n;i++)
        os<<s[i]<<" ";
    return os;
}

int main ()
{
    string target="abcdef";
    vector<string>wordBank{"ab", "abc", "cd", "def", "abcd"};
    n_wordB=wordBank.size();
    cout<<countConstruct(target,wordBank)<<" | memo size: "<<memo.size()<<endl;

    target="skateboard";
    wordBank={"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    n_wordB=wordBank.size();
    memo.clear();
    cout<<countConstruct(target,wordBank)<<" | memo size: "<<memo.size()<<endl;

    target="enterapotentpot";
    wordBank={"a", "p", "ent", "enter", "ot", "o", "t"};
    n_wordB=wordBank.size();
    memo.clear();
    cout<<countConstruct(target,wordBank)<<" | memo size: "<<memo.size()<<endl;

    target="eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    wordBank={"e",
      "ее"
      "еее"
      "eeee"
      "eeeee"
      "eeeeee"
    };
    n_wordB=wordBank.size();
    memo.clear();
    cout<<countConstruct(target,wordBank)<<" | memo size: "<<memo.size()<<endl;

    target="purple";
    wordBank={"purp","p","ur","le","purpl"};
    n_wordB=wordBank.size();
    memo.clear();
    cout<<countConstruct(target,wordBank)<<" | memo size: "<<memo.size()<<endl;
}

//https://www.youtube.com/watch?v=oBt53YbR9Kk&list=PL5P21V35wKDkzAOVpZ6qfqrVq_43yfc-J&index=1&t=9516s
