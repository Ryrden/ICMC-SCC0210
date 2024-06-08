n, m = map(int, input().split())
graph = {i: [] for i in range(1, n+1)}
start_vertex = -1
for _ in range(m):
    a, b = map(int, input().split())
    if start_vertex == -1:
        start_vertex = a
    graph[a].append(b)

# O(n * (n + m))
def brute_force():
    def dfs(curr, dest, visited):
        stack = [curr]
        while stack:
            curr = stack.pop()
            if curr == dest:
                return True
            if visited[curr]:
                continue
            visited[curr] = True
            stack.extend(graph[curr])
        return False
    
    def is_connected(a, b):
        visited = [False] * (n+1)
        return dfs(a, b, visited)
    
    def find_strongly_connected_components():
        ans = []
        is_scc = [False] * (n+1)

        for i in range(1, n+1): 
            if is_scc[i]:
                continue
            scc = [i]
            for j in range(i + 1, n+1):
                if is_scc[j]:
                    continue
                if is_connected(i, j) and is_connected(j, i):
                    scc.append(j)
                    is_scc[j] = True
            ans.append(scc)
        return ans
    
    scc = find_strongly_connected_components()
    if len(scc) == 1:
        print('SIM')
    else:
        print('NAO')

# O(n + m)
def solution_kosaraju():
    def dfs(v, visited, graph):
        stack = [v]
        while stack:
            v = stack.pop()
            if v in visited:
                continue
            visited.add(v)
            stack.extend(graph[v])

    def transpose(graph):
        transposed = {i: [] for i in range(1, n+1)}
        for i in range(1, n+1):
            for j in graph[i]:
                transposed[j].append(i)
        return transposed

    def kosaraju():
        visited = set()

        dfs(start_vertex, visited, graph)

        if len(visited) < n:
            return False
        
        graph_transposed = transpose(graph)

        visited = set()

        dfs(start_vertex, visited, graph_transposed)

        if len(visited) < n:
            return False
        
        return True
    
    if kosaraju():
        print('SIM')
    else:
        print('NAO')

# O(n + m)
def solution_tarjan():
    def tarjan():
        stack = []
        is_on_stack = [False] * (n+1)
        visited_index = [0] * (n+1)
        low_link = [0] * (n+1)

        id_count = 0
        scc_count = 0
        def dfs(curr):
            stack.append(curr)
            is_on_stack[curr] = True
            nonlocal id_count, scc_count
            id_count += 1
            visited_index[curr] = low_link[curr] = id_count

            for neighbor in graph[curr]:
                if visited_index[neighbor] == 0:
                    dfs(neighbor)
                if is_on_stack[neighbor]:
                    low_link[curr] = min(low_link[curr], low_link[neighbor])
            
            if visited_index[curr] == low_link[curr]:
                while True:
                    v = stack.pop()
                    is_on_stack[v] = False
                    low_link[v] = visited_index[curr]
                    if v == curr:
                        break
                scc_count += 1
        for i in range(1, n+1):
            if visited_index[i] != 0:
                continue
            dfs(i)

        return scc_count

    scc_count = tarjan()
    if scc_count == 1:
        print('SIM')
    else:
        print('NAO')

# brute_force()
solution_kosaraju()
# solution_tarjan() # Note: Doesn't work for python does recursion limit exceeded
