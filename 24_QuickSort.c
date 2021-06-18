#include <stdio.h>

int n;

void printArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int *a, int low, int high)
{
    int pivot = a[low], i = low + 1, j = high, temp;
    do
    {
        while (pivot >= a[i] && i < n)
        {
            i++;
        }
        while (pivot < a[j])
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    // Swap pivot and A[j]
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int *a, int low, int high)
{

    int partitionIndex; // Index of pivot after partition
    if (low < high)
    {
        partitionIndex = partition(a, low, high);
        // printArr(a,n);
        quickSort(a, low, partitionIndex - 1);  // sort left subarray
        quickSort(a, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    int a[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 5, 9, 987};
    // int a[] = {45, 7, 24, 4, 89, 21, 49};
    n = sizeof(a) / sizeof(int);
    printf("Array before sorting :\n");
    printArr(a, n);
    quickSort(a, 0, n - 1);
    printf("Array after sorting :\n");
    printArr(a, n);
    return 0;
}