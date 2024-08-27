#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    printf("Enter x, y : ");
    scanf("%d %d", &x, &y);
    x = x + y;
    y = x - y;
    x = x - y;
    printf("x = %d\t y = %d\n", x,y);
    return 0;
}
