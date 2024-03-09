t = int(input())

for i in range(t):
    x, y = map(int, input().split())
    total = x + 2*y
    if total % 2 == 0:
        if x == 0:
            if y % 2 == 0:
                print("YES")
            else:
                print("NO")
        else:
            print("YES")
    else:
        print("NO")