def largest_component(graph):
    visited=[]
    largest=0

    for i in graph:
        re=explore(graph,i,visited)
        if largest<re:
            largest=re

    return largest

def explore(graph,current,visited):
    if current in visited: return 0
    visited.append(current)

    count=1
    for i in graph[current]:
        count+=explore(graph,i,visited)

    return count

# print(largest_component({}))
print(largest_component({
  3: [],
  4: [6],
  6: [4, 5, 7, 8],
  8: [6],
  7: [6],
  5: [6],
  1: [2],
  2: [1]
}))