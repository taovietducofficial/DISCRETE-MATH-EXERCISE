// Viết bằng C++
// Bài 3: Sinh tập con của một tập hợp.

#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& arr) {
    int n = arr.size();
    int subsetCount = 1 << n; // 2^n
    for (int i = 0; i < subsetCount; i++) {
        cout << "{ ";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) // Kiểm tra bit j
                cout << arr[j] << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    cout << "Tập con:\n";
    generateSubsets(arr);
    return 0;
}
