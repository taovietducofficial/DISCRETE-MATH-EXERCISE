// Viết bằng C++
// Bài 11: Thuật toán Sàng Eratosthenes.

#include <iostream>
#include <vector> // Thư viện vector
using namespace std;

void sieve_of_eratosthenes(int n) 
{
    vector<bool> primes(n + 1, true);  // Tạo mảng đánh dấu với tất cả giá trị là true
    primes[0] = primes[1] = false;     // 0 và 1 không phải số nguyên tố

    for (int p = 2; p * p <= n; p++) 
    {
        if (primes[p]) {  // Nếu p là số nguyên tố
            for (int i = p * p; i <= n; i += p) 
            {  // Đánh dấu bội số của p
                primes[i] = false;
            }
        }
    }

    cout << "Các số nguyên tố <= " << n << " là: ";
    for (int i = 2; i <= n; i++) // In ra các số nguyên tố từ 2 đến n
    {
        if (primes[i])  // Nếu i là số nguyên tố
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() 
{
    sieve_of_eratosthenes(30); 
    // Các số nguyên tố <= 30 là: 2 3 5 7 11 13 17 19 23 29
    return 0;
}