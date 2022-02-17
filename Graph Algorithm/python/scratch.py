# def depthFirstPrint(graph,source):
#     stack=[source]

#     while len(stack)>0:
#         current=stack.pop()
#         print(current,end=' ')

#         for i in graph[current]:
#             stack.append(i)

#     print('')

# def depthFirstPrintRecursive(graph,source):
#     print(source)

#     for neighbor in graph[source]:
#         depthFirstPrintRecursive(graph,neighbor)

# def breadthFirstPrint(graph,source):
#     queue=[source]

#     while(len(queue)):
#         current=queue.pop(0);
#         print(current,end=' ')

#         for i in graph[current]:
#             queue.append(i)
    
#     print('')
# a={
#     'a':['c','b'],
#     'b':['d'],
#     'c':['e'],
#     'd':['f'],
#     'e':[],
#     'f':[]
# }

# depthFirstPrint(a,'a')
# breadthFirstPrint(a,'a')

def test(n,s):
    # print('--',n,s)
    if n==10: 
        # print(s)
        return s
    s.append(n)
    print(n,s)
    test(n+1,s)
    print(n,s)
    return s

re=test(0,[])
print(re)