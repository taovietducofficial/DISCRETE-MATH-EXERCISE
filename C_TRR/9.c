// Viết bằng C
// Bài 9: Sinh phân hoạch số (Integer Partition).

#include <stdio.h>

void print_partition(int arr[], int size)  // In ra phân hoạch 
{
    for (int i = 0; i < size; i++)  // Duyệt qua các phần tử trong mảng arr
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void integer_partition(int n, int max, int arr[], int index)  // Sinh phân hoạch số
{
    if (n == 0)  // Nếu n = 0 thì đã tìm được phân hoạch
    {
        print_partition(arr, index); // In ra phân hoạch
        return;
    }

    for (int i = max; i >= 1; i--)  // Duyệt qua các số từ max đến 1
    {
        if (n - i >= 0)  // Nếu n - i >= 0 thì thêm số i vào phân hoạch
        {
            arr[index] = i; // Thêm số i vào phân hoạch
            integer_partition(n - i, i, arr, index + 1);
        }
    }
}

int main()  
{
    int n = 5;
    int arr[n]; // Khởi tạo mảng arr có kích thước n
    printf("Các phân hoạch của %d là:\n", n); 
    integer_partition(n, n, arr, 0);
    return 0;
}

