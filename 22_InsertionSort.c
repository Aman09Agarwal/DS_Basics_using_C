#include <stdio.h>

void printArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertionSort(int *a, int n)
{
    int j, key;
    for (int i = 1; i <= n - 1; i++) // Loop for no. of passes
    {
        j = i - 1;
        key = a[i];
        while (a[j] > key && j >= 0) // Loop for each pass
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    int n = sizeof(a) / sizeof(int);
    printf("Array before sorting :\n");
    printArr(a, n);
    insertionSort(a, n);
    printf("Array after sorting :\n");
    printArr(a, n);
    return 0;
}