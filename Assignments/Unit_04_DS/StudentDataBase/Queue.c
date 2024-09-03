/*
* ***************************************
* ************ Queue.c ******************
* ***************************************
*/

#include "Queue.h"
#include "config.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Initialize the queue based on type
QueueError Queue_enumQueueErrorInit(Queue* PQ)
{
    QueueError errorState = NO_ERROR;
    
    #if QueueType == QueueArray
        PQ->size  = 0;
        PQ->front = 0;
        PQ->rear  = -1;
    
    #elif QueueType == QueueLinkedList
        PQ->size = 0;
        PQ->front = NULL;
    
    #endif
    
    return errorState;
}

// Enqueue an element into the queue
QueueError Queue_enumQueueErrorEnqueue(Queue* PQ, QueueEntry element)   
{
    QueueError errorState = NO_ERROR;
    
    #if QueueType == QueueArray
        if(Queue_enumQueueErrorIsFull(PQ) == QUEUE_FULL)
            return QUEUE_FULL;
        else
        {   
            PQ->rear = (PQ->rear + 1) % MAX_ELEMENTS;
            PQ->queueElements[PQ->rear] = element;
            PQ->size++;
        }
        
    #elif QueueType == QueueLinkedList
        QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
        if(newNode == NULL)
            return QUEUE_NULL;
        
        newNode->value = element;
        newNode->next = NULL;
        
        if(Queue_enumQueueErrorIsEmpty(PQ) == QUEUE_EMPTY)
            PQ->front = newNode;
        else
            PQ->rear->next = newNode;
        
        PQ->rear = newNode;
        PQ->size++;
    
    #endif
    
    return errorState;
}

// Dequeue an element from the queue
QueueError Queue_enumQueueErrorDequeue(Queue* PQ, QueueEntry* element) 
{
    QueueError errorState = NO_ERROR;
    
    #if QueueType == QueueArray
        if(Queue_enumQueueErrorIsEmpty(PQ) == QUEUE_EMPTY)
            return QUEUE_EMPTY;
        else
        {
            *element = PQ->queueElements[PQ->front];
            PQ->front = (PQ->front + 1) % MAX_ELEMENTS;
            PQ->size--;
        }
    
    #elif QueueType == QueueLinkedList
        if(Queue_enumQueueErrorIsEmpty(PQ) == QUEUE_EMPTY)
            return QUEUE_EMPTY;
        
        QueueNode* ptrToNode = PQ->front;
        *element = ptrToNode->value;        
        PQ->front = PQ->front->next;
        free(ptrToNode);
        PQ->size--;
        if(PQ->size == 0)
            PQ->rear = NULL;
         
    #endif
    
    return errorState;
}

// Check if the queue is full
QueueError Queue_enumQueueErrorIsFull(Queue* PQ) 
{
    QueueError errorState = QUEUE_NOT_FULL;
    
    #if QueueType == QueueArray
        if(PQ->size == MAX_ELEMENTS)
            errorState = QUEUE_FULL;
    
    #endif
    
    return errorState;
}

// Check if the queue is empty
QueueError Queue_enumQueueErrorIsEmpty(Queue* PQ)
{
    QueueError errorState = QUEUE_NOT_EMPTY;
    
    #if QueueType == QueueArray
        if(PQ->size == 0)
            errorState = QUEUE_EMPTY;
    
    #elif QueueType == QueueLinkedList
        if(PQ->size == 0)
            errorState = QUEUE_EMPTY;
    
    #endif
    
    return errorState;
}

// Get the current size of the queue
QueueError Queue_enumQueueErrorSize(Queue* PQ, int* size)   
{
    QueueError errorState = NO_ERROR;
    
    #if QueueType == QueueArray
        *size = PQ->size;
    
    #elif QueueType == QueueLinkedList
        *size = PQ->size;
    
    #endif
    
    return errorState;
}

// Get the front element of the queue
QueueError Queue_enumQueueErrorFront(Queue* PQ, QueueEntry* front)    
{
    QueueError errorState = NO_ERROR;
    
    #if QueueType == QueueArray
        *front = PQ->queueElements[PQ->front];

    #elif QueueType == QueueLinkedList
        *front = PQ->front->value;
    
    #endif
    
    return errorState;
}

