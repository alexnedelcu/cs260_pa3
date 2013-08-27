class Tree(object):
    def __init__(self):
        self.left_child = None
        self.right_child = None
        self.data = None
        self.root = None
    

def PARENT(node):
    return node.root

def LEFT_CHILD(node):
    if node == None: return None
    return node.left_child
    
def RIGHT_CHILD(node):
    if node == None: return None
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
           deletemin = LABEL(LEFT_CHILD(root))
           root.left_child = RIGHT_CHILD(LEFT_CHILD(root))
        else:
           return DELETEMIN(RIGHT_CHILD(LEFT_CHILD(root)))
    else:
        if RIGHT_CHILD(root) != None:
            deletemin = LABEL(root)
            root = RIGHT_CHILD(root)
        else:
            deletemin = LABEL(root)
            root = None

    return [root, deletemin]


def DELETE (x, root):
    if root != None:
        if x < root.data:
           root.left_child = DELETE(x, LEFT_CHILD(root))
        elif x > root.data:
           root.right_child = DELETE(x, RIGHT_CHILD(root))
        elif LEFT_CHILD(root) == None and RIGHT_CHILD(root) == None:
           root = SET_NODE(root, None)
        elif LEFT_CHILD(root) == None:
           root = SET_NODE(root, RIGHT_CHILD(root))
        elif RIGHT_CHILD(root) == None:
           root = SET_NODE(root, LEFT_CHILD(root))
        else:
           root.data = DELETEMIN(RIGHT_CHILD(root))[1]
    return root

def SET_NODE (x, new):
    if IS_RIGHT_CHILD(x):
        PARENT(x).right_child = new
    elif IS_LEFT_CHILD(x):
        PARENT(x).left_child = new
    return new 
 
def IS_RIGHT_CHILD(x) :
    if x != None:
      if PARENT(x) != None:
        if x == RIGHT_CHILD(PARENT(x)):
          return True
    return False

 
def IS_LEFT_CHILD(x) :
    if x != None:
      if PARENT(x) != None:
        if x == LEFT_CHILD(PARENT(x)):
          return True
    return False
