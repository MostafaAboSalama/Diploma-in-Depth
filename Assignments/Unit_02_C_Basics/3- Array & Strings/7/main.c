#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[50];  int size =0;
    printf("Enter a string : ");
    gets(str);
    int i =0;
    while(str[i++])
        size++;
    printf("Size : %d", size);
    return 0;
}
