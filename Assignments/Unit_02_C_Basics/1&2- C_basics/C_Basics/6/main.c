#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,temp;
    printf("Enter x, y : ");
    scanf("%d %d", &x, &y);
    temp = x;
    x = y;
    y = temp;
    printf("x = %d\t y = %d\n", x,y);
    return 0;
}
