t = input()
s = input()

def lps(s):
    lps = [0] * len(s)
    j = 0
    for i in range(1, len(s)):
        while j > 0 and s[i] != s[j]:
            j = lps[j - 1]
        if s[i] == s[j]:
            j += 1
        lps[i] = j
    return lps

def kmp(t, s):
    lps_s = lps(s)
    j = 0
    count = 0
    for i in range(len(t)):
        while j > 0 and t[i] != s[j]:
            j = lps_s[j - 1]
        if t[i] == s[j]:
            j += 1
        if j == len(s):
            count += 1
            j = lps_s[j - 1]
    return count

# Automato de KMP
# Não foi possível implementar...


res = kmp(t, s)

# Solução apenas usando LPS
# res = sum(num == len(s) for num in lps(s+ "$" + t))

print(res)
