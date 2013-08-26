def dfs(x, graph, mark):
	mark[x] = "visited"
	print x
	for vertex in graph[x]:
		if mark[vertex] == "unvisited":
			dfs(vertex, graph, mark)
		return x
			


graph = {'A':['B','C'],
			'B':['D'],
			'C':['E'],
			'D':['C'],
			'E':['F'],
			'F':['C']}

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
