// Viết bằng C
// Bài 1: Sinh tổ hợp (Combination).

#include <stdio.h>

void printCombination(int arr[], int n, int r, int index, int data[], int i) 
{
    if (index == r) 
    {
        for (int j = 0; j < r; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }

    if (i >= n)
        return;

    data[index] = arr[i];
    printCombination(arr, n, r, index + 1, data, i + 1);
    printCombination(arr, n, r, index, data, i + 1);
}

void generateCombinations(int arr[], int n, int r) 
{
    int data[r];
    printCombination(arr, n, r, 0, data, 0);
}

int main() 
{
    int arr[] = {1, 2, 3, 4};
    int n = 4, r = 2;
    printf("Tổ hợp:\n");
    generateCombinations(arr, n, r);
    return 0;
}

