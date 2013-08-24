from Dictionary import *

dictionary=Dictionary(3)


dictionary.INSERT("A")
dictionary.INSERT("A")
dictionary.INSERT("Z")
dictionary.INSERT("T")
dictionary.INSERT("B")
for item in dictionary.hashtable:
	print item, dictionary.hashtable[item]
dictionary.DELETE("A")
for item in dictionary.hashtable:
	print item, dictionary.hashtable[item]
