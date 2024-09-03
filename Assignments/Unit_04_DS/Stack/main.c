#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

StackError Stack_enumStackErrorPrint(Stack* PS)  
{
	StackError errorState = NO_ERROR;	
	#if StackType == StackArray
		printf("####### Printing StackArray########\n");
		for(int i = PS->stackTop-1; i >= 0; i--)
		{
			printf("%d\n", PS->stackElements[i]);
		}
		printf("##################################\n");
	#elif StackType == StackLinkedList
		printf("####### Printing StackLinkedList########\n");
		StackNode* currentNode = PS->stackTop;
		while(currentNode != NULL)
		{
			printf("%d\n", currentNode->value);
			currentNode = currentNode->next;
		}
		printf("##################################\n");
	
	#endif
	
	return errorState;
}

int main()
{
	Stack S;
	Stack_enumStackErrorInit(&S);
	Stack_enumStackErrorPush(&S, 10);
	printf("10 is added\n");	
	Stack_enumStackErrorPush(&S, 20);
	printf("20 is added\n");	
	Stack_enumStackErrorPush(&S, 30);
	printf("30 is added\n");
	Stack_enumStackErrorPrint(&S);
	int e; 	
	Stack_enumStackErrorPop(&S, &e);
	printf("%d is popped\n", e);
	Stack_enumStackErrorPrint(&S);
	Stack_enumStackErrorPop(&S, &e);
	printf("%d is popped\n", e);
	Stack_enumStackErrorPrint(&S);
	if(Stack_enumStackErrorIsFull(&S) == STACK_FULL)
		printf("Stack Full\n");
	else
		printf("Stack NOT Full\n");
    if(Stack_enumStackErrorIsEmpty(&S) == STACK_EMPTY)
		printf("Stack Empty\n");
	else
		printf("Stack NOT Empty\n");
	Stack_enumStackErrorPush(&S, 30);
	printf("30 is added\n");
	Stack_enumStackErrorPrint(&S);
    Stack_enumStackErrorSize(&S, &e);
	printf("size = %d\n", e);
    Stack_enumStackErrorTop(&S, &e);
	printf("stack top = %d\n", e);
	return 0;
}