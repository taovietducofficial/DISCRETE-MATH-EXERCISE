// Ma trận kề sang danh sách kề

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; // số đỉnh
    cin >> n;
    int a[1001][1001]; // ma trận kề
    vector<vector<int>> adj(n + 1); // danh sách kề
    
    // Nhập ma trận kề
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    // Chuyển đổi sang danh sách kề
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }
    
    // In danh sách kề
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}

// Độ phức tạp: O(n^2) với n là số đỉnh của đồ thị
// Input:
// 4
// 0 1 0 0
// 1 0 1 0
// 0 1 0 1
// 0 0 1 0
// Output:
// 1: 2
// 2: 1 3
// 3: 2 4
// 4: 3
// Giải thích: Đồ thị có 4 đỉnh, ma trận kề biểu diễn các cạnh (1,2), (2,3), (3,4)
