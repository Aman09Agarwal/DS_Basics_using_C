#include <stdio.h>

void printArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selectionSort(int *a, int n)
{
    int temp, indexOfMin;
    for (int i = 0; i < n - 1; i++) // Loop for no. of passes
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[indexOfMin] > a[j])
                indexOfMin = j;
        }
        temp = a[i];
        a[i] = a[indexOfMin];
        a[indexOfMin] = temp;
    }
}

int main()
{
    int a[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    int n = sizeof(a) / sizeof(int);
    printf("Array before sorting :\n");
    printArr(a, n);
    selectionSort(a, n);
    printf("Array after sorting :\n");
    printArr(a, n);
    return 0;
}