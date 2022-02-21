class Node:
    def __init__(self, val):
        self.val=val
        self.left=None
        self.right=None

def breadth_first_values(root):
    if root:
        queue=[root]
        re=[]

        while len(queue):
            current=queue.pop(0)
            re.append(current.val)
            if current.left: queue.append(current.left)
            if current.right: queue.append(current.right)

        return re

    return []

a = Node('a')
b = Node('b')
c = Node('c')
d = Node('d')
e = Node('e')
f = Node('f')

a.left = b
a.right = c
b.left = d
b.right = e
c.right = f

print(breadth_first_values(a))

#https://structy.net/problems/breadth-first-values