#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base, power;
    printf("Enter the base, the power : ");
    scanf("%d %d",&base, &power);
    printf("%d",getPower(base,power));
    return 0;
}

int getPower(int base, int power)
{
    static int i =0;
    if(power==i)
        return 1;
    else
    {
        i++;
        return base*getPower(base, power);
    }
}
