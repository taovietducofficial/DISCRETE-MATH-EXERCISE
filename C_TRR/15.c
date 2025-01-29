// Viết bằng C
// Bài 15: Tính lũy thừa nhanh (Fast Exponentiation).

// CÁCH 1: ĐỆ QUY
#include <stdio.h>
 
long long fast_exponentiation_recursive(long long a, long long b)  
// Hàm đệ quy tính lũy thừa nhanh
{
    if (b == 0) return 1;  // Cơ sở: a^0 = 1
    long long half = fast_exponentiation_recursive(a, b / 2); // Gọi đệ quy với b/2 
    return (b % 2 == 0) ? (half * half) : (a * half * half); // Trả về kết quả
}

int main() 
{
    printf("%lld\n", fast_exponentiation_recursive(2, 10));  // 1024
    return 0;
}


// CÁCH 2: VÒNG LẶP
#include <stdio.h>

long long fast_exponentiation_iterative(long long a, long long b) 
// Hàm vòng lặp tính lũy thừa nhanh
{
    long long result = 1; // Khởi tạo kết quả là 1 
    while (b > 0)  // Vòng lặp với điều kiện b > 0
    {
        if (b % 2 == 1) result *= a;  // Nếu b lẻ, nhân với a
        a *= a;  // Bình phương a
        b /= 2;  // Chia b cho 2
    }
    return result;
}

int main() 
{
    printf("%lld\n", fast_exponentiation_iterative(2, 10));  // 1024
    return 0;
}
