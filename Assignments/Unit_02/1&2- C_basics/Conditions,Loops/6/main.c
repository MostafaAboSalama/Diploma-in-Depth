#include <stdio.h>

int main(void)
{
    int n, sum=0;
    printf("Enter number :");
    scanf("%d", &n);
    printf("Using loop\n");
    for(int i=0; i<=n; i++)
        sum+=i;
    printf("Sum O(n) = %d\n", sum);
    printf("Sum O(1)  = %d\n", n*(n+1)/2);
    return 0;
}
