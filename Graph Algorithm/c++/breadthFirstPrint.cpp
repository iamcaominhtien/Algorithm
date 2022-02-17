#include<bits/stdc++.h>
using namespace std;

void breadthFirstPrint(map<string,vector<string>>graph, string source)
{
    queue<string>q; q.push(source);

    while (q.size()>0)
    {
        string current=q.front();
        q.pop();
        cout<<current<<" ";

        vector<string>::iterator i;
        for (i=graph[current].begin();i!=graph[current].end();i++)
            q.push(*i);
    }
}

int main()
{
    map<string,vector<string>>graph={{"a",{"c","b"}},{"b",{"d"}},{"c",{"e"}},{"d",{"f"}},{"e",{}},{"f",{}}};
    breadthFirstPrint(graph,"a"); cout<<endl;
}
