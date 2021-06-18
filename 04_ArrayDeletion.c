#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indDeletion(int arr[], int size, int index)
{
    // code for deletion
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, index = 1;
    printf("original array:\n");
    display(arr, size);

    indDeletion(arr, size, index);
    size--;
    printf("new array:\n");
    display(arr, size);

    return 0;
}