#include <stdio.h>

int main(void)
{
    int x;
    printf("Enter number : ");
    scanf("%d", &x);
    if(x==0)
        printf("You entered zero.");
    else if(x>0)
        printf("You entered positive.");
    else
        printf("You entered negative.");
    return 0;
}
