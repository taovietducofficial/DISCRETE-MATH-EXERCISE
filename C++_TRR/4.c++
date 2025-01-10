// Viết bằng C++
// Bài 4: Tính giai thừa bằng đệ quy.

#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int n = 5;
    cout << "Giai thừa của " << n << " là: " << factorial(n) << endl;
    return 0;
}
