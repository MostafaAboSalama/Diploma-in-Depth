#include <stdio.h>

int main(void)
{
    double x, y, z;
    printf("Enter 3 numbers :");
    scanf("%lf %lf %lf", &x, &y, &z);
    if(x > y)
    {
        if(x > z)
            printf("%0.2lf is the largest.", x);
        else
            printf("%0.2lf is the largest.", z);
    }
    else
    if(y > z)
        printf("%0.2lf is the largest.", y);
    else
        printf("%0.2lf is the largest.", z);
    return 0;
}
