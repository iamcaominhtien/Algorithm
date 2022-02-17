from locale import currency


def undirectedPath(edges,source,des):
    graph=buildGraph(edges)
    # return hasPathRecursive(graph,source,des,[])
    return hasPath(graph,source,des)

def hasPathRecursive(graph,source,des,visited):
    if source==des: return True
    if source in visited: return False
    visited.append(source)
    # print(visited)

    for i in graph[source]:
        if hasPathRecursive(graph,i,des,visited):
            return True

    return False

def hasPath(graph,source,des):
    stack=[source]
    visited=[]

    while len(stack):
        current=stack.pop()
        if current==des: return True

        if current not in visited:
            visited.append(current)
            for i in graph[current]:
                stack.append(i)

    return False

def buildGraph(edges):
    graph={}

    for i in edges:
        [a,b]=i
        if a not in graph: graph[a]=[]
        if b not in graph: graph[b]=[]
        graph[a].append(b)
        graph[b].append(a)

    return graph

edges = [
  ["i", "j"],
  ["k", "i"],
  ["m", "k"],
  ["l","k"],
  ["o", "n"]
]

print(buildGraph(edges))

print(undirectedPath(edges,'i','l'))
print(undirectedPath(edges,'o','m'))
print(undirectedPath(edges,'j','n'))