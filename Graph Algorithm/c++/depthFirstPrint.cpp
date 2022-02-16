#include<bits/stdc++.h>
using namespace std;

void depthFirstPrint(map<string,vector<string>>graph,string source)
{
    stack<string>s;
    s.push(source);

    while (s.size()>0)
    {
        string current=s.top();
        s.pop();
        cout<<current<<" ";

        int n=graph[current].size();
        for (int i=0;i<n;i++)
            s.push(graph[current][i]);
    }
}

void depthFirstPrintRecursive(map<string,vector<string>>graph,string source)
{
    cout<<source<<" ";

//    int n=graph[source].size();
//    for (int i=0;i<n;i++)
//        depthFirstPrintRecursive(graph,graph[source][i]);
    vector<string>::iterator i;
    for (i=graph[source].begin();i!=graph[source].end();i++)
        depthFirstPrintRecursive(graph,*i);
}

int main()
{
    map<string,vector<string>>graph={{"a",{"b","c"}},{"b",{"d"}},{"c",{"e"}},{"d",{"f"}},{"e",{}},{"f",{}}};
    depthFirstPrint(graph,"a"); cout<<endl;
    depthFirstPrintRecursive(graph,"a");
}

