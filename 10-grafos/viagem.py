import heapq

n, m = map(int, input().split())
graph = {i: [] for i in range(1, n+1)}
for _ in range(m):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))

MOD = 10**9 + 7

def dijkstra(start, end):
    min_cost = [float('inf')] * (n + 1)
    min_cost[start] = 0
    path_count = [0] * (n + 1)
    path_count[start] = 1
    min_flights = [float('inf')] * (n + 1)
    max_flights = [0] * (n + 1)
    min_flights[start] = 0

    heap = [(0, start)]
    while heap:
        cost, u = heapq.heappop(heap)
        
        if cost > min_cost[u]:
            continue
        
        for v, w in graph[u]:
            new_cost = cost + w
            if new_cost < min_cost[v]:
                min_cost[v] = new_cost
                path_count[v] = path_count[u]
                min_flights[v] = min_flights[u] + 1
                max_flights[v] = max_flights[u] + 1
                heapq.heappush(heap, (new_cost, v))
            elif new_cost == min_cost[v]:
                path_count[v] = (path_count[v] + path_count[u]) % MOD
                min_flights[v] = min(min_flights[v], min_flights[u] + 1)
                max_flights[v] = max(max_flights[v], max_flights[u] + 1)

    return min_cost[end], path_count[end], min_flights[end], max_flights[end]

def bellman_ford(n, start, end):
    pass

print(*dijkstra(1, n))