#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;
    printf("Enter n of rows and cols : ");
    scanf("%d %d", &row, &col);
    int arr[row][col];
    for(int i =0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("Enter element a%d%d : ", i+1, j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Entered Matrix : \n");
    for(int i =0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("Transpose of Matrix : \n");
    for(int i =0; i<col; i++)
    {
        for(int j=0; j<row; j++)
        {
            printf("%d\t", arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}