// Set student information
void SetStudentInfo(StudentType* newStudent) 
{
    printf("Enter the name: ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
    
    fgets(newStudent->name, sizeof(newStudent->name), stdin);
    
    size_t len = strlen(newStudent->name);
    if (len > 0 && newStudent->name[len - 1] == '\n') 
    {
        newStudent->name[len - 1] = '\0';
    }

    printf("Enter the age: ");
    scanf("%d", &newStudent->age);
    
    printf("Enter the id: ");
    scanf("%d", &newStudent->id);
    
    printf("Enter the marks: ");
    scanf("%lf", &newStudent->marks);
    
    while ((c = getchar()) != '\n' && c != EOF); 
}

// Add a student to the queue
void AddStudent(Queue* PQ, StudentType* newStudent)
{
    int exist = 0;
    QueueNode* ptrToNode = PQ->front;
    
    while(ptrToNode != NULL)
    {
        if(ptrToNode->value->id == newStudent->id)
        {           
            exist = 1;
            break;
        }
        ptrToNode = ptrToNode->next;
    }
    if(exist)
        printf("ID Already exists\n");
    else
        Queue_enumQueueErrorEnqueue(PQ, newStudent);
}

// Delete a student from the queue by ID
void DeleteStudent(Queue* PQ, int id)
{
    int exist = 0;
    QueueNode* ptrToNode = PQ->front;
    QueueNode* previousStd = NULL;
    
    while(ptrToNode != NULL)
    {
        if(ptrToNode->value->id == id)
        {
            if(previousStd)
                previousStd->next = ptrToNode->next;
            else
                PQ->front = ptrToNode->next;
            
            exist = 1;
            break;
        }
        previousStd = ptrToNode;
        ptrToNode = ptrToNode->next;
    }
    if(exist)
    {
        free(ptrToNode);
        PQ->size--;
        if(PQ->size == 0)
            PQ->rear = NULL;
    }
    else
        printf("ID Doesn't exist\n");
}

// View student information by ID
void ViewStudent(Queue* PQ, int id)
{
    int exist = 0;
    QueueNode* ptrToNode = PQ->front;
    
    while(ptrToNode != NULL)
    {
        if(ptrToNode->value->id == id)
        {           
            exist = 1;
            break;
        }
        ptrToNode = ptrToNode->next;
    }
    if(exist)
    {
        printf("Student Name = %s\n", ptrToNode->value->name);
        printf("Student Age = %d\n", ptrToNode->value->age);
        printf("Student ID = %d\n", ptrToNode->value->id);
        printf("Student Marks = %.2lf\n", ptrToNode->value->marks);
        printf("###########################################\n");
    }
    else
        printf("ID Doesn't exist\n");
}

// Delete all students from the queue
void DeleteAllStudents(Queue* PQ)
{
    QueueNode* ptrToNode = PQ->front;
    QueueNode* previousStd = PQ->front;
    
    while(ptrToNode != NULL)
    {
        previousStd = ptrToNode;
        ptrToNode = ptrToNode->next;
        free(previousStd);
        PQ->size--;                
    }
    PQ->rear = NULL;
    PQ->front = NULL;
}

// View student information by index
void ViewStudentWithIndex(Queue* PQ, int index)
{
    int exist = 0;
    int i = 1;
    QueueNode* ptrToNode = PQ->front;
    
    while(ptrToNode != NULL)
    {
        if(i == index)
        {           
            exist = 1;
            break;
        }
        ptrToNode = ptrToNode->next;
        i++;
    }
    if(exist)
    {
        printf("Student Name = %s\n", ptrToNode->value->name);
        printf("Student Age = %d\n", ptrToNode->value->age);
        printf("Student ID = %d\n", ptrToNode->value->id);
        printf("Student Marks = %.2lf\n", ptrToNode->value->marks);
        printf("###########################################\n");
    }
    else
        printf("Index Doesn't exist\n");
}

// Count the number of students in the queue recursively
int CountNumberOfStudents(Queue* PQ, QueueNode* ptrToNode)
{
    if(ptrToNode == NULL)
        return 0;
    else
    {
        ptrToNode = ptrToNode->next;
        return 1 + CountNumberOfStudents(PQ, ptrToNode);
    }        
}

// View student information by reversed index
void ViewStudentWithReversedIndex(Queue* PQ, int index)
{
    ViewStudentWithIndex( PQ, (PQ->size - index + 1 ));
}

// View the middle student in the queue
void ViewMiddleStudent(Queue* PQ)
{
    ViewStudentWithIndex( PQ, ((PQ->size / 2) + 1 ));
}

// Check if there's a loop in the linked list queue
void IsThereALoop(Queue* PQ)
{
    int loop = 0;
    QueueNode* slowPtr = PQ->front;
    QueueNode* fastPtr = PQ->front;
    while(fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(fastPtr == slowPtr)
        {
            loop = 1;
            break;
        }
        
    }
    if(loop)
        printf("There is a loop\n");
    else
        printf("There is NOT a loop\n");
}

// Reverse the order of students in the queue
void ReverseTheStudentsOrder(Queue* PQ)
{
    QueueNode* current = PQ->front;
    QueueNode* prev = NULL;
    QueueNode* next = NULL;
    PQ->rear = PQ->front;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    PQ->front = prev;
}
