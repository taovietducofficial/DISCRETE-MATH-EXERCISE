// Viết bằng C++
// Bài 22: Thuật toán Bellman-Ford

#include <iostream>
#include <vector>
using namespace std;

#define INF 1e9 // Khai báo vô cùng 

void bellmanFord(int V, vector<vector<int>>& edges, int src)  // src là đỉnh nguồn 
{ 
    vector<int> dist(V, INF); // Khoảng cách ngắn nhất từ src đến các đỉnh
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)  // Lặp V-1 lần 
    {
        for (auto edge : edges)  // Duyệt qua tất cả các cạnh
        {
            int u = edge[0], v = edge[1], w = edge[2]; 
            if (dist[u] != INF && dist[u] + w < dist[v])  // Nếu có cách đi ngắn hơn
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto edge : edges)  // Kiểm tra chu trình âm
    {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[u] != INF && dist[u] + w < dist[v]) // Nếu có cách đi ngắn hơn 
        {
            cout << "Đồ thị chứa chu trình âm\n";
            return;
        }
    }

    for (int i = 0; i < V; i++)  // In ra khoảng cách từ src đến các đỉnh
    {
        cout << "Khoảng cách từ " << src << " đến " << i << ": " << dist[i] << endl;
    }
}

int main() 
{
    vector<vector<int>> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    int V = 5;
    bellmanFord(V, edges, 0);
    return 0;
}

