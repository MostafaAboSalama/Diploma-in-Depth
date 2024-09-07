#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

//*******************************
// Function: Queue_enumQueueErrorPrint
// Description: Prints the elements in the queue
//*******************************
QueueError Queue_enumQueueErrorPrint(Queue* PQ)  
{
    QueueError errorState = NO_ERROR;    

    #if QueueType == QueueArray
        int s;
        printf("\n####### Printing QueueArray ########\n");
        for(int i = PQ->front, s = 0; s < PQ->size; s++)
        {
            printf("%d\t", PQ->queueElements[i]);
            i = (i+1) % MAX_ELEMENTS;
        }
        printf("\n#########################################\n");

    #elif QueueType == QueueLinkedList
        printf("\n####### Printing QueueLinkedList ########\n");
        QueueNode* currentNode = PQ->front;
        int i = 0;
        while(currentNode != NULL)
        {
            printf("Record Number: %d\n", ++i);
            printf("Student Name: %s\n", currentNode->value->name);
            printf("Student Age: %d\n", currentNode->value->age);
            printf("Student ID: %d\n", currentNode->value->id);
            printf("Student Marks: %.2lf\n", currentNode->value->marks);
            printf("###########################################\n");
            currentNode = currentNode->next;
        }
        printf("\n#########################################\n");
    #endif
    
    return errorState;
}

//*******************************
// Function: main
// Description: Main program loop for the Student Database
//*******************************
int main()
{
    Queue Q;
    Queue_enumQueueErrorInit(&Q);
    int choice = 0;

    printf("*******************************************\n");
    printf("** Welcome to the Student Database System **\n");
    printf("*******************************************\n");

    while(choice != 12)
    {
        printf("\n\tChoose one of the following options:\n");
        printf("1- Add Student\n"); 
        printf("2- Delete Student\n");
        printf("3- View Student\n"); 
        printf("4- View All Students\n");
        printf("5- Delete All Students\n");
        printf("6- View Student Using Index\n");
        printf("7- View Student Using Reversed Index\n");
        printf("8- Count Number Of Students\n");
        printf("9- Find The Middle Student\n");
        printf("10- Check for Loop in Queue\n");
        printf("11- Reverse The Students Order\n");
        printf("12- Exit\n");
        printf("\n Enter Option Number: ");
        scanf("%d", &choice);

        StudentType* newStudent = NULL;  
        int id;
        int index;

        switch(choice)
        {
            case 1: 
                newStudent = (StudentType*)malloc(sizeof(StudentType));
                SetStudentInfo(newStudent);
                AddStudent(&Q, newStudent);
                break;
            
            case 2: 
                printf("Enter the Student ID: ");
                scanf("%d", &id);
                DeleteStudent(&Q, id);
                break;
                    
            case 3:               
                printf("Enter the Student ID: ");
                scanf("%d", &id);
                ViewStudent(&Q, id);
                break;
                    
            case 4: 
                Queue_enumQueueErrorPrint(&Q);
                break;
                
            case 5: 
                DeleteAllStudents(&Q);
                break;
                
            case 6: 
                printf("Enter The Student Index: ");
                scanf("%d", &index);
                ViewStudentWithIndex(&Q, index);
                break;
            
            case 7:
                printf("Enter The Student Reversed Index: ");
                scanf("%d", &index);
                ViewStudentWithReversedIndex(&Q, index);
                break;
                
            case 8: 
                printf("The Number of Students: %d\n", CountNumberOfStudents(&Q, Q.front));
                break;
                
            case 9:       
                ViewMiddleStudent(&Q);
                break;
                
            case 10:       
                IsThereALoop(&Q);
                break;
                
            case 11:       
                ReverseTheStudentsOrder(&Q);
                break;

            case 12:
                printf("Exiting the Student Database System. Goodbye!\n");
                break;

            default:
                printf("Invalid Option. Please try again.\n");
                break;
        }
    }
    
    return 0;
}
