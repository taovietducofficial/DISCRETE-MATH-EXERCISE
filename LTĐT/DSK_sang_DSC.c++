// Danh sách kề sang danh sách cạnh

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; // số đỉnh
    cin >> n;
    vector<vector<int>> adj(n + 1); // danh sách kề
    
    // Nhập danh sách kề
    for (int i = 1; i <= n; i++) {
        int k; // số đỉnh kề với đỉnh i
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    
    // Chuyển sang danh sách cạnh và in ra
    vector<pair<int,int>> edges; // danh sách cạnh
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            if (i < j) { // chỉ lấy một lần mỗi cạnh
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

// Độ phức tạp: O(n + m) với n là số đỉnh và m là số cạnh của đồ thị
// Input:
// 4
// 1 2
// 2 1 3  
// 2 2 4
// 1 3
// Output:
// 4 3
// 1 2
// 2 3  
// 3 4
// Giải thích: Đồ thị có 4 đỉnh, mỗi dòng của input là danh sách các đỉnh kề với đỉnh tương ứng
// Output là danh sách 3 cạnh: (1,2), (2,3), (3,4)
