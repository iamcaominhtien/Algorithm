class Node:
    def __init__(self, val):
        self.val=val
        self.left=None
        self.right=None

def tree_includes(root, target):
    if root:
        if root.val==target:
            return True
        
        if tree_includes(root.left,target): return True
        if tree_includes(root.right,target): return True

    return False

a = Node("a")
b = Node("b")
c = Node("c")
d = Node("d")
e = Node("e")
f = Node("f")

a.left = b
a.right = c
b.left = d
b.right = e
c.right = f

print(tree_includes(a, "e")) # -> True

#https://structy.net/problems/tree-includes
