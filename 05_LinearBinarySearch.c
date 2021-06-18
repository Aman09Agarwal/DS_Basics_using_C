#include <stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low = 0, high = size - 1, mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
            return mid;
        if (arr[mid] < element)
            low = mid + 1;
        if (arr[mid] > element)
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int unSortedArray[7] = {74, 14, 54, 63, 754, 49, 8};
    int sortedArray[7] = {8, 14, 49, 54, 63, 74, 754};
    int size = 7, element = 754;
    //Linear Search
    // int searchIndex = linearSearch(unSortedArray,size,element) + 1;
    //Binary Search
    int searchIndex = binarySearch(sortedArray, size, element) + 1;
    if (searchIndex == 0)
        printf("The element %d was not found", element);
    else
        printf("The element %d was found at %dth position", element, searchIndex);
    return 0;
}