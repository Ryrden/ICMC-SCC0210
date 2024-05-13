def solve(palitos):
    if sum(palitos) % 4 != 0:
        return False
    tamanho_alvo = sum(palitos) // 4
    palitos.sort(reverse=True)
    total_palitos = len(palitos)
    dp = [-1] * (1 << total_palitos)
    
    def can_form_square(mask, current_sum, count):
        if dp[mask] != -1:
            return dp[mask]
        
        if count == 4:
            return True
        
        if current_sum > tamanho_alvo:
            return False
        
        if current_sum == tamanho_alvo:
            return can_form_square(mask, 0, count + 1)
        
        answer = False
        for i in range(total_palitos):
            if not (mask & (1 << i)) and current_sum + palitos[i] <= tamanho_alvo:
                if can_form_square(mask | (1 << i), current_sum + palitos[i], count):
                    answer = True
                    break
        
        dp[mask] = answer
        return answer
    
    return can_form_square(0, 0, 0)

def solve_without_bitmask(palitos):
    if sum(palitos) % 4 != 0:
        return False
    tamanho_alvo = sum(palitos) // 4
    palitos.sort(reverse=True)
    lados = [0, 0, 0, 0]
    def dfs(idx):
        if idx == len(palitos):
            return tamanho_alvo == lados[0] == lados[1] == lados[2] == lados[3]
        for i in range(4):
            if lados[i] + palitos[idx] <= tamanho_alvo:
                lados[i] += palitos[idx]
                if dfs(idx+1):
                    return True
                lados[i] -= palitos[idx]
    return dfs(0)

t = int(input())
for _ in range(t):
    entrada = list(map(int, input().split()))
    n, *palitos = entrada

    if solve(palitos):
        print("sim")
    else:
        print("nao")