#include<bits/stdc++.h>
using namespace std;

struct dict
{
    string key;
    vector<vector<string>>val;
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

void addWord(vector<vector<string>>&s,string word)
{
    int row=s.size();

    for (int i=0;i<row;i++)
        s[i].push_back(word);
}

void addVector(vector<vector<string>>a, vector<vector<string>>&des) //add all elements of a into des
{
    int n=a.size();
    for (int i=0;i<n;i++)
        des.push_back(a[i]);
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
    return os;
}

vector<vector<string>> allConstruct(string target, vector<string>wordBank)
{
    if (target=="") return {{}};
    int fkey=findKey(target);
    if (fkey!=-1) return memo[fkey].val;

    vector<vector<string>>allWay;

    for (int i=0;i<n_wordB;i++)
        if (target.find(wordBank[i])==0)
        {
            string temp=target;
            vector<vector<string>>re=allConstruct(temp.replace(0,wordBank[i].length(),""),wordBank);
            addWord(re,wordBank[i]);
            addVector(re,allWay);
        }

    memo.push_back({target,allWay});
    return allWay;
}

int main()
{
//    vector<vector<int>>a;
//    vector<vector<string>>b{{"hello","how"},{"iam","tien"}};
//    vector<vector<string>>c{{"hello","how"},{"CaoMinh","tien"}};
//    addVector(b,c);
//    cout<<c[3]<<endl;
//    cout<<=c;

    string target="abcdef";
    vector<string>wordBank{"ab", "abc", "cd", "def", "abcd","ef","c"};
    n_wordB=wordBank.size();
    cout<<=allConstruct(target,wordBank);
    cout<<" ****** memo size: "<<memo.size()<<endl;

    target="skateboard";
    wordBank={"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    n_wordB=wordBank.size();
    memo.clear();
    cout<<=allConstruct(target,wordBank);
    cout<<" ****** memo size: "<<memo.size()<<endl;

    target="enterapotentpot";
    wordBank={"a", "p", "ent", "enter", "ot", "o", "t"};
    n_wordB=wordBank.size();
    memo.clear();
    cout<<=allConstruct(target,wordBank);
    cout<<" ****** memo size: "<<memo.size()<<endl;

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
    cout<<=allConstruct(target,wordBank);
    cout<<" ****** memo size: "<<memo.size()<<endl;

    target="purple";
    wordBank={"purp","p","ur","le","purpl"};
    n_wordB=wordBank.size();
    memo.clear();
    cout<<=allConstruct(target,wordBank);
    cout<<" ****** memo size: "<<memo.size()<<endl;
}

//https://www.youtube.com/watch?v=oBt53YbR9Kk&list=PL5P21V35wKDkzAOVpZ6qfqrVq_43yfc-J&index=1&t=10050s
