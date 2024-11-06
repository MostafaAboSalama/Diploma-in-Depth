#include <stdio.h>

void reverseArr(int arr[], int size);

int main(void)
{
    int arr[5]={1,2,3,4,5};
    reverseArr(arr, 5);
    for(int i=0; i<5; i++)
        printf("%d\t", arr[i]);
    return 0;
}

void reverseArr(int arr[], int size)
{
    int temp[size];
    for(int i=0; i<size; i++)
        temp[size-1-i] = arr[i];
    for(int i=0; i<size; i++)
        arr[i] = temp[i];
}