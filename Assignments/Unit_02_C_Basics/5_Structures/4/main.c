#include <stdio.h>

#define NUM 10

typedef struct student
{
    char name[30];
    int roll;
    double marks;
}Student_t;

int main(void)
{
    Student_t st[NUM];
    int num;
    for(int i = 0; i < NUM; i++)
    {
        printf("Student Number%d\n",i+1);
        printf("Enter the name: ");
        scanf("%s", st[i].name);
        printf("Enter the roll: ");
        scanf("%d", &st[i].roll);
        printf("Enter the marks: ");
        scanf("%lf", &st[i].marks);
        printf("###############################\n");
    }

    for(int i = 0; i < NUM; i++)
    {
        printf("Student Number%d\n",i+1);
        printf("The name: %s\n", st[i].name);
        printf("The roll: %d\n", st[i].roll);
        printf("The marks: %0.2lf\n", st[i].marks);
        printf("###############################\n");
    }

    return 0;
}
