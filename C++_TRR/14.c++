// Viết bằng C++
// Bài 14: Tìm số Fibonacci thứ n.

// CÁCH 1: ĐỆ QUY
#include <iostream>
using namespace std;

int fib_recursive(int n)  // Hàm đệ quy tìm Fibonacci
{
    if (n <= 1) return n;  // Trường hợp cơ bản
    return fib_recursive(n - 1) + fib_recursive(n - 2);  // Công thức Fibonacci
}

int main()  
{
    cout << fib_recursive(10) << endl;  // Fibonacci thứ 10
    return 0;
}

// CÁCH 2: QUY HOẠCH ĐỘNG
#include <iostream> 
#include <vector>
using namespace std; 

int fib_dynamic(int n) // Hàm quy hoạch động tìm Fibonacci
{
    if (n <= 1) return n; // Trường hợp cơ bản
    
    vector<int> dp(n + 1); // Mảng lưu Fibonacci
    dp[0] = 0, dp[1] = 1; // Gán giá trị cho 2 phần tử đầu tiên

    for (int i = 2; i <= n; i++)  // Tính Fibonacci từ 2 đến n
    {
        dp[i] = dp[i - 1] + dp[i - 2];  // Công thức Fibonacci
    }
    
    return dp[n]; // Trả về số Fibonacci thứ n
}

int main() 
{
    cout << fib_dynamic(10) << endl;  // Fibonacci thứ 10
    return 0;
}
