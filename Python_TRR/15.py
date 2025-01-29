# Viết bằng Python
# Bài 15: Tính lũy thừa nhanh (Fast Exponentiation).

# Cách 1: Sử dụng đệ quy
def fib_recursive(n): # F(n) = F(n-1) + F(n-2) với F(0) = 0, F(1) = 1
    """Tính số Fibonacci thứ n bằng đệ quy."""
    if n <= 1: # Trường hợp cơ bản F(0) = 0, F(1) = 1
        return n  # Trường hợp cơ bản
    return fib_recursive(n - 1) + fib_recursive(n - 2)  # Công thức F(n) = F(n-1) + F(n-2)

print(fib_recursive(10))  # Fibonacci thứ 10


# Cách 2: Sử dụng vòng lặp 
def fib_dynamic(n):
    """Tính số Fibonacci thứ n bằng quy hoạch động (DP)."""
    if n <= 1: # Trường hợp cơ bản F(0) = 0, F(1) = 1
        return n 
    dp = [0, 1]  # Lưu kết quả Fibonacci trước đó
    for i in range(2, n + 1): # Tính F(n) từ F(2) đến F(n)
        dp.append(dp[-1] + dp[-2])  # Công thức F(n) = F(n-1) + F(n-2)
    return dp[n]

print(fib_dynamic(10))  # Fibonacci thứ 10
