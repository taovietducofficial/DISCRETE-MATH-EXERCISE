// Viết bằng C
// Bài 20: Sinh dãy Fibonacci modulo m.

#include <stdio.h>

// Sinh dãy Fibonacci modulo m
void fibonacci_modulo(int n, int m)  // Hàm sinh dãy Fibonacci modulo m 
{
    long long f1 = 0, f2 = 1, fn; // Khai báo f1 = 0, f2 = 1 
    printf("Fibonacci modulo %d: %lld %lld ", m, f1, f2); 
    
    for (int i = 2; i < n; i++)  // Vòng lặp từ 2 đến n 
    {
        fn = (f1 + f2) % m; // Tính fn = (f1 + f2) % m
        printf("%lld ", fn);
        f1 = f2; // Gán f1 = f2
        f2 = fn; // Gán f2 = fn
    }
    printf("\n");
}

int main() 
{
    int n = 10, m = 100; // n = 10, m = 100
    fibonacci_modulo(n, m);
    return 0;
}
