def knight_moves(x, y):
    moves = [(x + 2, y + 1), (x + 2, y - 1), (x - 2, y + 1), (x - 2, y - 1), 
             (x + 1, y + 2), (x + 1, y - 2), (x - 1, y + 2), (x - 1, y - 2)]
    return [(nx, ny) for nx, ny in moves if 1 <= nx <= 8 and 1 <= ny <= 8]

def pos_to_coord(pos):
    return (ord(pos[0]) - ord('a') + 1, int(pos[1]))

def solve_chess_problem(rook_pos, knight_pos):
    rook_x, rook_y = pos_to_coord(rook_pos)
    knight_x, knight_y = pos_to_coord(knight_pos)
    
    # Inicializa o tabuleiro com True (posições seguras)
    board = [[True for _ in range(8)] for _ in range(8)]
    
    # Marca as posições ameaçadas pela torre
    for i in range(8):
        board[rook_x - 1][i] = False  # Coluna
        board[i][rook_y - 1] = False  # Linha
    
    # Marca as posições ameaçadas pelo primeiro cavalo e a posição do próprio cavalo
    for move in knight_moves(knight_x, knight_y):
        board[move[0] - 1][move[1] - 1] = False
    board[knight_x - 1][knight_y - 1] = False  # Posição atual do cavalo

    # Conta as posições seguras para o segundo cavalo
    safe_positions = 0
    for x in range(1, 9):
        for y in range(1, 9):
            if board[x - 1][y - 1]:  # Se a posição está segura
                # Assume inicialmente que a posição é segura para um novo cavalo
                is_safe = True
                # Verifica se colocar um cavalo aqui ameaça o primeiro cavalo
                for move in knight_moves(x, y):
                    if move == (knight_x, knight_y):
                        is_safe = False
                        break
                # Se a posição é segura, incrementa o contador
                if is_safe:
                    safe_positions += 1

    return safe_positions

rook = input()
knight = input()

print(solve_chess_problem(rook, knight) - 2)
