// Viết bằng C
// Bài 19: Sinh số nguyên tố lớn hơn n.

#include <stdio.h>
#include <math.h>

// Kiểm tra số nguyên tố
int is_prime(int n)  // Hàm kiểm tra số nguyên tố
{
    if (n < 2) return 0; // Nếu n < 2 thì không phải số nguyên tố
    if (n == 2 || n == 3) return 1; // Nếu n = 2 hoặc n = 3 thì là số nguyên tố
    if (n % 2 == 0 || n % 3 == 0) return 0; // Nếu n chia hết cho 2 hoặc 3 thì không phải số nguyên tố
    
    for (int i = 5; i * i <= n; i += 6) // Vòng lặp từ 5 đến căn bậc 2 của n
    {
        if (n % i == 0 || n % (i + 2) == 0) return 0; // Nếu n chia hết cho i hoặc i + 2 thì không phải số nguyên tố
    }
    return 1; // Ngược lại là số nguyên tố
}

// Tìm số nguyên tố lớn hơn n
int next_prime(int n)  // Hàm tìm số nguyên tố lớn hơn n
{
    if (n < 2) return 2;    // Nếu n < 2 thì trả về 2
    n++;
    while (!is_prime(n)) n++; // Tìm số nguyên tố lớn hơn n
    return n;
}

int main() 
{
    int n = 50;
    printf("Số nguyên tố lớn hơn %d là %d\n", n, next_prime(n));
    return 0;
}
