#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a[2][2]; double b[2][2];
    double sum[2][2] = {0};
    for(int i = 0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("a[%d][%d] : ", i,j);
            scanf("%lf",&a[i][j]);
        }
    }

    for(int i = 0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("b[%d][%d] : ", i,j);
            scanf("%lf",&b[i][j]);
        }
    }

    for(int i = 0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            sum[i][j] = a[i][j]+b[i][j];
        }
    }

    for(int i = 0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("sum[%d][%d] : %0.2lf\t", i,j, sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}
