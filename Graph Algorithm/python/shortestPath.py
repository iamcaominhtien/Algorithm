def shortest_path(edges,nodeA,nodeB):
    graph=createGraph(edges)
    print(graph)

    return explore(graph,nodeA,nodeB)

def explore(graph,source,des):
    queue=[[source,0]]
    visited=[source]

    while len(queue):
        # print(queue)
        [current,length]=queue.pop(0)
        if current==des: return length

        for i in graph[current]:
            if i not in visited:
                visited.append(i)
                queue.append([i,length+1])

    return -1

def createGraph(edges):
    graph={}
    for a,b in edges:
        if a not in graph:
            graph[a]=[]
        if b not in graph:
            graph[b]=[]
        graph[a].append(b)
        graph[b].append(a)

    return graph

edges = [
  ['w', 'x'],
  ['x', 'y'],
  ['z', 'y'],
  ['z', 'v'],
  ['w', 'v']
]

print(shortest_path(edges, 'w', 'z')) # -> 2

# edges = [
#   ['w', 'x'],
#   ['x', 'y'],
#   ['z', 'y'],
#   ['z', 'v'],
#   ['w', 'v']
# ]

# print(shortest_path(edges, 'y', 'x')) # -> 1