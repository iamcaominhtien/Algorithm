#include<bits/stdc++.h>
using namespace std;

ostream &operator<<(ostream &os, unordered_map<string,vector<string>>graph)
{
    for (auto i:graph)
    {
        os<<i.first<<": ";
        vector<string>::iterator j;

        for (j=(i.second).begin();j!=(i.second).end();j++)
            os<<*j<<" ";
        os<<endl;
    }

    return os;
}

unordered_map<string,vector<string>> createGraph(std::vector<std::tuple<std::string, std::string>> edges)
{
    unordered_map<string,vector<string>>graph;
    int n=edges.size();

    for (int i=0;i<n;i++)
    {
        string a=get<0>(edges[i]), b=get<1>(edges[i]);
        if (graph.find(a)==graph.end())
            graph[a]={};
        if (graph.find(b)==graph.end())
            graph[b]={};
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return graph;
}

ostream &operator<<(ostream &os, queue<std::tuple<string,int>>q)
{
    while (q.size())
    {
        std::tuple<string,int>current=q.front();
        q.pop();
        string node=get<0>(current);
        int distance=get<1>(current);

        os<<"("<<node<<" "<<distance<<"), ";
    }
    os<<endl;

    return os;
}

int shortestPath(std::vector<std::tuple<std::string, std::string>> edges, std::string nodeA, std::string nodeB)
{
    queue<std::tuple<string,int>>q;
    q.push({nodeA,0});
    map<string,int>visited;
    visited[nodeA]=true;
    unordered_map<string,vector<string>>graph=createGraph(edges);
//    cout<<graph;

    while (q.size())
    {
//        cout<<q;
        std::tuple<string,int>current=q.front();
        q.pop();
        string node=get<0>(current);
        int distance=get<1>(current);
//        cout<<node<<" "<<distance<<endl;

        if (node==nodeB)
            return distance;

        vector<string>::iterator i;
        for (i=graph[node].begin();i!=graph[node].end();i++)
            if (visited.find(*i)==visited.end())
            {
                visited[*i]=true;
                q.push({*i,distance+1});
            }
    }

    return -1;
}

int main()
{
    std::vector<std::tuple<std::string, std::string>> edges {
      {"w", "x"},
      {"x", "y"},
      {"z", "y"},
      {"z", "v"},
      {"w", "v"}
    };
    cout<<shortestPath(edges, "w", "z"); // -> 2
}
