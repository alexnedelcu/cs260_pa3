import sys
import re
from trie import *

alice_trie = Trie()

f = open("alice30.txt", "r")
lines = f.readlines()
print ("Adding words to the trie... ")
for i in lines:
  i=i.lower()
  words =re.findall(r"[a-z]+", i)
  for word in words:
    alice_trie.addWord(word)

print("Number of nodes: " + str(alice_trie.size_nodes))
print("Number of distinct words: " + str(alice_trie.size_words))

f.close()
