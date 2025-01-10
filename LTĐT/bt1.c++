// Cài đặt thuật toán Duyệt theo chiều rộng (BFS)
#include <iostream>  // Thư viện nhập xuất cơ bản
#include <queue>     // Thư viện hàng đợi để thực hiện BFS
#include <vector>    // Thư viện vector để lưu danh sách kề

using namespace std;

void Tree_BFS(int root, vector<vector<int>>& adj) {
    queue<int> QUEUE;                        // Khai báo hàng đợi để lưu các đỉnh cần duyệt
    vector<int> ChuaXet(adj.size(), 1);      // Mảng đánh dấu các đỉnh chưa xét, khởi tạo tất cả = 1
    
    QUEUE.push(root);                        // Đưa đỉnh gốc vào hàng đợi
    ChuaXet[root] = 0;                       // Đánh dấu đỉnh gốc đã được xét
    
    while (!QUEUE.empty()) {                 // Lặp khi hàng đợi còn phần tử
        int u = QUEUE.front();               // Lấy đỉnh đầu hàng đợi
        QUEUE.pop();                         // Xóa đỉnh đầu hàng đợi
        cout << u << " ";                    // In ra đỉnh vừa xét
        
        for (int v : adj[u]) {              // Duyệt tất cả các đỉnh kề với u
            if (ChuaXet[v] == 1) {          // Nếu đỉnh v chưa được xét
                QUEUE.push(v);               // Thêm v vào hàng đợi
                ChuaXet[v] = 0;             // Đánh dấu v đã được xét
            }
        }
    }
}

int main() {
    int n, m;                               // n là số đỉnh, m là số cạnh
    cin >> n >> m;                          // Nhập số đỉnh và số cạnh
    
    vector<vector<int>> adj(n + 1);         // Khai báo danh sách kề với n+1 phần tử
    
    // Nhập các cạnh của đồ thị
    for (int i = 0; i < m; i++) {
        int u, v;                           // u, v là 2 đỉnh của cạnh
        cin >> u >> v;                      // Nhập 2 đỉnh u, v
        adj[u].push_back(v);                // Thêm v vào danh sách kề của u
        adj[v].push_back(u);                // Thêm u vào danh sách kề của v (đồ thị vô hướng)
    }
    
    cout << "BFS traversal starting from vertex 1: ";  // In thông báo bắt đầu duyệt BFS
    Tree_BFS(1, adj);                       // Gọi hàm BFS bắt đầu từ đỉnh 1
    
    return 0;                               // Kết thúc chương trình
}

// Ví dụ cách chạy:
// Input:
// 6 5     // 6 đỉnh, 5 cạnh
// 1 2     // Cạnh nối đỉnh 1 và 2
// 1 3     // Cạnh nối đỉnh 1 và 3
// 2 4     // Cạnh nối đỉnh 2 và 4
// 2 5     // Cạnh nối đỉnh 2 và 5
// 3 6     // Cạnh nối đỉnh 3 và 6

// Output:
// BFS traversal starting from vertex 1: 1 2 3 4 5 6

