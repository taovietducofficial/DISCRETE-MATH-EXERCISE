// Thuật toán Prim tìm cây khung bé nhất

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void Prim(int n, vector<vector<pair<int,int>>>& adj) {
    vector<int> key(n + 1, INF); // Lưu trọng số nhỏ nhất để thêm đỉnh vào MST
    vector<bool> inMST(n + 1, false); // Đánh dấu đỉnh đã thêm vào MST
    vector<int> parent(n + 1, -1); // Lưu đỉnh cha trong MST
    
    // Priority queue để chọn cạnh có trọng số nhỏ nhất
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    // Bắt đầu từ đỉnh 0
    key[0] = 0;
    pq.push({0, 0}); // {key, đỉnh}
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (inMST[u]) continue;
        inMST[u] = true;
        
        // Duyệt các đỉnh kề với u
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    
    // In cây khung bé nhất
    int totalWeight = 0;
    cout << "Canh cua cay khung be nhat:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
        totalWeight += key[i];
    }
    cout << "Tong trong so: " << totalWeight << endl;
}

int main() {
    int n, m; // n: số đỉnh, m: số cạnh
    cin >> n >> m;
    
    vector<vector<pair<int,int>>> adj(n);
    
    // Nhập danh sách cạnh có trọng số
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Đồ thị vô hướng
    }
    
    Prim(n, adj);
    
    return 0;
}

/*
Ví dụ input (theo hình vẽ):
6 10
0 1 4
0 2 2
0 4 3
1 2 1
1 3 5
2 3 3
2 4 6
2 5 2
3 5 6
4 5 2

Output:
Canh cua cay khung be nhat:
0 - 2 : 2
2 - 1 : 1
2 - 5 : 2
2 - 3 : 3
4 - 5 : 2
Tong trong so: 10

Độ phức tạp: O((V + E)logV) với V là số đỉnh và E là số cạnh
*/
