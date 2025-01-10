# Viết bằng Python
# Bài 5: Tính tổ hợp C(n,k) bằng quy hoạch động.

def combination(n, k): # Hàm tính tổ hợp C(n, k).
    dp = [[0] * (k + 1) for _ in range(n + 1)] # Khởi tạo mảng dp.
    for i in range(n + 1): # Duyệt qua tất cả các giá trị của n.
        for j in range(min(i, k) + 1): # Duyệt qua tất cả các giá trị của k.
            if j == 0 or j == i: # Nếu k = 0 hoặc k = n.
                dp[i][j] = 1 # Gán dp[i][j] = 1.
            else:
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] # Công thức tính tổ hợp.
    return dp[n][k]

# Ví dụ
n, k = 5, 2 # Gán n = 5, k = 2.
print(f"C({n}, {k}) = {combination(n, k)}") # In ra kết quả.

# Kết quả
# C(5, 2) = 10
# Độ phức tạp: O(n*k).
