#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch = 'A';
    char* ptr = &ch;
    while(*ptr <= 'Z')
    {
        printf("%c\t",*ptr);
        (*ptr)++;
    }
    return 0;
}
