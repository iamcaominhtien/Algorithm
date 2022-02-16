def depthFirstPrint(graph,source):
    stack=[source]

    while len(stack)>0:
        current=stack.pop()
        print(current,end=' ')

        for i in graph[current]:
            stack.append(i)
a={
    'a':['c','b'],
    'b':['d'],
    'c':['e'],
    'd':['f'],
    'e':[],
    'f':[]
}

def depthFirstPrintRecursive(graph,source):
    print(source)

    for neighbor in graph[source]:
        depthFirstPrintRecursive(graph,neighbor)

depthFirstPrint(a,'a')
