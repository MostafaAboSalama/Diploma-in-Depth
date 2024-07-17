#include <stdio.h>

int main(void)
{
    int n, fact=1;
    printf("Enter positive int : ");
    scanf("%d",&n);
    if(n==0)
        printf("Factorial of %d = %d", 0, 0);
    else if(n<0)
        printf("Factorial of negative numbers doesn't exist");
    else
    {
        for(int i=2; i<=n; i++)
            fact*=i;
        printf("Factorial of %d = %d", n, fact);
    }
    return 0;
}
