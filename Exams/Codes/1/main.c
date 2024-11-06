#include <stdio.h>

int main(void)
{
    int n, sum=0;
    printf("Enter n : ");
    scanf("%d",&n);
    while(n!=0)
    {
        sum = sum + (n%10);
        n/=10;
    }
    printf("Sum = %d", sum);
    return 0;
}
