// Viết bằng C
// Bài 11: Thuật toán Sàng Eratosthenes.

#include <stdio.h>
#include <stdbool.h>

void sieve_of_eratosthenes(int n) // n là giới hạn số nguyên tố cần tìm
{
    bool primes[n + 1]; // Tạo mảng đánh dấu với tất cả giá trị là true
    for (int i = 0; i <= n; i++)
    {
        primes[i] = true;  // Khởi tạo mảng đánh dấu True
    }
    primes[0] = primes[1] = false;  // 0 và 1 không phải số nguyên tố

    for (int p = 2; p * p <= n; p++) 
    {
        if (primes[p]) {  // Nếu p là số nguyên tố
            for (int i = p * p; i <= n; i += p) 
            {  // Đánh dấu bội số của p
                primes[i] = false;
            }
        }
    }

    printf("Các số nguyên tố <= %d là: ", n);
    for (int i = 2; i <= n; i++)  // In ra các số nguyên tố từ 2 đến n
    {
        if (primes[i])  // Nếu i là số nguyên tố
        {
            printf("%d ", i);
        }
    }
}

int main() 
{
    sieve_of_eratosthenes(30); 
    // Các số nguyên tố <= 30 là: 2 3 5 7 11 13 17 19 23 29
    return 0;
}