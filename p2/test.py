from Dictionary import *

dictionary=Dictionary(3)


dictionary.INSERT("A")
dictionary.INSERT("A")
dictionary.INSERT("Z")
dictionary.INSERT("T")
dictionary.INSERT("B")
print "Dictionary before Deleting A:"
for item in dictionary.hashtable:
	print item, dictionary.hashtable[item]
dictionary.DELETE("A")
print "Dictionary after Deleting A:"
for item in dictionary.hashtable:
	print item, dictionary.hashtable[item]

print "MEMBER(A)", dictionary.MEMBER("A")
print "MEMBER(T)", dictionary.MEMBER("T")
