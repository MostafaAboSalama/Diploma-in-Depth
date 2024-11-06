#include <stdio.h>

void bubbleSort(int arr[], int n);
int findUnique(int arr[], int size);

int main(void)
{
    int arr[7] = {4,2,5,2,5,7,4};
    printf("unique = %d\n", findUnique(arr, 7));

    return 0;
}

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    int swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int findUnique(int arr[], int size)
{
    bubbleSort(arr, size);
    for(int i=0; i<size; i++)
    {
        if(i==size-1)
        {
            if(arr[i] != arr[i-1])
                return arr[i];
        }
        else if(i == 0)
        {
            if(arr[i] != arr[i+1])
                return arr[i];
        }
        else
        {
            if(arr[i] != arr[i+1] && arr[i] != arr[i-1])
                return arr[i];
        }
    }
}