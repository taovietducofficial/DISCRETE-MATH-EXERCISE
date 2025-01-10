// Danh sách cạnh sang ma trận kề

#include <iostream> // thư viện nhập xuất

using namespace std;

int n, m; // n: số đỉnh, m: số cạnh 
int a[1001][1001]; // khai báo mảng 2 chiều a với 1001 phần tử

int main() 
{
	cin >> n >> m; // nhập số đỉnh và số cạnh 
	for (int i = 0; i < m; i++) // vòng lặp chạy từ 0 đến m-1
	{
		int x, y; // khai báo biến x, y 
		cin >> x >> y; // nhập x, y 
		a[x][y] = a[y][x] = 1;	// gán a[x][y] = a[y][x] = 1
	}	
	for(int i = 1; i <= n; i++) // vòng lặp chạy từ 1 đến n
	{
		for(int j = 1; j <= n; j++) // vòng lặp chạy từ 1 đến n
		{
			cout << a[i][j] << " "; // in ra a[i][j] và dấu " "
		}
		cout << endl;	// xuống dòng
	}
}

// Độ phức tạp: O(n^2) với n là số đỉnh của đồ thị
// Input:
// 4 3
// 1 2
// 2 3
// 3 4
// Output:
// 0 1 0 0
// 1 0 1 0
// 0 1 0 1
// 0 0 1 0
// Giải thích: Đồ thị có 4 đỉnh và 3 cạnh, cạnh 1-2, 2-3, 3-4

