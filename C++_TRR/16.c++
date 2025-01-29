// Viết bằng C++
// Bài 16: Tính lũy thừa nhanh (Fast Exponentiation).

#include <iostream>
using namespace std;

long long fast_exponentiation(long long a, long long b, long long mod) 
{
    long long result = 1;
    while (b > 0) 
    {
        if (b % 2 == 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

int main() 
{
    cout << fast_exponentiation(2, 10, 1000) << endl;  // Output: 24
    return 0;
}
