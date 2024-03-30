h = int(input())
ll = list(map(int, input().split()))

ans = 0
ll.sort(reverse=True)

for num in ll:
    ans += 1
    h -= num
    if h <= 0:
        break

if h > 0: 
    print("nao cresce")
else:
    print(ans)
