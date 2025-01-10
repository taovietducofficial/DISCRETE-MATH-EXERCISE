#include <iostream>
#include <vector> // vector cung cấp cấu trúc dữ liệu mảng động 
#include <climits> // cung cấp các hằng số INT_MAX, LLONG_MAX 
using namespace std;

using ll = long long; // Định nghĩa kiểu dữ liệu long long

const int maxn = 100001;  // Số đỉnh tối đa của đồ thị
int n, m, s;             // n: số đỉnh, m: số cạnh, s: đỉnh xuất phát
vector<pair<int,int>> adj[maxn];  // Danh sách kề lưu các cạnh có trọng số

// Hàm nhập dữ liệu đồ thị
void nhap()
{
    cin >> n >> m >> s;  // Nhập số đỉnh, số cạnh và đỉnh xuất phát
    for(int i = 0; i < m; i++) // Đọc m cạnh của đồ thị có trọng số
    {
        int x, y, w; cin >> x >> y >> w;  // Nhập cạnh x->y có trọng số w
        adj[x].push_back({y, w});  // Thêm cạnh có hướng x->y
        //adj[y].push_back({x, w}); // Uncomment nếu là đồ thị vô hướng
    }
}

const int INF = 1e9;  // Giá trị vô cùng
int pre[maxn];  // Mảng lưu đường đi

// Thuật toán Bellman-Ford tìm đường đi ngắn nhất
void bellmanFord(int s) // s: đỉnh xuất phát
{
    // Khởi tạo mảng khoảng cách
    vector<ll> d(n + 1, INF);  // Ban đầu mọi đỉnh có khoảng cách là vô cùng
    d[s] = 0;  // Khoảng cách từ s đến chính nó là 0
    
    // Lặp n-1 lần để tìm đường đi ngắn nhất
    // Mỗi lần lặp có thể cải thiện được khoảng cách đến một đỉnh
    for(int i = 1; i <= n-1; i++) // Lặp n-1 lần
    {
        // Duyệt qua tất cả các cạnh của đồ thị
        for(int u = 1; u <= n; u++) // Duyệt qua tất cả các đỉnh
        {
            for(auto it : adj[u]) // Duyệt qua tất cả các đỉnh kề với u
            {
                int v = it.first;   // Đỉnh kề
                int w = it.second;  // Trọng số cạnh
                // Nếu có thể cải thiện được khoảng cách đến v
                if(d[u] != INF && d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;  // Cập nhật khoảng cách
                    pre[v] = u;       // Lưu đỉnh trước v trong đường đi ngắn nhất
                }
            }
        }
    }
    
    // Kiểm tra chu trình âm bằng cách chạy thêm một lần nữa
    // Nếu vẫn cải thiện được => có chu trình âm
    bool negative_cycle = false;
    for(int u = 1; u <= n; u++) // Duyệt qua tất cả các cạnh của đồ thị
    {
        for(auto it : adj[u]) // Duyệt qua tất cả các đỉnh kề với u
        {
            int v = it.first; // Đỉnh kề với u
            int w = it.second; // Trọng số cạnh (u, v)
            if(d[u] != INF && d[v] > d[u] + w) // Nếu vẫn cải thiện được khoảng cách đến v
            {
                negative_cycle = true; // Đồ thị có chu trình âm 
                break; // Thoát khỏi vòng lặp   
            }
        }
    }
    
    // In kết quả
    if(negative_cycle) // Nếu có chu trình âm thì không tìm được đường đi ngắn nhất
    {
        cout << "Do thi co chu trinh am\n";  // Không tìm được đường đi ngắn nhất
    }
    else // Nếu không có chu trình âm thì in khoảng cách ngắn nhất từ s đến các đỉnh còn lại
    {
        // In khoảng cách ngắn nhất đến mọi đỉnh
        for(int i = 1; i <= n; i++) // In khoảng cách ngắn nhất từ s đến các đỉnh còn lại
        {
            cout << d[i] << ' '; // In khoảng cách ngắn nhất từ s đến i
        }
    }
}

int main() // Hàm main đọc dữ liệu và gọi hàm bellmanFord
{
    ios::sync_with_stdio(false);  // Tối ưu việc nhập xuất
    cin.tie(nullptr); // Tối ưu việc nhập xuất 
    nhap();  // Nhập dữ liệu
    bellmanFord(s);  // Chạy thuật toán Bellman-Ford
    return 0; // Kết thúc chương trình
}

// Độ phức tạp: O(n*m) với n là số đỉnh, m là số cạnh
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
// giâi thích:
// - Đầu tiên, ta khởi tạo mảng d[] với giá trị INF, d[s] = 0
// - Sau đó, ta lặp n-1 lần, cập nhật khoảng cách từ s đến các đỉnh
// - Cuối cùng, ta kiểm tra xem có chu trình âm không
// - Nếu không có chu trình âm, mảng d[] chứa khoảng cách ngắn nhất từ s đến các đỉnh còn lại
// - Nếu có chu trình âm, ta thông báo không tìm được đường đi ngắn nhất
// - Độ phức tạp: O(n*m) với n là số đỉnh, m là số cạnh
// - Ứng dụng: Tìm đường đi ngắn nhất trong đồ thị có trọng số âm
// - Nhược điểm: Độ phức tạp lớn hơn Dijkstra, không tìm được đường đi ngắn nhất nếu có chu trình âm
// - Ưu điểm: Tìm được đường đi ngắn nhất trong đồ thị có trọng số âm
