# Viết bằng Python
# Bài 14: Tìm số Fibonacci thứ n.

# CÁCH 1: ĐỆ QUY 
def fib_recursive(n): # Đệ quy là cách tính số Fibonacci thứ n bằng cách gọi lại chính hàm đó với n-1 và n-2
    """Tính số Fibonacci thứ n bằng đệ quy."""
    if n <= 1:
        return n  # Trường hợp cơ bản
    return fib_recursive(n - 1) + fib_recursive(n - 2)  # Công thức F(n) = F(n-1) + F(n-2)

print(fib_recursive(10))  # Fibonacci thứ 10

# CÁCH 2: QUY HOẠCH ĐỘNG
def fib_dynamic(n): # Quy hoạch động là cách tính số Fibonacci thứ n bằng cách lưu kết quả các số Fibonacci trước đó
    """Tính số Fibonacci thứ n bằng quy hoạch động (DP)."""
    if n <= 1: 
        return n
    dp = [0, 1]  # Lưu kết quả Fibonacci trước đó
    for i in range(2, n + 1): # Tính số Fibonacci thứ n
        dp.append(dp[-1] + dp[-2])  # Công thức F(n) = F(n-1) + F(n-2)
    return dp[n]

print(fib_dynamic(10))  # Fibonacci thứ 10
