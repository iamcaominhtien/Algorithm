#include<bits/stdc++.h>
using namespace std;

map<string,vector<string>>buildGraph(vector<vector<string>>edges)
{
    map<string,vector<string>>graph;
    int row=edges.size();
    for (int i=0;i<row;i++)
    {
        if (graph.find(edges[i][0])==graph.end())
            graph[edges[i][0]]={};
        if (graph.find(edges[i][1])==graph.end())
            graph[edges[i][1]]={};
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    return graph;
}

ostream &operator<<(ostream &os, map<string,vector<string>>graph)
{
    map<string,vector<string>>::iterator i;

    for (i=graph.begin();i!=graph.end();i++)
    {
        os<<i->first<<": ";
        vector<string>::iterator j;
        for (j=(i->second).begin();j!=(i->second).end();j++)
            cout<<*j<<" ";
        os<<endl;
    }

    return os;
}

bool hasPathRecursive(map<string,vector<string>>graph,string source, string des, map<string,bool> &visited)
{
    if (source==des) return true;
    if (visited.find(source)!=visited.end()) return false;
    visited[source]=true;

    vector<string>::iterator i;
    for (i=graph[source].begin();i!=graph[source].end();i++)
        if (hasPathRecursive(graph,*i,des,visited))
            return true;

    return false;
}

bool hasPath(map<string,vector<string>>graph,string source, string des)
{
    map<string,bool> visited;
    stack<string>s;
    s.push(source);

    while (s.size()>0)
    {
        string current=s.top();s.pop();
        if (current==des) return true;

        if (visited.find(current)==visited.end())
        {
            visited[current]=true;
            vector<string>::iterator i;
            for (i=graph[current].begin();i!=graph[current].end();i++)
                s.push(*i);
        }
    }

    return false;
}

bool undirectedPath(vector<vector<string>>edges, string source, string des)
{
    map<string,vector<string>>graph=buildGraph(edges);
//    map<string,bool> visited;
//    return hasPathRecursive(graph,source,des,visited);
    return hasPath(graph,source,des);
}

int main()
{
    vector<vector<string>>edges={
      {"i", "j"},
      {"k", "i"},
      {"m", "k"},
      {"l","k"},
      {"o", "n"}
    };

    cout<<undirectedPath(edges,"i","l")<<endl;
    cout<<undirectedPath(edges,"o","m")<<endl;
    cout<<undirectedPath(edges,"j","m");
}
