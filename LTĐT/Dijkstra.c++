#include <iostream>
#include <vector> // vector cung cấp cấu trúc dữ liệu mảng động
#include <queue> // queue cung cấp cấu trúc dữ liệu hàng đợi
#include <climits> // cung cấp các hằng số INT_MAX, LLONG_MAX
using namespace std;

using ll = long long;

const int maxn = 100001; // Số lượng đỉnh tối đa
int n, m, s, t; // Số lượng đỉnh, số lượng cạnh, đỉnh bắt đầu, đỉnh kết thúc
vector<pair<int, int>> adj[maxn];

void nhap() // Hàm nhập dữ liệu đầu vào 
{
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) // Đọc m cạnh của đồ thị
    {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        //adj[y].push_back({x, w}); // Uncomment for undirected graph
    }
}

const int INF = 1e9;
int pre[maxn]; // Mảng lưu đường đi ngắn nhất từ s đến t

void dijkstra(int s) // Thuật toán Dijkstra tìm đường đi ngắn nhất từ s đến các đỉnh còn lại
{
    // Mảng lưu khoảng cách đường đi
    vector<ll> d(n + 1, INF);  // d[i] là khoảng cách ngắn nhất từ s đến i
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> Q;
    // {khoảng cách, đỉnh}
    Q.push({0, s});
    
    while(!Q.empty())
    {
        // Chọn ra đỉnh có khoảng cách từ s nhỏ nhất 
        pair<int, int> top = Q.top(); Q.pop();
        int u = top.second; // Đỉnh u có khoảng cách từ s nhỏ nhất
        int kc = top.first; // Khoảng cách từ s đến u ngắn nhất
        
        if(kc > d[u]) continue;
        
        // Relaxation: Thông qua đỉnh u đã biết khoảng cách ngắn nhất tính từ S,
        // cập nhật khoảng cách với các đỉnh kề với u
        for(auto it : adj[u]) // Duyệt qua các đỉnh kề với u
        {
            int v = it.first; // Đỉnh kề với u 
            int w = it.second; // Trọng số cạnh (u, v)
            if(d[v] > d[u] + w) // Nếu có đường đi ngắn hơn từ s đến v thông qua u
            {
                d[v] = d[u] + w; // Cập nhật khoảng cách ngắn nhất từ s đến v
                Q.push({d[v], v}); // Thêm v vào hàng đợi ưu tiên
                pre[v] = u; // Lưu đường đi
            }
        }
    }
    
    // In kết quả
    for(int i = 1; i <= n; i++)  // In khoảng cách ngắn nhất từ s đến các đỉnh còn lại
    {
        cout << d[i] << ' '; // In khoảng cách ngắn nhất từ s đến i
    }
}

int main() // Hàm main đọc dữ liệu và gọi hàm dijkstra
{ 
    ios::sync_with_stdio(false); // Tắt đồng bộ với stdio, tăng tốc độ xử lý dữ liệu
    cin.tie(nullptr); // Tắt đồng bộ với cin, tăng tốc độ xử lý dữ liệu
    nhap(); // Đọc dữ liệu đầu vào 
    dijkstra(s); // Gọi hàm dijkstra tìm đường đi ngắn nhất từ s đến các đỉnh còn lại
    return 0; // Kết thúc chương trình
}

// Độ phức tạp: O((n + m) log n) với n là số đỉnh, m là số cạnh
// INPUT:
// 5 6 1
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 5 1
// OUTPUT:
// 0 2 3 9 6

// giải thích:
// - Đầu tiên, ta khởi tạo mảng d[] với giá trị INF, d[s] = 0
// - Sau đó, ta thêm đỉnh s vào hàng đợi ưu tiên Q
// - Mỗi lần lặp, ta lấy ra đỉnh u có khoảng cách từ s nhỏ nhất
// - Duyệt qua các đỉnh kề với u, cập nhật khoảng cách nếu có đường đi ngắn hơn
// - Kết thúc thuật toán, mảng d[] chứa khoảng cách ngắn nhất từ s đến các đỉnh còn lại
// - Đường đi từ s đến t có thể được tái tạo từ mảng pre[]
// - Độ phức tạp của thuật toán Dijkstra là O((n + m) log n) với n là số đỉnh, m là số cạnh
// - Đây là một giải pháp hiệu quả để tìm đường đi ngắn nhất trong đồ thị có hướng có trọng số dương
// - Để cải thiện độ phức tạp, có thể sử dụng hàng đợi ưu tiên Fibonacci hoặc cấu trúc dữ liệu khác
// - Để giải quyết bài toán tìm đường đi ngắn nhất trong đồ thị vô hướng, ta có thể sử dụng thuật toán Dijkstra với độ phức tạp O((n + m) log n)
