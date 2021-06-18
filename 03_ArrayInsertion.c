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

int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    // code for insertion
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 64, index = 3, capacity = 10, res = 0;
    printf("original array:\n");
    display(arr, size);

    res = indInsertion(arr, size, element, capacity, index);
    if (res == -1)
        printf("array full!");
    else
    {
        size++;
        printf("new array:\n");
        display(arr, size);
    }

    return 0;
}