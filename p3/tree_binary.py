class Tree(object):
    def __init__(self):
        self.left_child = None
        self.right_sibling = None
        self.data = None
        self.root = None
    

def PARENT(node):
    return node.root

def LEFT_CHILD(node):
    return node.left_child
    
def RIGHT_CHILD(node):
    return node.left_child.right_sibling
    
def LABEL(node):
    if node:
        if node.data:
            return node.data
        else:
            return "[Label not set]"
    else:
        return "[No node]"
    
def CREATE(*args):
    node = Tree()
    node.data = args[0]
    node.left_child = args[1]
    node.left_child.root = node
    node.left_child.right_sibling = args[2]    
    node.left_child.right_sibling.root = node

    return node

def MAKENULL():
    node = Tree()
    return node
