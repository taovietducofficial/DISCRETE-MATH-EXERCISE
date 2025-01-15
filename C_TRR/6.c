// Viết bằng C
// Bài 6: Sinh hoán vị của một dãy số.

#include <stdio.h>

void swap(int *a, int *b)  // hàm hoán đổi giá trị của hai số
{
    int temp = *a; // biến tạm temp để lưu giá trị của a
    *a = *b; // gán giá trị của b cho a 
    *b = temp; // gán giá trị của temp cho b
}

void generate_permutations(int arr[], int start, int n)  
// sinh hoán vị của một dãy số
{
    if (start == n)  // nếu start bằng n, in ra hoán vị
    {
        for (int i = 0; i < n; i++) // in ra hoán vị
            printf("%d ", arr[i]); // in ra số
        printf("\n");
        return;
    }
    for (int i = start; i < n; i++)  // sinh hoán vị và in ra kết quả
    {
        swap(&arr[start], &arr[i]); // hoán đổi giá trị của hai số
        generate_permutations(arr, start + 1, n); // đệ quy để sinh hoán vị tiếp theo
        swap(&arr[start], &arr[i]); // hoán đổi giá trị của hai số
    }
}

int main() 
{
    int arr[] = {1, 2, 3}; // khởi tạo dãy số 
    int n = sizeof(arr) / sizeof(arr[0]); // số lượng phần tử của dãy
    printf("Hoán vị của mảng:\n"); 
    generate_permutations(arr, 0, n);  // sinh hoán vị của dãy số
    return 0; 
}

// Giải thích:
// Đệ quy: Tại mỗi bước, phần tử hiện tại được hoán đổi với phần tử còn lại trong dãy.
// Khi đạt đến điểm cuối (base case), in ra một hoán vị.