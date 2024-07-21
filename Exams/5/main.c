#include <stdio.h>

#define GET_BIT(X, BIT) ((X) & (1<<(BIT)))

int countOnes(int x);

int main(void)
{
    int n;
    printf("Enter num : ");
    scanf("%d",&n);
    printf("ans = %d", countOnes(n));
    return 0;
}

int countOnes(int x)
{
    int cnt=0;
    for(int i=0; i<32; i++)
    {
        if(GET_BIT(x, i))
            cnt++;
    }
    return cnt;
}