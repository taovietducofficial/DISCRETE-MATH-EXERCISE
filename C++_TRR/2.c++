// Viết bằng C++
// Bài 2: Sinh chỉnh hợp (Permutation).

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void generatePermutations(vector<int>& arr, int l, int r) {
    if (l == r) {
        for (int i : arr)
            cout << i << " ";
        cout << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(arr[l], arr[i]);
            generatePermutations(arr, l + 1, r);
            swap(arr[l], arr[i]);
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    cout << "Chỉnh hợp:\n";
    generatePermutations(arr, 0, arr.size() - 1);
    return 0;
}
