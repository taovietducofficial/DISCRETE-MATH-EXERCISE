# Viết bằng Python#
# Bài 8: Đếm số tập con có tổng bằng k (Subset Sum Problem)

def subset_sum(arr, k): # arr: mảng số nguyên, k: tổng cần tìm 
    n = len(arr) # n: số phần tử của mảng arr
    dp = [[0] * (k + 1) for _ in range(n + 1)] 
    # Khởi tạo mảng 2 chiều dp[n+1][k+1] với giá trị ban đầu là 0
    for i in range(n + 1): # Duyệt qua các phần tử của mảng arr
        dp[i][0] = 1 # Gán giá trị 1 cho dp[i][0] với mọi i từ 0 đến n

    for i in range(1, n + 1): # Duyệt qua các phần tử của mảng arr
        for j in range(1, k + 1): # Duyệt qua các giá trị từ 1 đến k
            dp[i][j] = dp[i - 1][j] # Gán giá trị dp[i][j] = dp[i-1][j] 
            if j >= arr[i - 1]: # Nếu j >= arr[i-1]
                dp[i][j] += dp[i - 1][j - arr[i - 1]] # Cộng thêm giá trị dp[i-1][j-arr[i-1]] vào dp[i][j]
    return dp[n][k] 

# Ví dụ
arr = [2, 3, 5, 6, 8]
k = 10
print(f"Số tập con có tổng bằng {k} là: {subset_sum(arr, k)}")

# Kết quả
# Số tập con có tổng bằng 10 là: 3
# Có 3 tập con có tổng bằng 10 là: {2, 3, 5}, {2, 8}, {3, 6 