#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,e,pos;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        printf("%d. Enter number : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be inserted : ");
    scanf("%d",&e);
    printf("Enter the position : ");
    scanf("%d",&pos);
    n++;
    for(int i=n-1; i>pos-2; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos-1]=e;
    for(int i=0; i<n; i++)
    {
        printf("%d\t ",arr[i]);
    }
    return 0;
}
