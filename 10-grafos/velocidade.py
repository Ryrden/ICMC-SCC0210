from collections import deque

# NOTA: Este código é lento e não passou no caso de teste nro 19 mesmo que otimizado utilizando duas representações diferentes do grafo.
# Seu problema se encontra na necessidade de adicionar a aresta reversa na representação de lista de adjacências, o que torna o BFS lento.
# Ao passar o código para C++ com a mesma lógica, o código passou em todos os casos de teste.

n, m = map(int, input().split())

residual_graph = [[0] * (n+1) for _ in range(n+1)]
graph = {i: [] for i in range(1, n+1)}
for _ in range(m):
    u, v, c = map(int, input().split())
    residual_graph[u][v] += c
    graph[u].append(v)
    graph[v].append(u)

def ford_fulkerson(graph, residual_graph, source, sink):
    def bfs(source, sink, parent):
        visited = [False] * (n+1)
        queue = deque([source])
        visited[source] = True
        
        while queue:
            node = queue.popleft()
            for neighbor in graph[node]:
                if not visited[neighbor] and residual_graph[node][neighbor] > 0:
                    queue.append(neighbor)
                    visited[neighbor] = True
                    parent[neighbor] = node
                    if neighbor == sink:
                        return True
        return False
    
    parent = [-1] * (n+1)
    max_flow = 0
    
    while bfs(source, sink, parent):
        # Encontra a menor capacidade residual a partir do caminho encontrado pelo BFS
        path_flow = float("inf")
        temp_sink = sink
        while temp_sink != source:
            parent_node = parent[temp_sink]
            path_flow = min(path_flow, residual_graph[parent_node][temp_sink])
            temp_sink = parent[temp_sink]
        
        max_flow += path_flow

        # Atualiza as capacidades residuais e inverte o caminho encontrado
        temp_sink = sink
        while temp_sink != source:
            parent_node = parent[temp_sink]
            residual_graph[parent_node][temp_sink] -= path_flow
            residual_graph[temp_sink][parent_node] += path_flow
            temp_sink = parent[temp_sink]
        
    return max_flow

source, sink = 1, n
max_flow = ford_fulkerson(graph, residual_graph, source, sink)
print(max_flow)