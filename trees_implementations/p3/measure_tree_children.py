import sys
import time
from tree_list_of_children import *

i=0
level = 0
max_level = 3

def create_children(root, i):
    r  = MAKENULL()
    c1 = MAKENULL()
    c2 = MAKENULL()
    c3 = MAKENULL()
    c1.data = i
    i = i + 1
    c2.data = i
    i = i + 1
    c3.data = i
    i = i + 1
    r = CREATEi(r, c1, c2, c3)
    root.children = r.children
    return [c1, c2, c3]

def create_levels(list_nodes, level, max_level, i):
    new_list = []

    for node in list_nodes:
        new_list.extend(create_children(node, i))
        i=i+3

    level = level + 1
    if level < max_level:
        create_levels(new_list, level, max_level, i)

def preorder (root):
    print(LABEL(root))
    if LEFTMOST_CHILD(root) != None:
        preorder(LEFTMOST_CHILD(root))
        preorder(RIGHT_SIBLING(LEFTMOST_CHILD(root)))
        preorder(RIGHT_SIBLING(RIGHT_SIBLING(LEFTMOST_CHILD(root))))

def postorder (root):
    if LEFTMOST_CHILD(root) != None:
        preorder(LEFTMOST_CHILD(root))
        preorder(RIGHT_SIBLING(LEFTMOST_CHILD(root)))
        preorder(RIGHT_SIBLING(RIGHT_SIBLING(LEFTMOST_CHILD(root))))
    print(LABEL(root))

def run_tests (max_level):

    root = Tree()
    root.data = 1

    i=2
    create_levels([root], 1, max_level, i)

    start1 = time.time()
    preorder(root)
    end1 = time.time()


    start2 = time.time()
    postorder(root)
    end2 = time.time()

    f = open("MEASUREMENTS_TREE_CHILDREN.txt", "a")
    f.write("  " + str(max_level) + "      " + str("{0:.4f}".format(end1-start1)) + "    " + str( "{0:4f}".format(end2-start2) ) + "\n")
    f.close()

f = open("MEASUREMENTS_TREE_CHILDREN.txt", "w+")
f.write ("Height  Preorder  Postorder\n")
f.close()
for i in range(2, 12):
    print (i)
    run_tests(i)
