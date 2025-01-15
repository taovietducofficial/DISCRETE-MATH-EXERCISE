// Viết bằng C++
// Bài 6: Sinh hoán vị của một dãy số.

#include <iostream> 
#include <vector>   // std::vector  
#include <algorithm> // std::sort, std::next_permutation
using namespace std;

void generate_permutations(vector<int> &arr) // sinh hoán vị của một dãy số
{
    sort(arr.begin(), arr.end()); // sắp xếp dãy số trước khi sinh hoán vị
    do  // sinh hoán vị và in ra m ekết quả
    {
        for (int num : arr)  // in ra hoán vị 
            cout << num << " "; // in ra số 
        cout << endl;
    } while (next_permutation(arr.begin(), arr.end())); // sinh hoán vị tiếp theo
}

int main() 
{
    vector<int> arr = {1, 2, 3}; // khởi tạo dãy số 
    cout << "Hoán vị của dãy số là:\n"; // in ra thông báo 
    generate_permutations(arr); // sinh hoán vị của dãy số
    return 0;
}

// Giải thích:
// Sử dụng std::next_permutation để sinh tất cả hoán vị theo thứ tự từ điển.
// Trước khi sinh, sắp xếp dãy để đảm bảo tạo ra hoán vị theo thứ tự.

