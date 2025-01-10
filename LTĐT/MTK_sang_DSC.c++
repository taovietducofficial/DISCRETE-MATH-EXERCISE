// Ma trận kề sang danh sách cạnh

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; // số đỉnh
    cin >> n;
    int a[1001][1001]; // ma trận kề
    
    // Nhập ma trận kề
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    // Chuyển sang danh sách cạnh và in ra
    vector<pair<int,int>> edges; // danh sách cạnh
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] == 1) { // nếu có cạnh nối i và j
                edges.push_back({i, j});
            }
        }
    }
    
    // In kết quả
    cout << n << " " << edges.size() << endl; // số đỉnh và số cạnh
    for (auto e : edges) {
        cout << e.first << " " << e.second << endl;
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
// 4 3
// 1 2
// 2 3
// 3 4
// Giải thích: Đồ thị có 4 đỉnh, ma trận kề biểu diễn các cạnh (1,2), (2,3), (3,4)
