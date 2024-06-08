def transpose(graph):
    transposed = {node: [] for node in graph}
    for node in graph:
        for neighbor in graph[node]:
            transposed[neighbor].append(node)
    return transposed

def dfs(graph, visited, start, stack=None):
    visited.add(start)
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, visited, neighbor, stack)
    if stack is not None:
        stack.append(start)

def kosaraju(graph):
    visited = set()
    stack = []
    
    for node in graph:
        if node not in visited:
            dfs(graph, visited, node, stack)

    graph_transposed = transpose(graph)

    sccs = []
    visited = set()
    while stack:
        scc = []
        start = stack.pop()
        if start not in visited:
            dfs(graph_transposed, visited, start, scc)
            sccs.append(scc)

    return sccs

while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    graph = {i: [] for i in range(1, n + 1)}
    for _ in range(m):
        u, v, r = map(int, input().split())
        if r == 1:
            graph[u].append(v)
        elif r == 2:
            graph[u].append(v)
            graph[v].append(u)

    sccs = kosaraju(graph)
    if len(sccs) == 1:
        print("amor total")
    else:
        sccs.sort(key=lambda x: min(x))
        for idx, scc in enumerate(sccs, 1):
            print(f"[{idx},{len(scc)}]", end="")
        print()
