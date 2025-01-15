// Viết bằng C++
// Bài 7: Số cách xếp n đồ vật vào k hộp.

#include <iostream>
#include <cmath>
using namespace std;

long long comb(int n, int k)  // Hàm tính toán tổ hợp 
{
    long long res = 1; 
    for (int i = 1; i <= k; i++)  // Vòng lặp từ i = 1 đến k
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
    return comb(n + k - 1, k - 1); // Trả về tổ hợp (n + k - 1, k - 1)
}

int main() 
{
    int n = 5, k = 3; // Khai báo n = 5, k = 3 
    cout << "Có thứ tự: " << distribute_with_order(n, k) << endl; 
    // In ra số cách xếp có thứ tự
    cout << "Không có thứ tự: " << distribute_without_order(n, k) << endl; 
    // In ra số cách xếp không có thứ tự
    return 0;
}


