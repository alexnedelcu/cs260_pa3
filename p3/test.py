
from tree_binary import *

# inplementing the tree from figure 5.1 in the text

# attach the child 15 to the node 18
tree = MAKENULL()
print("TREE ROOT: ")
tree = INSERT(18, tree)
print(tree)
print("TREE LEFT CHILD:")
print(INSERT(17, tree))
print(LEFT_CHILD(tree))
print("TREE RIGHT CHILD:")
print(INSERT(19, tree))
print(RIGHT_CHILD(tree))

print("TREE LEFT LEFT CHILD:")
print(INSERT(16, tree))
print(LEFT_CHILD(LEFT_CHILD(tree)))
