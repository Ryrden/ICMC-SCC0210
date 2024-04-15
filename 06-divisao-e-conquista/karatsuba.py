def karatsuba(x, y):
    if len(x) == 1 or len(y) == 1:
        return bin(int(x, 2) * int(y, 2))[2:]

    max_len = max(len(x), len(y))
    x = x.zfill(max_len)
    y = y.zfill(max_len)
    
    n = max_len // 2
    x_high, x_low = x[:-n], x[-n:]
    y_high, y_low = y[:-n], y[-n:]

    z0 = karatsuba(x_low, y_low)
    z1 = karatsuba(bin(int(x_high, 2) + int(x_low, 2))[2:], bin(int(y_high, 2) + int(y_low, 2))[2:])
    z2 = karatsuba(x_high, y_high)

    z2_shifted = z2 + '0' * (2 * n)
    z1_shifted = bin(int(z1, 2) - int(z2, 2) - int(z0, 2))[2:].zfill(len(z2) + n) + '0' * n

    result = bin(int(z2_shifted, 2) + int(z1_shifted, 2) + int(z0, 2))[2:]

    return result

# Exemplo de uso
n = int(input())
x = input()
y = input()
resultado = karatsuba(x, y)
if resultado == "0":
    print("0" *n + "0")
else:
    print(resultado)
