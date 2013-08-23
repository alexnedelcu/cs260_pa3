class Dictionary:

	hashtable=None
	def __init__(self,B):
		self.hashtable = {}
		for i in xrange(0,B):
			self.hashtable[i]=None

	def rehash(self, x):
		return (x+1)%len(self.hashtable)


