// Viết bằng C
// Bài 3: Sinh tập con của một tập hợp.

#include <stdio.h>

void generateSubsets(int arr[], int n) 
{
    int subsetCount = 1 << n; // 2^n
    for (int i = 0; i < subsetCount; i++) 
    {
        printf("{ ");
        for (int j = 0; j < n; j++) 
        {
            if (i & (1 << j)) // Kiểm tra bit j
                printf("%d ", arr[j]);
        }
        printf("}\n");
    }
}

int main() 
{
    int arr[] = {1, 2, 3};
    int n = 3;
    printf("Tập con:\n");
    generateSubsets(arr, n);
    return 0;
}
