// Viết bằng C++ 
// Bài 10: Kiểm tra số nguyên tố (Trial Division).

#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n) 
{
    if (n <= 1) return false; // Số nhỏ hơn hoặc bằng 1 không phải số nguyên tố
    if (n <= 3) return true;  // 2 và 3 là số nguyên tố
    if (n % 2 == 0 || n % 3 == 0) return false; // Loại bỏ các số chia hết cho 2 hoặc 3

    // Kiểm tra các số từ 5 đến √n
    for (int i = 5; i <= sqrt(n); i += 6) 
    {
        if (n % i == 0 || n % (i + 2) == 0) return false; 
        // Không phải số nguyên tố nếu chia hết cho i hoặc i+2
    }
    return true; // Là số nguyên tố
}

int main() {
    int num = 29;
    if (is_prime(num)) // Gọi hàm kiểm tra số nguyên tố
    {
        cout << num << " là số nguyên tố." << endl;
    } 
    else  // Không phải số nguyên tố
    {
        cout << num << " không phải số nguyên tố." << endl;
    }
    return 0;
}
