// Viết bằng C
// Bài 7: Số cách xếp n đồ vật vào k hộp.

#include <stdio.h>
#include <math.h>

long long comb(int n, int k)  // Hàm tính toán tổ hợp
{
    long long res = 1; // Khởi tạo biến res = 1
    for (int i = 1; i <= k; i++) // Vòng lặp từ i = 1 đến k
    {
        res *= n--; // res = res * n, n = n - 1
        res /= i; // res = res / i 
    }
    return res;
}

long long distribute_with_order(int n, int k)  
// Hàm tính số cách xếp có thứ tự
{
    return pow(k, n); // Trả về k^n 
}

long long distribute_without_order(int n, int k) 
// Hàm tính số cách xếp không có thứ tự
{
    return comb(n + k - 1, k - 1); 
    // Trả về tổ hợp (n + k - 1, k - 1)
}

int main() 
{
    int n = 5, k = 3; // Khai báo n = 5, k = 3 
    printf("Có thứ tự: %lld\n", distribute_with_order(n, k)); // In ra số cách xếp có thứ tự
    printf("Không có thứ tự: %lld\n", distribute_without_order(n, k)); // In ra số cách xếp không có thứ tự
    return 0;
}

// Kết quả:
// Có thứ tự: 243
// Không có thứ tự: 21
