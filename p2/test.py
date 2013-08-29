from Dictionary import *

dictionary=Dictionary(10000)

for x in xrange(0,5000):
	dictionary.INSERT(x)

dictionary.DELETE(5000)

print "MEMBER(298)", dictionary.MEMBER(298)
print "MEMBER(4852)", dictionary.MEMBER(4852)
print "MEMBER(100000)", dictionary.MEMBER(100000)
