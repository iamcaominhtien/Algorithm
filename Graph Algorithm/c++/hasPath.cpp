#include<bits/stdc++.h>
using namespace std;

bool hasPathRecursive(map<string,vector<string>>graph, string source, string des)
{
    if (source==des) return true;

    vector<string>::iterator i;
    for (i=graph[source].begin();i!=graph[source].end();i++)
        if (hasPathRecursive(graph,*i,des))
            return true;

    return false;
}

bool hasPath(map<string,vector<string>>graph, string source, string des)
{
    queue<string>q;
    q.push(source);

    while (q.size()>0)
    {
        string current=q.front();q.pop();
        if (current==des) return true;

        vector<string>::iterator i;
        for (i=graph[current].begin();i!=graph[current].end();i++)
            q.push(*i);
    }

    return false;
}

int main()
{
    map<string,vector<string>>graph={{"f",{"g","i"}},{"g",{"h"}},{"h",{}},{"i",{"g","k"}},{"j",{"i"}},{"k",{}}};
    cout<<"test1: "<<hasPath(graph,"j","f")<<" - "<<hasPathRecursive(graph,"j","f")<<endl;
    cout<<"test2: "<<hasPath(graph,"h","g")<<" - "<<hasPathRecursive(graph,"h","g")<<endl;
    cout<<"test3: "<<hasPath(graph,"f","k")<<" - "<<hasPathRecursive(graph,"f","k")<<endl;
}
