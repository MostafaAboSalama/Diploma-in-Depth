#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char str[], int size, char* ret);

int main()
{
    char str[100];
    printf("Enter a string : ");
    gets(str);
    char* ret = (char*)malloc(strlen(str)+1);
    reverse(str, strlen(str), ret);
    printf("%s",ret);
    return 0;
}



void reverse(char str[], int size, char* ret)
{
    static int i = 0;
    if (size == 0)
    {
        ret[i] = '\0';
        return;
    }
    else
    {
        ret[i] = str[size - 1];
        i++;
        reverse(str, size - 1, ret);
    }
}
