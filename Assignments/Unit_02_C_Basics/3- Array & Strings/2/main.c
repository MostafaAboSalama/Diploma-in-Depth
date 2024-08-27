#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; double avg; double sum = 0.0;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    double* arr = (double*)malloc(n*sizeof(double));
    for(int i=0; i<n; i++)
    {
        printf("%d. Enter number : ",i+1);
        scanf("%lf",&arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
    }
    avg = sum/n;
    printf("Average = %0.2lf", avg);
    return 0;
}
