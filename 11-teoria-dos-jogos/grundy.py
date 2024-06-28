MAXN = 5000 + 5
dp = [-1] * MAXN

def mex(set_of_numbers):
    mex_val = 0
    while mex_val in set_of_numbers:
        mex_val += 1
    return mex_val

def calculate_grundy(n):
    if dp[n] != -1:
        return dp[n]
    
    reachable = set()
    for i in range(1, n // 2 + 1):
        j = n - i
        if i != j:
            reachable.add(calculate_grundy(i) ^ calculate_grundy(j))
    
    dp[n] = mex(reachable)
    return dp[n]

t = int(input())

for n in range(1, MAXN):
    calculate_grundy(n)

for _ in range(t):
    n = int(input())
    result = dp[n]
    
    if result == 0:
        print("segundo")
    else:
        print("primeiro")
