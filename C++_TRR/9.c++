// Viết bằng C++
// Bài 9: Sinh phân hoạch số (Integer Partition).

#include <iostream> 
#include <vector>
using namespace std;

void print_partition(const vector<int>& partition) // In ra phân hoạch 
{
    for (int num : partition) // Duyệt qua các phần tử trong vector partition
        cout << num << " "; // In ra phần tử
    cout << endl;
}

void integer_partition(int n, int max, vector<int>& partition)  // Sinh phân hoạch số
{ 
    if (n == 0)  // Nếu n = 0 thì đã tìm được phân hoạch
    {
        print_partition(partition); // In ra phân hoạch
        return;
    }

    for (int i = max; i >= 1; i--)  // Duyệt qua các số từ max đến 1
    {
        if (n - i >= 0)  // Nếu n - i >= 0 thì thêm số i vào phân hoạch
        {
            partition.push_back(i); // Thêm số i vào phân hoạch
            integer_partition(n - i, i, partition);
            partition.pop_back(); // Xóa số i để thử số tiếp theo
        }
    }
}

int main()  
{
    int n = 5;
    vector<int> partition; // Khởi tạo vector partition rỗng
    cout << "Các phân hoạch của " << n << " là:" << endl;
    integer_partition(n, n, partition);
    return 0;
}
