#include <stdio.h>

typedef struct distance
{
    double feet;
    double inch;
}Distance_t;

int main(void)
{
    Distance_t d1, d2,result;
    printf("Enter d1 info: \n");
    printf("Enter d1 feet: ");
    scanf("%lf", &d1.feet);
    printf("Enter d1 inch: ");
    scanf("%lf", &d1.inch);
    printf("Enter d2 info: \n");
    printf("Enter d2 feet: ");
    scanf("%lf", &d2.feet);
    printf("Enter d2 inch: ");
    scanf("%lf", &d2.inch);
    result.feet = d1.feet + d2.feet;
    result.inch = d1.inch + d2.inch;
    if(result.inch > 12)
    {
        result.feet++;
        result.inch -=12;
    }
    printf("result = %0.lf'%0.2lf'", result.feet, result.inch);
    return 0;
}
