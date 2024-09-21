#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Input the number of elements to store in the array (max 15) : ");
    scanf("%d", &n);
    int arr[n];
    printf("Input 5 number of elements in the array : \n");
    for(int i=0; i<n; i++)
    {
        printf("element - %d : ",i+1);
        scanf("%d", &arr[i]);
    }
    int* ptr = arr;
    printf("The elements of array in reverse order are :\n");
    for(int i=n-1; i>=0; i--)
    {
        printf("element - %d : %d\n",i+1, *(ptr+i));
    }
    return 0;
}
