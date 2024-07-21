#include <stdio.h>
#include <string.h>

void reverseWord(char str[], int size);

int main(void)
{
    char str[] = "Ahmed Mohamed";
    reverseWord(str, strlen(str));
    printf("%s\n",str);
    return 0;
}

void reverseWord(char str[], int size)
{
    char temp1[size + 1]; char temp2[size + 1];
    int i = 0, j = 0;

    for (i = 0; i < size; i++)
    {
        if (str[i] == ' ')
            break;
        temp1[i] = str[i];
    }
    temp1[i] = '\0';
    i++;

    for (; i < size; i++)
    {
        temp2[j++] = str[i];
    }
    temp2[j] = '\0';

    strcpy(str, temp2);
    strcat(str, " ");
    strcat(str, temp1);
}
