import time
import sys
import random
from tree_binary import *
from math import log

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

tree = DELETE(18, tree)
# delete the first 7 minimum values (the entire tree)
for i in range(0, 7):
  dm = DELETEMIN(tree)
  tree = dm[0]
  print("MIN: " + str(dm[1]) + " ROOT: " + str(LABEL(dm[0])))

