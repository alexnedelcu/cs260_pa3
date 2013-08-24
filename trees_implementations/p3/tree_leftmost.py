class Tree(object):
    def __init__(self):
        self.left_child = None
        self.right_sibling = None
        self.data = None
        self.root = None
    

def PARENT(node):
    return node.root

def LEFTMOST_CHILD(node):
    return node.left_child
    
def RIGHT_SIBLING(node):
    return node.right_sibling
    
def LABEL(node):
    if node:
        if node.data:
            return node.data
        else:
            return "[Label not set]"
    else:
        return "[No node]"
    
def CREATEi(*args):
    node = Tree()
    node.data = args[0]
    node.left_child = args[1]
    
    for i in range(0, len(args)-2):
        args[len(args)-2-i].right_sibling = args[len(args)-1-i]
        args[len(args)-2-i].root = node
 
    args[len(args)-1].root = node
    args[len(args)-1].right_sibling = None

    return node

def MAKENULL():
    node = Tree()
    return node
