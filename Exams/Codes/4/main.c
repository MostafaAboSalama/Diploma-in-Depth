#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char num[], int size);

int main(void)
{
    char num[100];
    printf("Enter num : ");
    gets(num);
    reverse(num, strlen(num) +1);
    return 0;
}

void reverse(char num[], int size)
{
    for(int i=0; i< size; i++)
        printf("%c",num[size-1-i]);
}