n = int(input())
player = int(input())
piles = list(map(int, input().split(" ")))

def xor_approach(piles):
    xor_sum = 0
    for pile in piles:
        xor_sum ^= pile
    return xor_sum

def grundy_approach(piles):
    dp = [-1] * (max(piles) + 1)

    def calculate_grundy(n):
        if 0 <= n <= 3:
            return n
    
        if dp[n] != -1:
            return dp[n]
        
        # Para valores maiores que 3, precisamos calcular a função de Grundy de maneira recursiva
        grundy_set = set()
        grundy_set.add(calculate_grundy(n-1))
        grundy_set.add(calculate_grundy(n-2))
        grundy_set.add(calculate_grundy(n-3))
        
        # MEX function to find the minimum excludant
        grundy_value = 0
        while grundy_value in grundy_set:
            grundy_value += 1
        dp[n] = grundy_value
        return grundy_value
    
    grundy_total = 0
    for pile in piles:
        grundy_total ^= calculate_grundy(pile)
    return grundy_total

#result = xor_approach(piles)
result = grundy_approach(piles)

if result != 0:
    print(f"Jogador {player} ganhou o jogo!")
else:
    print(f"Jogador {player} perdeu o jogo!")
