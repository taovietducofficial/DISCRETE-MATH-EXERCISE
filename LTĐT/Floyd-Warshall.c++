/*
Đây là chương trình cài đặt thuật toán Floyd-Warshall để tìm đường đi ngắn nhất giữa mọi cặp đỉnh trong đồ thị có trọng số.

1. Cấu trúc dữ liệu:
- n: số đỉnh của đồ thị
- m: số cạnh của đồ thị  
- d[MAXN][MAXN]: ma trận khoảng cách, d[i][j] lưu khoảng cách ngắn nhất từ đỉnh i đến j
- nextVertex[MAXN][MAXN]: ma trận lưu đỉnh kế tiếp, nextVertex[i][j] lưu đỉnh tiếp theo trên đường đi từ i đến j

2. Các hàm chính:

a) void init():
- Khởi tạo ma trận khoảng cách ban đầu:
  + d[i][i] = 0 (khoảng cách từ đỉnh đến chính nó là 0)
  + d[i][j] = INF với i ≠ j (ban đầu chưa có đường đi giữa các đỉnh)
  + nextVertex[i][j] = j (đường đi trực tiếp từ i đến j)

b) void nhap():
- Nhập số đỉnh n và số cạnh m
- Gọi hàm init() để khởi tạo
- Nhập m cạnh của đồ thị, mỗi cạnh gồm:
  + x: đỉnh đầu
  + y: đỉnh cuối  
  + w: trọng số cạnh
- Cập nhật d[x][y] = w

c) void Floyd():
- Cài đặt thuật toán Floyd-Warshall:
- Sử dụng 3 vòng lặp lồng nhau:
  + k: đỉnh trung gian
  + i: đỉnh xuất phát
  + j: đỉnh đích
- Nếu tồn tại đường đi qua k ngắn hơn (d[i][k] + d[k][j] < d[i][j]):
  + Cập nhật khoảng cách ngắn nhất d[i][j] = d[i][k] + d[k][j]
  + Cập nhật đỉnh kế tiếp nextVertex[i][j] = nextVertex[i][k]

d) void path(int s, int t):
- In đường đi ngắn nhất từ đỉnh s đến t:
  + Nếu d[s][t] = INF: không có đường đi
  + Ngược lại: in đường đi bằng cách truy vết qua mảng nextVertex
  + In độ dài đường đi d[s][t]

3. Hàm main():
- Gọi hàm nhap() để đọc dữ liệu
- Gọi Floyd() để tìm đường đi ngắn nhất
- In kết quả cho mọi cặp đỉnh bằng hàm path()

Độ phức tạp: O(n^3) với n là số đỉnh của đồ thị
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = 1e9; // Số vô cùng lớn
const int MAXN = 1001;

int n, m; // n: số đỉnh, m: số cạnh
int d[MAXN][MAXN]; // ma trận khoảng cách
int nextVertex[MAXN][MAXN]; // ma trận lưu đỉnh kế tiếp trong đường đi

void init() {
    // Khởi tạo ma trận khoảng cách ban đầu
    for(int i = 1; i <= n; i++) {   // Duyệt tất cả các đỉnh
        for(int j = 1; j <= n; j++) {   // Duyệt tất cả các đỉnh
            if(i == j) d[i][j] = 0; // Khoảng cách từ đỉnh đến chính nó là 0
            else d[i][j] = INF; // Ban đầu chưa có đường đi giữa các đỉnh
            nextVertex[i][j] = j; // Đường đi trực tiếp từ i đến j
        }
    }
}

void nhap() {
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w; // Nhập cạnh x->y có trọng số w
        d[x][y] = w;
        //d[y][x] = w; // Uncomment nếu là đồ thị vô hướng
    }
}

void Floyd() {
    // Thuật toán Floyd-Warshall
    for(int k = 1; k <= n; k++) { // Đỉnh trung gian
        for(int i = 1; i <= n; i++) { // Đỉnh xuất phát
            for(int j = 1; j <= n; j++) { // Đỉnh đích
                if(d[i][k] != INF && d[k][j] != INF && d[i][j] > d[i][k] + d[k][j]) { 
                // Nếu tồn tại đường đi qua k ngắn hơn (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];    // Cập nhật khoảng cách ngắn nhất
                    nextVertex[i][j] = nextVertex[i][k]; // Cập nhật đỉnh kế tiếp       
                }
            }
        }
    }
}

// In đường đi từ đỉnh s đến t
void path(int s, int t) {   
    if(d[s][t] == INF) {    // Nếu không tồn tại đường đi
        cout << "Khong co duong di tu " << s << " den " << t << endl;
        return;
    }
    cout << "Duong di ngan nhat tu " << s << " den " << t << ": ";
    cout << s;  // In đỉnh xuất phát
    while(s != t) {
        s = nextVertex[s][t]; // Truy vết đỉnh kế tiếp
        cout << " -> " << s;
    }
    cout << "\nDo dai duong di: " << d[s][t] << endl;
}

int main() {
    nhap(); // Nhập dữ liệu
    Floyd(); // Tìm đường đi ngắn nhất
    
    // In kết quả cho tất cả các cặp đỉnh
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) path(i, j); // In đường đi từ i đến j
        }
    }
    return 0;
}

//input:
//4 5
//1 2 1
//1 3 2
//2 3 3
//2 4 4
//3 4 5 

//output:
//Duong di ngan nhat tu 1 den 2: 1 -> 2
//Do dai duong di: 1
//Duong di ngan nhat tu 1 den 3: 1 -> 3
//Do dai duong di: 2
//Duong di ngan nhat tu 1 den 4: 1 -> 3 -> 4
//Do dai duong di: 5
