from tree_list_of_children import *

class Trie (object):
  def __init__(self):
    self.start = MAKENULL()
    self.size_nodes = 1
    self.size_words = 0

  def findChild(self, node, x):
    child = LEFTMOST_CHILD(node)
    while child != None:
      if LABEL(child) == x:
        return child
      child = RIGHT_SIBLING(child)
    return None
  
  def addWord(self, word):
    pathAdded = False
    chars = list(word)
    current = self.start
    for c in chars:
      child = self.findChild(current, c)
      if child != None:
        current = child
      else:
        current = INSERT(current, c)
        self.size_nodes = self.size_nodes+1
        pathAdded = True
    if pathAdded :
      self.size_words = self.size_words + 1

t = Trie()
t.addWord("blah") 
t.addWord("blahs") 
t.addWord("blshs") 
print("Number of nodes: ", t.size_nodes)
print("Number of distinct words: ", t.size_words)
