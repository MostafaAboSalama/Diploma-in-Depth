#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[50]; char ch; int cnt =0;
    printf("Enter a string : ");
    gets(str);
    printf("Enter a char ");
    scanf(" %c",&ch);
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i]==ch)
            cnt++;
    }
    printf("count = %d", cnt);
    return 0;
}
