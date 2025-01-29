# Viết bằng Python
# Bài 17: Thuật toán Euclid mở rộng (Extended Euclidean Algorithm).

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0  # gcd, x, y
    gcd, x1, y1 = extended_gcd(b, a % b)
    return gcd, y1, x1 - (a // b) * y1

print(extended_gcd(30, 20))  # Output: (10, 1, -1)
