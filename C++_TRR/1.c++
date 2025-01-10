// Viết bằng C++
// Bài 1: Sinh tổ hợp (Combination).

#include <iostream>
#include <vector>
using namespace std;

void printCombination(vector<int>& arr, vector<int>& data, int start, int end, int index, int r) {
    if (index == r) {
        for (int i = 0; i < r; i++)
            cout << data[i] << " ";
        cout << endl;
        return;
    }

    for (int i = start; i <= end; i++) {
        data[index] = arr[i];
        printCombination(arr, data, i + 1, end, index + 1, r);
    }
}

void generateCombinations(vector<int>& arr, int r) {
    vector<int> data(r);
    printCombination(arr, data, 0, arr.size() - 1, 0, r);
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int r = 2;
    cout << "Tổ hợp:\n";
    generateCombinations(arr, r);
    return 0;
}
