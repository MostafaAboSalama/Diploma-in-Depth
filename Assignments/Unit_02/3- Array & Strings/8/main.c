#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[50]; char rev[50];
    printf("Enter a string : ");
    gets(str);
    for(int i = 0; i<strlen(str); i++)
    {
        rev[strlen(str)-i-1] = str[i];
    }
    printf("%s", rev);
    return 0;
}
