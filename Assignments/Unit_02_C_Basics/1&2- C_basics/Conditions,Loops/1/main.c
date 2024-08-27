#include <stdio.h>

int main(void)
{
    int x;
    printf("Enter integer u want to check : ");
    scanf("%d", &x);
    if(x%2 ==0)
        printf("%d is even",x);
    else
        printf("%d is odd",x);
    return 0;
}
