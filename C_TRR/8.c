// Viết bằng C
// Bài 8: Đếm số tập con có tổng bằng k (Subset Sum Problem)

#include <stdio.h>

int subset_sum(int arr[], int n, int k)  
// arr: mảng các số nguyên, n: số phần tử của mảng, k: tổng cần tìm
{
    int dp[n + 1][k + 1]; // Khởi tạo mảng 2 chiều dp[n+1][k+1] với giá trị ban đầu là 0
    for (int i = 0; i <= n; i++) // Gán giá trị 1 cho dp[i][0] với mọi i từ 0 đến n
        dp[i][0] = 1; // Mỗi tập con rỗng đều có tổng bằng 0
    for (int j = 1; j <= k; j++) // Gán giá trị 0 cho dp[0][j] với mọi j từ 1 đến k
        dp[0][j] = 0; 

    for (int i = 1; i <= n; i++)  // Duyệt qua từng phần tử của mảng arr
    {
        for (int j = 1; j <= k; j++)  // Duyệt qua từng giá trị của k
        {
            dp[i][j] = dp[i - 1][j]; // Gán giá trị của dp[i][j] bằng giá trị của dp[i-1][j]
            if (j >= arr[i - 1]) // Nếu j >= arr[i-1]
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[n][k]; // Trả về giá trị của dp[n][k]
}

int main() 
{
    int arr[] = {2, 3, 5, 6, 8}; // Khởi tạo mảng arr
    int k = 10; // Khởi tạo giá trị k
    int n = sizeof(arr) / sizeof(arr[0]); // Số phần tử của mảng arr
    printf("Số tập con có tổng bằng %d là: %d\n", k, subset_sum(arr, n, k));
    return 0;
}

// kết quả: Số tập con có tổng bằng 10 là: 3
// Giải thích: Có 3 tập con có tổng bằng 10 là {2, 3, 5}, {3, 5, 2}, {8, 2}.
// Độ phức tạp: O(n*k) với n là số phần tử của mảng arr, k là tổng cần tìm.