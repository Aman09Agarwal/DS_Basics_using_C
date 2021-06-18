#include <stdio.h>
#include <stdlib.h>

void printArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int *a, int mid, int low, int high)
{
    int k = low, i = low, j = mid + 1;
    int b[100];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= high)
    {
        b[k++] = a[j++];
    }
    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int *a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);      // sort left subarray
        mergeSort(a, mid + 1, high); // sort right subarray
        merge(a, mid, low, high);
    }
}

int main()
{
    int a[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 5, 9, 987};
    int n = sizeof(a) / sizeof(int);
    printf("Array before sorting :\n");
    printArr(a, n);
    mergeSort(a, 0, n - 1);
    printf("Array after sorting :\n");
    printArr(a, n);
    return 0;
}