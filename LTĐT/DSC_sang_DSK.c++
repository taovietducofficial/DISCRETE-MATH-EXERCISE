// Danh sách cạnh sang danh sách kề

#include <iostream>  // thư viện nhập xuất
#include <vector> // thư viện vector 

using namespace std;

int main() 
{
    int n, m; // n: số đỉnh, m: số cạnh     
    cin >> n >> m; // nhập số đỉnh và số cạnh
    vector<vector<int>> adj(n + 1); // khai báo mảng 2 chiều adj với n+1 phần tử
    for (int i = 0; i < m; i++)  // vòng lặp chạy từ 0 đến m-1
    {
        int u, v; // khai báo biến u, v
        cin >> u >> v; // nhập u, v
        adj[u].push_back(v); // thêm v vào adj[u]
        adj[v].push_back(u); // thêm u vào adj[v]
    }
    for (int u = 1; u <= n; u++)  // vòng lặp chạy từ 1 đến n
    {
        cout << u << ": "; // in ra u và dấu ": " 
        for (int v : adj[u])  // vòng lặp chạy từ 0 đến adj[u].size()-1
        {
            cout << v << " "; // in ra v và dấu " "
        }
        cout << endl; // xuống dòng  
    }
    return 0; // kết thúc chương trình
}

// Độ phức tạp: O(n + m) với n là số đỉnh và m là số cạnh của đồ thị
// Input:
// 4 3
// 1 2
// 2 3
// 3 4
// Output:
// 1: 2
// 2: 1 3
// 3: 2 4
// 4: 3
// Giải thích: Đồ thị có 4 đỉnh và 3 cạnh, cạnh 1-2, 2-3, 3-4
