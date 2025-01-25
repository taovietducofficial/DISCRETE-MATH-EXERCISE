// Viết bằng C++
// Bài 13: Tìm ước chung lớn nhất (GCD) và bội chung nhỏ nhất (LCM).

#include <iostream>
using namespace std;

int gcd(int a, int b)  // Hàm tìm GCD của 2 số a, b (a > b)
{
    return b == 0 ? a : gcd(b, a % b);  // Đệ quy
}

int lcm(int a, int b) // Hàm tìm LCM của 2 số a, b (a > b)
{
    return a * b / gcd(a, b);  // Tính LCM từ GCD
}

int main() 
{
    cout << "GCD: " << gcd(12, 18) << endl; // GCD: 6 
    cout << "LCM: " << lcm(12, 18) << endl; // LCM: 36
    return 0;
}
