// Viết bằng C
// Bài 18: Giải phương trình đồng dư (Modular Equation).

#include <stdio.h>

// Thuật toán Euclid mở rộng để tìm x, y sao cho ax + by = gcd(a, b)
long long extended_gcd(long long a, long long b, long long *x, long long *y) 
// Thuật toán Euclid mở rộng 
{
    if (b == 0)  // Nếu b = 0 thì trả về a, x = 1, y = 0
    {
        *x = 1; // x = 1 
        *y = 0; // y = 0
        return a;
    }
    long long x1, y1; // Khai báo biến x1, y1
    long long gcd = extended_gcd(b, a % b, &x1, &y1); // Gọi đệ quy với b, a % b
    *x = y1; // x = y1
    *y = x1 - (a / b) * y1; // y = x1 - (a / b) * y1 
    return gcd;
}

// Giải phương trình đồng dư ax ≡ b (mod m)
void solve_modular_equation(long long a, long long b, long long m)  // Hàm giải phương trình đồng dư
{
    long long x, y; // Khai báo biến x, y
    long long gcd = extended_gcd(a, m, &x, &y); // Gọi extended_gcd để tìm gcd, x, y

    // Kiểm tra xem b có chia hết cho gcd hay không
    if (b % gcd != 0)   // Nếu b không chia hết cho gcd
    {
        printf("No solution\n");
        return;
    }

    // Nhân x với b/gcd để tìm nghiệm đầu tiên
    x = x * (b / gcd) % m; // Tính x = x * (b / gcd) % m 
    if (x < 0) x += m; // Nếu x < 0 thì cộng m

    printf("One solution: x = %lld\n", x); 

    // Nếu có nhiều nghiệm
    long long step = m / gcd; // Bước nhảy
    printf("All solutions: x = %lld + k * %lld (k ∈ ℤ)\n", x, step);
}

int main() 
{
    long long a = 3, b = 2, m = 7; // a = 3, b = 2, m = 7
    solve_modular_equation(a, b, m);
    return 0;
}
