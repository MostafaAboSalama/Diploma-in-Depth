#include <stdio.h>

int main(void)
{
    char op;
    double x, y;
    printf("Enter operator : + or - or * or / : ");
    scanf(" %c",&op);
    printf("Enter two operands : ");
    scanf("%lf %lf", &x, &y);
    switch (op)
    {
        case '+':
            printf("%0.2lf + %0.2lf = %0.2lf\n", x, y, x+y);
            break;
        case '-':
            printf("%0.2lf - %0.2lf = %0.2lf\n", x, y, x-y);
            break;
        case '*':
            printf("%0.2lf * %0.2lf = %0.2lf\n", x, y, x*y);
            break;
        case '/':
            if(y == 0)
                printf("Error division by Zero\n");
            else
                printf("%0.2lf / %0.2lf = %0.2lf\n", x, y, x/y);
            break;
    }
    return 0;
}
