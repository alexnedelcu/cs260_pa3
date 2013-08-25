
from tree_binary import *

# inplementing the tree from figure 5.1 in the text

# attach the child 15 to the node 18
tree = MAKENULL()
tree = INSERT(10, tree)
INSERT(5, tree)
INSERT(7, tree)
INSERT(14, tree)
INSERT(12, tree)
INSERT(18, tree)
INSERT(15, tree)

print(str(LABEL(LEFT_CHILD(tree))) + ", root: " + str(LABEL(tree)))
tree = DELETEMIN(tree)
print(str(LABEL(LEFT_CHILD(tree))) + ", root: " + str(LABEL(tree)))
