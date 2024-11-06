#include <stdio.h>
int sum (int n);

int main(void)
{
    printf("Ans = %d\n", sum(100));
    return 0;
}

int sum (int n)
{
    return ((n*(n+1))/2);
}