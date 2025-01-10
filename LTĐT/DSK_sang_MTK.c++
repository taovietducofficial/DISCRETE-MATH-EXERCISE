// Danh sách kề sang ma trận kề

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; // số đỉnh
    cin >> n;
    vector<vector<int>> adj(n + 1); // danh sách kề
    int a[1001][1001] = {0}; // ma trận kề
    
    // Nhập danh sách kề
    for (int i = 1; i <= n; i++) {
        int k; // số đỉnh kề với đỉnh i
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
            a[i][x] = 1; // đánh dấu trong ma trận kề
        }
    }
    
    // In ma trận kề
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

// Độ phức tạp: O(n^2) với n là số đỉnh của đồ thị
// Input:
// 4
// 1 2
// 2 1 3
// 2 2 4
// 1 3
// Output:
// 0 1 0 0
// 1 0 1 0
// 0 1 0 1
// 0 0 1 0
// Giải thích: Đồ thị có 4 đỉnh, mỗi dòng của input là danh sách các đỉnh kề với đỉnh tương ứng
// Output là ma trận kề tương ứng
