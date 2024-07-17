#include <stdio.h>

int main(void)
{
    char ch;
    printf("Enter a char : ");
    scanf(" %c", &ch);
    if(ch=='a' || ch=='i' || ch=='e' || ch=='o' || ch=='u' || ch=='A' || ch=='I' || ch=='E' || ch=='O' || ch=='U' )
        printf("%c is vowel.",ch);
    else
        printf("%c is constant.",ch);
    return 0;
}
