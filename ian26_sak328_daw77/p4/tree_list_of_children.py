class Tree(object):
    def __init__(self):
        self.children = list()
        self.data = None
        self.root = None
    
def PARENT(node):
    return node.root

def LEFTMOST_CHILD(node):
    if len(node.children) > 0 :
        return node.children[0]
    else:
        return None
    
def RIGHT_SIBLING(node):
    if node == None:
        return None
    
    if node.root == None:
        return None;
    
    i=0;
    while node is not node.root.children[i]:
        i = i+1;
        if i+1 == len(node.root.children):
            return None

    if i+1 == len(node.root.children):
        return None
        
    return node.root.children[i+1]

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
    node.children = args[1:]
    node.data = args[0]
    
    for child in args[1:]:
        child.root=node

    return node

def MAKENULL():
    node = Tree()
    node.children = []
    node.data = None
    node.root = None
    return node

def INSERT(root, childVal):
    node = Tree()
    node.children = []
    node.data = childVal
    node.root = root
    root.children.append(node)
    return node


def PRINT(root):
    if root == None:
        return "NONE"
    result = "\nROOT: " + str(LABEL(root)) + "\nCHILDREN: "
    for i in root.children:
      result = result + LABEL(i) + " ,"
    
    return result


