#include <stdio.h>
#include <stdlib.h>

int factorial(int x);

int main()
{
    int x;
    printf("Enter positive int : ");
    scanf("%d",&x);
    printf("Answer : %d",factorial(x));
    return 0;
}

int factorial(int x)
{
    if(x==1)
        return 1;
    else
        return x*factorial(x-1);
}
