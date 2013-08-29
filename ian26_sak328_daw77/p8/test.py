def dfs(x, graph, mark):
	mark[x] = "visited"
	print x
	for vertex in graph[x]:
		if mark[vertex] == "unvisited":
			dfs(vertex, graph, mark)
		else:
			continue
		return x
			


graph = {'A':['B','D','F'],
			'B':['C','F'],
			'C':['D'],
			'D':['B'],
			'E':['D','F'],
			'F':['D']}

mark={}
for item in graph:
	mark[item] = "unvisited"
print "DFS from A:"
dfs("A", graph, mark)
print "Continuing DFS, starting at E:"
dfs("E", graph, mark)
mark = {}
for item in graph:
	mark[item] = "unvisited"
print "New DFS, starting at C:"
dfs("C", graph, mark)
