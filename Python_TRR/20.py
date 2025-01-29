# Viết bằng Python
# Bài 20: Sinh dãy Fibonacci modulo m.

def fibonacci_modulo(n, m):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, (a + b) % m
    return a

print(fibonacci_modulo(10, 100))  # Output: 55
