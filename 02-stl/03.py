import heapq
pq = []
while True:
    line = input()
    if line == '#':
        break
    _, id, t = line.split()
    id = int(id)
    t = int(t)
    pq.append((t, id, t))

heapq.heapify(pq)
k = int(input())
ans = []
for _ in range(k):
    t, id, interval = heapq.heappop(pq)
    ans.append(id)
    heapq.heappush(pq, (t + interval, id, interval))

for id in ans:
    print(id)


    