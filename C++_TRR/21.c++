// Viết bằng C++
// Bài 21: Tìm đường đi ngắn nhất (Dijkstra).

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; // Định nghĩa kiểu dữ liệu pair<int, int>
const int INF = numeric_limits<int>::max(); // Khai báo INF = numeric_limits<int>::max()
 
vector<int> dijkstra(vector<vector<pii>>& graph, int start)  // Hàm Dijkstra
{
    int n = graph.size(); // Gán n = graph.size()
    vector<int> dist(n, INF); // Khởi tạo vector dist với n phần tử, mỗi phần tử bằng INF
    priority_queue<pii, vector<pii>, greater<pii>> pq;  
    // Khai báo priority_queue với kiểu dữ liệu là pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>

    dist[start] = 0;
    pq.push({0, start}); // Thêm {0, start} vào pq

    while (!pq.empty())  // Vòng lặp while với điều kiện pq không rỗng
    {
        int current_dist = pq.top().first, u = pq.top().second;
        pq.pop(); // Xóa phần tử đầu tiên của pq
        if (current_dist > dist[u]) continue; // Nếu current_dist > dist[u] thì tiếp tục vòng lặp

        for (auto [v, weight] : graph[u])  // Vòng lặp for với mỗi phần tử [v, weight] trong graph[u]
        {
            int distance = current_dist + weight; // Gán distance = current_dist + weight
            if (distance < dist[v])  // Nếu distance < dist[v]
            {
                dist[v] = distance; // Gán dist[v] = distance
                pq.push({distance, v}); // Thêm {distance, v} vào pq
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<pii>> graph =  // Khai báo vector graph
    {
        {{1, 4}, {2, 1}},
        {{3, 1}},
        {{1, 2}, {3, 5}},
        {}
    };

    vector<int> result = dijkstra(graph, 0); // Gán result = dijkstra(graph, 0)
    for (int i = 0; i < result.size(); i++)  // Vòng lặp for từ 0 đến result.size()
    {
        cout << "Khoảng cách từ 0 đến " << i << " là " << result[i] << endl;
    }
    return 0;
}
