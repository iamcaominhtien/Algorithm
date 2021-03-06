#include<bits/stdc++.h>
using namespace std;

int explore(std::unordered_map<int, std::vector<int>> graph, int current, unordered_map<int,bool> &visited)
{
    if (visited.find(current)!=visited.end())
        return 0;
    visited[current]=true;

    vector<int>::iterator i;
    for (i=graph[current].begin();i!=graph[current].end();i++)
        explore(graph,*i,visited);

    return 1;
}

int connectedComponentsCount(std::unordered_map<int, std::vector<int>> graph)
{
    unordered_map<int,bool>visited;
    int c=0;

    for (auto i:graph)
        c+=explore(graph,i.first,visited);

    return c;
}

int main()
{
    std::unordered_map<int, std::vector<int>> graph {
      { 0, { 4, 7 } },
      { 1, { } },
      { 2, { } },
      { 3, { 6 } },
      { 4, { 0 } },
      { 6, { 3 } },
      { 7, { 0 } },
      { 8, { } },
    };

    cout<<connectedComponentsCount(graph);
}
