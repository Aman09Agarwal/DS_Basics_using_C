#include <stdio.h>

void printArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int *a, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // For no. of pass
    {
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void adaptiveBubbleSort(int *a, int n)
{
    int temp, isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For no. of pass
    {
        printf("Working on pass No. %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted == 1)
            return;
    }
}

int main()
{
    int a[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    int n = sizeof(a) / sizeof(int);
    printf("Array before sorting :\n");
    printArr(a, n);
    bubbleSort(a, n);
    // adaptiveBubbleSort(a,n);
    printf("Array after sorting :\n");
    printArr(a, n);
    return 0;
}