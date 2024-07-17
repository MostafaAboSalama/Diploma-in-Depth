#include <stdio.h>

int main(void)
{
    char ch;
    printf("Enter a char : ");
    scanf(" %c",&ch);
    if(ch >= 'A' && ch <='z')
        printf("You entered an alphabet.");
    else
        printf("You entered non alphabet.");
    return 0;
}
