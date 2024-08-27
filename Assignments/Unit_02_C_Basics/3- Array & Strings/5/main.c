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
    printf("Enter the element to be searched : ");
    scanf("%d",&e);
    for(int i=0; i<n; i++)
    {
        if(arr[i]==e)
        {
            pos = i+1;
            break;
        }
    }
    printf("Number found at location %d", pos);
    return 0;
}
