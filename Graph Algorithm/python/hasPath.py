def hasPathRecursive(graph,source,des):
    if source==des: return True

    for i in graph[source]:
        if hasPathRecursive(graph,i,des): return True

    return False

def hasPath(graph,source,des):
    queue=[source]

    while len(queue)>0:
        current=queue.pop(0)
        if current==des: return True

        for i in graph[current]:
            queue.append(i)

    return False

graph={
    'f':['g','i'],
    'g':['h'],
    'h':[],
    'i':['g','k'],
    'j':['i'],
    'k':[]
}

print('test1',hasPath(graph,'f','k'),hasPathRecursive(graph,'f','k'))
print('test2',hasPath(graph,'j','f'),hasPathRecursive(graph,'j','f'))
print('test3',hasPath(graph,'h','g'),hasPathRecursive(graph,'h','g'))
