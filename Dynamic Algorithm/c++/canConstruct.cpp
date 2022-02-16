#include<bits/stdc++.h>
using namespace std;

int n_wordB;

struct dict
{
    string key;
    bool val;
};

vector<dict>memo;

int findKey(string x)
{
    int n=memo.size();
    for (int i=0;i<n;i++)
        if (memo[i].key==x)
            return i;
    return -1;
}

bool canConstruct(string target, vector<string>wordBank)
{
    if (target=="") return true;
    int fkey=findKey(target);
    if (fkey!=-1) return memo[fkey].val;

    for (int i=0;i<n_wordB;i++)
        if (target.find(wordBank[i])==0)
        {
            string temp=target;
            if (canConstruct(temp.replace(0,wordBank[i].size(),""),wordBank))
            {
                memo.push_back({target,true});
                return true;
            }
        }

    memo.push_back({target,false});
    return false;
}

ostream &operator<<(ostream &os, vector<string>s)
{
    int n=s.size();
    for (int i=0;i<n;i++)
        os<<s[i]<<" ";
    return os;
}

int main()
{
//    string target="caominhcaotien";
//    string temp=target;
//    cout<<temp.find("han")<<" "<<string::npos<<endl;
//    cout<<temp.replace(0,3,"")<<" "<<target<<" "<<temp;

    string target="abcdef";
    vector<string>wordBank{"ab", "abc", "cd", "def", "abcd"};
    n_wordB=wordBank.size();
    cout<<canConstruct(target,wordBank)<<" | memo size: "<<memo.size()<<endl;

    target="skateboard";
    wordBank={"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    n_wordB=wordBank.size();
    memo.clear();
    cout<<canConstruct(target,wordBank)<<" | memo size: "<<memo.size()<<endl;

    target="enterapotentpot";
    wordBank={"a", "p", "ent", "enter", "ot", "o", "t"};
    n_wordB=wordBank.size();
    memo.clear();
    cout<<canConstruct(target,wordBank)<<" | memo size: "<<memo.size()<<endl;

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
    cout<<canConstruct(target,wordBank)<<" | memo size: "<<memo.size()<<endl;
}

//https://www.youtube.com/watch?v=oBt53YbR9Kk&list=PL5P21V35wKDkzAOVpZ6qfqrVq_43yfc-J&index=1&t=7965s
