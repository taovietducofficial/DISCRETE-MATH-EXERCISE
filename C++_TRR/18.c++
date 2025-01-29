// Viết bằng C++
// Bài 18: Giải phương trình đồng dư (Modular Equation).

#include <iostream>
using namespace std;

// Thuật toán Euclid mở rộng để tìm x, y sao cho ax + by = gcd(a, b)
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Giải phương trình đồng dư ax ≡ b (mod m)
void solve_modular_equation(long long a, long long b, long long m) {
    long long x, y;
    long long gcd = extended_gcd(a, m, x, y);

    // Kiểm tra xem b có chia hết cho gcd hay không
    if (b % gcd != 0) {
        cout << "No solution" << endl;
        return;
    }

    // Nhân x với b/gcd để tìm nghiệm đầu tiên
    x = (x * (b / gcd)) % m;
    if (x < 0) x += m;

    cout << "One solution: x = " << x << endl;

    // Nếu có nhiều nghiệm
    long long step = m / gcd;
    cout << "All solutions: x = " << x << " + k * " << step << " (k ∈ ℤ)" << endl;
}

int main() {
    long long a = 3, b = 2, m = 7;
    solve_modular_equation(a, b, m);
    return 0;
}
