// Viết bằng C++
// Bài 17: Thuật toán Euclid mở rộng (Extended Euclidean Algorithm).

#include <iostream>
using namespace std;

long long extended_gcd(long long a, long long b, long long &x, long long &y) 
{
    if (b == 0) 
    {
        x = 1, y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, x1, y1);
    x = y1, y = x1 - (a / b) * y1;
    return gcd;
}

int main() 
{
    long long x, y;
    cout << extended_gcd(30, 20, x, y) << endl;  // Output: 10
    cout << "x = " << x << ", y = " << y << endl;  // x = 1, y = -1
    return 0;
}
