class Tree(object):
    def __init__(self):
        self.left_child = None
        self.right_child = None
        self.data = None
        self.root = None
    

def PARENT(node):
    return node.root

def LEFT_CHILD(node):
    return node.left_child
    
def RIGHT_CHILD(node):
    return node.right_child
    
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
    node.right_child = args[2]    
    node.right_child.root = node
    return node

def MAKENULL():
    node = Tree()
    return node

def INSERT(x, root):
    if root == None:
        n = MAKENULL()
        n.data = x
	n.root = root
        return n
    elif x < root.data:
        if LEFT_CHILD(root) == None:
            root.left_child = INSERT(x, LEFT_CHILD(root)) 
            return root.left_child
        return INSERT(x, LEFT_CHILD(root)) 
    elif x > root.data:
        if RIGHT_CHILD(root) == None:
            root.right_child = INSERT(x, RIGHT_CHILD(root))
            return root.right_child
        return INSERT(x, RIGHT_CHILD(root))

    return false


def MEMBER(x, root):
    if root == None:
        return false
    elif x == root.data:
        return root
    elif x < root.data:
        return MEMBER(x, LEFT_CHILD(root))
    elif x > root.data:
        return MEMBER(x, RIGHT_CHILD(root))
    else:
        return false

def DELETEMIN (root):
    if LEFT_CHILD(root) != None:
        if LEFT_CHILD(LEFT_CHILD(root)) == None:
           root.left_child = RIGHT_CHILD(LEFT_CHILD(root))
        return root 
    else:
        if RIGHT_CHILD(root) != None:
            root = RIGHT_CHILD(root)
        else:
            root = None

    return root
