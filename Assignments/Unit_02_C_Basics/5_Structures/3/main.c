#include <stdio.h>

typedef struct number
{
    double real;
    double img;
}ComplexNum_t;

int main(void)
{
    ComplexNum_t n1, n2,sum;
    printf("Enter n1 info: \n");
    printf("Enter n1 real: ");
    scanf("%lf", &n1.real);
    printf("Enter n1 img: ");
    scanf("%lf", &n1.img);
    printf("Enter n2 info: \n");
    printf("Enter n2 real: ");
    scanf("%lf", &n2.real);
    printf("Enter n2 img: ");
    scanf("%lf", &n2.img);
    sum.real = n1.real + n2.real;
    sum.img = n1.img + n2.img;
    printf("result = %0.2lf+i%0.2lf", sum.real,sum.img);
    return 0;
}
