from collections import defaultdict

n = int(input())

db = defaultdict(list)
for i in range(n):
    name = input()

    if name not in db:
        db[name] = []
        print("OK")
    else:
        if len(db[name]) == 0:
            db[name].append(1)
            print(f"{name}1")
        else:
            print(f"{name}{db[name][-1] + 1}")
            db[name].append(db[name][-1] + 1)