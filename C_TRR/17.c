// Viết bằng C
// Bài 17: Thuật toán Euclid mở rộng (Extended Euclidean Algorithm).

#include <stdio.h>

long long extended_gcd(long long a, long long b, long long *x, long long *y)  // Thuật toán Euclid mở rộng
{
    if (b == 0)  // Nếu b = 0 thì trả về a, x = 1, y = 0
    {
        *x = 1, *y = 0; // x = 1, y = 0
        return a;
    }
    long long x1, y1; // Khai báo biến x1, y1
    long long gcd = extended_gcd(b, a % b, &x1, &y1); // Gọi đệ quy với b, a % b
    *x = y1, *y = x1 - (a / b) * y1; // Tính x, y từ x1, y1 
    return gcd;
}

int main() 
{
    long long x, y; // Khai báo biến x, y
    printf("%lld\n", extended_gcd(30, 20, &x, &y));  // Output: 10
    printf("x = %lld, y = %lld\n", x, y);  // x = 1, y = -1
    return 0;
}

