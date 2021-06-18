#include <stdio.h>
#include <limits.h>

void printArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int maximum(int *a, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void countSort(int *a, int n)
{
    int m = maximum(a, n);
    int b[m + 1];
    for (int i = 0; i < m; i++)
    {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    int j = 0;
    for (int i = 0; i < m;)
    {
        if (b[i] > 0)
        {
            a[j++] = i;
            b[i]--;
        }
        else
            i++;
    }
}

int main()
{
    int a[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 5, 9, 987};
    int n = sizeof(a) / sizeof(int);
    printf("Array before sorting :\n");
    printArr(a, n);
    countSort(a, n);
    printf("Array after sorting :\n");
    printArr(a, n);
    return 0;
}