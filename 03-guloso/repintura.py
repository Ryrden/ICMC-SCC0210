t = int(input())
for _ in range(t):
    n, m = map(int, input().split())

    # read a matrix of n x m
    ll = []


    if (sum(ch == 'B' for ch in ll) == 0):
        print("0 0")
        continue

    line = n
    columnF = float('inf')
    columnL = float('-inf')

    for i in range(n):
        found = False
        for j in range(m):
            if ll[i][j] == 'B':
                found = True
                line = i
                break
        if found:
            break
    
    for i in range(m):
        for j in range(n):
            if ll[j][i] == 'B':
                columnF = min(columnF, i)
                columnL = max(columnL, i)

    line = n - line
    print(line, columnL - columnF + 1)
