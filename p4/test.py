import time
import sys
import random
from tree_binary import *
from math import log

def countAllPaths(node, nodeList, result):
    if node != None:
        nodeList.append(LABEL(node))
        result.append(len(nodeList)-1)
        countAllPaths(LEFT_CHILD(node), list(nodeList), result)
        countAllPaths(RIGHT_CHILD(node), list(nodeList), result)


# creating big tree
print("Building big tree ... ")
n = 150 
start = 100
tree1 = MAKENULL()
elem = []
for i in range ( 1 , n+1):
  elem.append(i)
random.shuffle(elem)
tree1 = INSERT(elem[0], tree1)


f = open("average_path.txt", "w")
f.write("Nodes  Experimantal value    log2(n)\n")

#building trees with randm values with sizes of 50-150
for n in range(start, start + n):
  # building tree of size n
  tree1 = MAKENULL()
  elem = []
  for i in range ( 1 , n+1):
    elem.append(i)
  random.shuffle(elem)
  tree1 = INSERT(elem[0], tree1)
  for i in range(1, n):
    start = time.time()
    INSERT(elem[i], tree1)
  result = []
  countAllPaths(tree1, [], result)
  
  # caluclate average of paths from root to any other node:
  s=0
  for r in result[1:]:
    s = s+r
  average = "{0:.2f}".format(float(s)/len(result))
  f.write(" "+str(n) + "         " + str(average) + "              " + str("{0:.2f}".format(log(n, 2))) + "\n")

print ("OK")
f.close()
