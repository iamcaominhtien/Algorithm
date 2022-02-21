class Node:
    def __init__(self, val):
        self.val=val
        self.left=None
        self.right=None

def depth_first_values(root):#nlr
    # print(root.val,root.left,root.right)
    if root:
        # re=[root.val]
        # re+=depth_first_values(root.left)
        # re+=depth_first_values(root.right)
        # return re
        return [root.val,*depth_first_values(root.left),*depth_first_values(root.right)]

    return []

a = Node('a')
b = Node('b')
c = Node('c')
d = Node('d')
e = Node('e')
f = Node('f')
g = Node('g')
a.left = b
a.right = c
b.left = d
b.right = e
c.right = f
e.left = g

print(depth_first_values(a))