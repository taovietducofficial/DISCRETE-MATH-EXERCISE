// Viết bằng C
// Bài 4: Tính giai thừa bằng đệ quy.

#include <stdio.h>

long long factorial(int n) 
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() 
{
    int n = 5;
    printf("Giai thừa của %d là: %lld\n", n, factorial(n));
    return 0;
}

