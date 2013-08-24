
import sys

if sys.argv[1] == "children":
    from measure_tree_children import * 

    f = open("MEASUREMENTS_TREE_CHILDREN.txt", "w+")
    f.write ("Height  Preorder  Postorder\n")
    f.close()
    for i in range(2, 15):
        print (i)
        run_tests(i)

if sys.argv[1] == "leftmost_child":
    from measure_tree_lmrs import *

    f = open("MEASUREMENTS_TREE_LEFTMOST.txt", "w+")
    f.write ("Height  Preorder  Postorder\n")
    f.close()
    for i in range(2, 15):
        print (i)
        run_tests(i)    
