#include <stdio.h>
#include <math.h>
double squrt(int x);

int main(void)
{
    int n;
    printf("Enter int : ");
    scanf("%d", &n);
    printf("ans = %0.3lf", squrt(n));
    return 0;
}
double squrt(int x)
{
    return sqrt(x);
}