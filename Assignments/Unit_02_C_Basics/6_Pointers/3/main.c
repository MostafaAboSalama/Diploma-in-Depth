#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[50];
    printf("Enter a string : ");
    gets(str);
    str[strlen(str)] = '\0';
    char* ptr = str;
    for(ptr = &str[strlen(str)-1]; ptr >= &str[0]; ptr--)
    {
        printf("%c", *ptr);
    }

    return 0;
}
