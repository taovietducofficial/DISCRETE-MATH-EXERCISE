// Viết bằng C++
// Bài 12: Phân tích một số thành tích các thừa số nguyên tố.

#include <iostream>
using namespace std;

void prime_factorization(int n)  // Phân tích một số thành tích các thừa số nguyên tố.
{
    cout << "Thừa số nguyên tố của " << n << " là: ";
    int i = 2;
    while (i * i <= n)  // i * i <= n   <=>   i <= sqrt(n)  <=>   i < sqrt(n) + 1
    {
        while (n % i == 0)  // n chia hết cho i thì in ra i và chia n cho i
        {
            cout << i << " ";
            n /= i;
        }
        i++;
    }
    if (n > 1)  // n còn lại sau khi chia hết cho các i từ 2 đến sqrt(n) thì in ra n
    {
        cout << n;
    }
    cout << endl;
}

int main() 
{
    prime_factorization(84); // Thử nghiệm với số 84    
    return 0;
}
