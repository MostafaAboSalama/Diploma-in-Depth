#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int x);
void prime(void);

int main()
{
    prime();
    return 0;
}

bool isPrime(int x)
{
    if(x==2)
        return true;
    else
        for(int i=2; i<=x/2; i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

void prime(void)
{
    int l,h;
    printf("Enter lower limit, higher limit : ");
    scanf("%d %d",&l,&h);
    for(int i=l; i<=h; i++)
    {
        if(isPrime(i))
            printf("%d\t",i);
    }
}
