def connected_components_count(graph):
  count=0
  visited=[]

  for i in graph:
      count+=explore(graph,i,visited)
      
  return count

def explore(graph,current,visited):
    if current in visited: return False
    visited.append(current)

    for i in graph[current]:
        explore(graph,i,visited)

    return True

#https://structy.net/problems/connected-components-count

# def loop(s):
#     for i in range(5):
#         s.append(i)

# s=[1,2,3]
# print(s)
# loop(s)
# print(s)