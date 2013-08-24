class Dictionary:

	hashtable=None
	def __init__(self,B):
		self.hashtable = {}
		for i in xrange(0,B):
			self.hashtable[i]=None

	def rehash(self, x):
		return (x+1)%len(self.hashtable)

	def INSERT(self, x):
		bucket = 0
		looped_through = False
		while looped_through == False:
			if self.hashtable[bucket] == x:
				print "{} is already in Dictionary".format(x)
				return
			elif self.hashtable[bucket] == None:
				self.hashtable[bucket] = x
				return
			if self.rehash(bucket) == 0:
				looped_through=True
				print "INSERT FAILED: Table is full"
			bucket = self.rehash(bucket)

	def DELETE(self, x):
		bucket = 0
		looped_through = False
		while looped_through == False:
			if self.hashtable[bucket] == x:
				self.hashtable[bucket] = None
			else:
				if self.rehash(bucket) == 0:
					looped_through = True
				bucket = self.rehash(bucket)
