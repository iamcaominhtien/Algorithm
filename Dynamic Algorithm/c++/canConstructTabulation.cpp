#include<bits/stdc++.h>
#include<string.h>
using namespace std;

ostream &operator<<(ostream &os, vector<bool>s)
{
    int n=s.size();
    for (int i=0;i<n;i++)
        if (s[i])
            os<<"TRUE ";
        else os<<"FALSE ";
    return os;
}

bool canConstruct(string target, vector<string>wordBank)
{
    int n_target=target.size();
    int n_memo=n_target+1;
    vector<bool>memo;
    memo.assign(n_target+1,false);
    memo[0]=true;
    int n_wordB=wordBank.size();

    for (int i=0;i<n_memo;i++)
        if (memo[i])
        {
            for (int j=0;j<n_wordB;j++)
            {
                string compare="";
                int condition=i+wordBank[j].length();
                for (int k=i;k<n_target&&k<condition;k++)
                    compare+=target[k];
//                cout<<compare<<" "<<wordBank[j]<<"  |"<<target<<" "<<i<<endl;
                if (compare==wordBank[j])
                    memo[condition]=true;
            }
        }

//    cout<<memo<<endl;
    return memo[n_memo-1];
}

int main()
{
//    string target="abcdef";
//    string compare=target;
//    cout<<compare.replace(1,target.length(),"");

    cout<<canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"})<<endl; // true
    cout<<canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"})<<endl; // false
    cout<<canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"})<<endl; // true
    cout<<canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {
        "e",
        "ee",
        "еее",
        "eeee"
        "eeeee",
        "eеееее",
    })<<endl; // false

//    string target="abcdef";
//    for (int i=0;i<=target.length();i++)
//    {
//        string comp=target;
//        comp.replace(0,i,"");
//        cout<<i<<" "<<comp<<" "<<target<<endl;
//    }
}
