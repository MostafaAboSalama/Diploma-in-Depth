#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x,y;
    printf("Enter x, y : ");
    scanf("%lf %lf", &x, &y);
    printf("x * y = %0.2lf\n", x*y);
    return 0;
}
