// Viết bằng C
// Bài 13: Tìm ước chung lớn nhất (GCD) và bội chung nhỏ nhất (LCM).

#include <stdio.h>

int gcd(int a, int b) // Hàm tìm GCD của 2 số a, b (a > b)
{
    return b == 0 ? a : gcd(b, a % b);  // Đệ quy
}

int lcm(int a, int b)  // Hàm tìm LCM của 2 số a, b (a > b)
{
    return a * b / gcd(a, b);  // Tính LCM từ GCD
}

int main() 
{
    printf("GCD: %d\n", gcd(12, 18)); // GCD: 6 
    printf("LCM: %d\n", lcm(12, 18)); // LCM: 36
    return 0;
}