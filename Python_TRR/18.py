# Viết bằng Python
# Bài 18: Giải phương trình đồng dư (Modular Equation).

def modular_equation(a, b, m):
    g, x, y = extended_gcd(a, m)
    if b % g != 0:
        return "No solution"
    x = (x * (b // g)) % m
    return x

print(modular_equation(3, 2, 7))  # Output: 5
