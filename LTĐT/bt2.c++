// Cài đặt thuật toán Duyệt theo chiều sâu (DFS)
#include <iostream>
#include <vector>

using namespace std;

void Tree_DFS(int u, vector<vector<int>>& adj, vector<int>& ChuaXet) {
    cout << u << " ";                    // In ra đỉnh đang xét
    ChuaXet[u] = 0;                      // Đánh dấu đỉnh u đã được xét
    
    for (int v : adj[u]) {              // Duyệt các đỉnh kề với u
        if (ChuaXet[v] == 1) {          // Nếu đỉnh v chưa được xét
            Tree_DFS(v, adj, ChuaXet);   // Gọi đệ quy DFS với đỉnh v
        }
    }
}

int main() {
    int n, m;                           // n là số đỉnh, m là số cạnh
    cin >> n >> m;                      // Nhập số đỉnh và số cạnh
    
    vector<vector<int>> adj(n + 1);     // Khai báo danh sách kề
    vector<int> ChuaXet(n + 1, 1);      // Mảng đánh dấu các đỉnh chưa xét
    
    // Nhập các cạnh của đồ thị
    for (int i = 0; i < m; i++) {
        int u, v;                       // u, v là 2 đỉnh của cạnh
        cin >> u >> v;                  // Nhập 2 đỉnh u, v
        adj[u].push_back(v);            // Thêm v vào danh sách kề của u
        adj[v].push_back(u);            // Thêm u vào danh sách kề của v
    }
    
    cout << "DFS traversal starting from vertex 1: ";
    Tree_DFS(1, adj, ChuaXet);         // Gọi DFS bắt đầu từ đỉnh 1
    
    return 0;
}

// Ví dụ input:
// 8 9    
// 1 2    
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7
// 4 8
// 5 8
// 6 7

// Output:
// DFS traversal starting from vertex 1: 1 2 4 5 8 3 6 7

// giải thích:
// 1 2 4 5 8 3 6 7 là các đỉnh được duyệt theo chiều sâu từ đỉnh 1

// cách duyệt:
// 1. duyệt đỉnh 1, đánh dấu đỉnh 1 đã được xét
// 2. duyệt đỉnh 2, đánh dấu đỉnh 2 đã được xét
// 3. duyệt đỉnh 4, đánh dấu đỉnh 4 đã được xét
// 4. duyệt đỉnh 5, đánh dấu đỉnh 5 đã được xét
// 5. duyệt đỉnh 8, đánh dấu đỉnh 8 đã được xét
// 6. duyệt đỉnh 3, đánh dấu đỉnh 3 đã được xét
// 7. duyệt đỉnh 6, đánh dấu đỉnh 6 đã được xét
// 8. duyệt đỉnh 7, đánh dấu đỉnh 7 đã được xét 

