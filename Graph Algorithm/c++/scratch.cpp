#include<bits/stdc++.h>
using namespace std;

ostream &operator <<(ostream &os, vector<int>s)
{
    vector<int>::iterator i;
    for (i=s.begin();i!=s.end();i++)
        if (i==s.end())
            os<<*i;
        else os<<*i<<" ";
    return os;
}

ostream &operator <<(ostream &os, map<string,vector<int>>dict)
{
    map<string,vector<int>>::iterator i;
    for (i=dict.begin();i!=dict.end();i++)
        os<<"("<<i->first<<","<<i->second<<")"<<endl;
    return os;
}

int main()
{
    map<string,vector<int>>dict={{"a",{1,2}},{"b",{1,3}},{"c",{1,4}}};
    dict["se"]={1,7};
    dict["df"]={1,12};
    cout<<dict;
}
