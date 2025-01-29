// Viết bằng C
// Bài 16: Tính lũy thừa nhanh (Fast Exponentiation).

#include <stdio.h>

long long fast_exponentiation(long long a, long long b, long long mod)  
// Hàm vòng lặp tính lũy thừa nhanh với mod 
{
    long long result = 1; // Khởi tạo kết quả là 1
    while (b > 0) // Vòng lặp với điều kiện b > 0
    {
        if (b % 2 == 1) // Nếu b lẻ 
            result = (result * a) % mod; // Nhân kết quả với a và lấy phần dư cho mod
        a = (a * a) % mod; // Bình phương a và lấy phần dư cho mod
        b /= 2; // Chia b cho 2
    }
    return result;
}

int main() 
{
    printf("%lld\n", fast_exponentiation(2, 10, 1000));  // Output: 24
    return 0;
}
