t = int(input())
for test in range(1, t+1):
    n = int(input())
    m = {}
    for i in range(n):
        a, b = input().split()
        m[a] = int(b)
    d = int(input())
    task = input()
    print(f"Case {test}: ", end="")
    if task in m:
        days = m[task]
        if days <= d:
            print("Yesss")
        elif days <= d + 5:
            print("Late")
        else:
            print("Do your own homework!")
    else:
        print("Do your own homework!")