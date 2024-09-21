#include <stdio.h>


#define AREA(R) (3.14*R*R)

int main(void)
{
    double r;
    printf("Enter radius: \n");
    scanf("%lf", &r);
    printf("Area = %0.2lf", AREA(r));
    return 0;
}
