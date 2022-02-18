#include<bits/stdc++.h>
using namespace std;

int explore(std::unordered_map<int, std::vector<int>> graph, int current, unordered_map<int,bool> &visited)
{
    if (visited.find(current)!=visited.end())
        return 0;
    visited[current]=true;

    int c=1;
    vector<int>::iterator i;
    for (i=graph[current].begin();i!=graph[current].end();i++)
        c+=explore(graph,*i,visited);

    return c;
}

int largestComponent(std::unordered_map<int, std::vector<int>> graph)
{
    unordered_map<int,bool>visited;
    int largest=0;

    for (auto i:graph)
    {
        int re=explore(graph,i.first,visited);
        largest=max(largest,re);
    }
    return largest;
}

int main()
{
    std::unordered_map<int, std::vector<int>> graph {
      { 1, {2} },
      { 2, {1, 8} },
      { 6, {7} },
      { 9, {8} },
      { 7, {6, 8} },
      { 8, {9, 7, 2} }
    };
    cout<<largestComponent(graph);
}
