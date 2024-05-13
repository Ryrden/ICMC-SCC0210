from collections import defaultdict

def count_ways(dp, mask, blusa_id):
    if mask == (1 << n) - 1:
        return 1
    
    if blusa_id > m:
        return 0
    
    if dp[mask][blusa_id] != -1:
        return dp[mask][blusa_id]
    
    ans = count_ways(dp, mask, blusa_id + 1)
        
    if blusa_id in pessoa_blusa:
        for person in pessoa_blusa[blusa_id]:
            if (mask & (1 << person)):
                continue
            ans += count_ways(dp, mask | (1 << person), blusa_id + 1)
            ans %= 10 ** 9 + 7

    
    dp[mask][blusa_id] = ans
    return dp[mask][blusa_id]

n, m = map(int, input().split())
pessoa_blusa = defaultdict(list)
for person in range(n):
    entrada = list(map(int, input().split()))
    _, *blusas = entrada
    for blusa in blusas:
        pessoa_blusa[blusa].append(person)

dp = [[-1 for _ in range(m+1)] for _ in range (2 ** n)]

print(count_ways(dp, 0, 1))
