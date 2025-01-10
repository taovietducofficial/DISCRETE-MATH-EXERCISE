// Viết bằng C
// Bài 5: Tính tổ hợp C(n,k) bằng quy hoạch động.

#include <iostream>
#include <vector>
using namespace std;

int combination(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][k];
}

int main() {
    int n = 5, k = 2;
    cout << "C(" << n << ", " << k << ") = " << combination(n, k) << endl;
    return 0;
}
