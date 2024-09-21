#include <stdio.h>
#include <stdlib.h>

typedef struct emp
{
    char name[30];
    int id;
}Employee;

int main()
{
    Employee* e1 = (Employee*)malloc(sizeof(Employee));
    Employee* e2 = (Employee*)malloc(sizeof(Employee));
    Employee* e3 = (Employee*)malloc(sizeof(Employee));
    Employee* array[3] = {e1, e2, e3};
    Employee*(*ptr)[3] = array;
    for(int i=0; i<3; i++)
    {
        printf("Enter the name of [%d] employee then his id : ",i+1);
        scanf("%s %d", &((*ptr)[i]->name), &((*ptr)[i]->id));
    }

    for(int i=0; i<3; i++)
    {
        printf("%s\t%d\n", (*ptr)[i]->name, (*ptr)[i]->id);
    }

    return 0;
}
