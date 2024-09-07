/*
*
********************** Stack.c ***************************
*
*
*/

#include "config.h"
#include "Stack.h"
#include <stdlib.h>

StackError Stack_enumStackErrorInit(Stack* PS)
{
	StackError errorState = NO_ERROR;
	#if StackType == StackArray
		PS->stackTop  = 0;
	
	#elif StackType == StackLinkedList
		PS->size = 0;
		PS->stackTop = NULL;
	
	#endif
	
	return errorState;
}
StackError Stack_enumStackErrorPush(Stack* PS, StackEntry element)   
{
	StackError errorState = NO_ERROR;
	#if StackType == StackArray
		if(Stack_enumStackErrorIsFull(PS) == STACK_FULL)
			return STACK_FULL;
		else
		{	
			PS->stackElements[PS->stackTop] = element;
			PS->stackTop++;
		}
		
	#elif StackType == StackLinkedList
		StackNode* newNode= (StackNode*)malloc(sizeof(StackNode));
		if(newNode == NULL)
			return STACK_NULL;
		
		newNode->value = element;
		newNode->next = PS->stackTop;	
		
		PS->stackTop = newNode;
		PS->size++;
		
	
	#endif
	
	return errorState;
}
StackError Stack_enumStackErrorPop(Stack* PS, StackEntry* element)    
{
	StackError errorState = NO_ERROR;
	#if StackType == StackArray
		if(Stack_enumStackErrorIsEmpty(PS) == STACK_EMPTY)
			return STACK_EMPTY;
		else
		{
			*element = PS->stackElements[PS->stackTop-1];
			PS->stackTop--;
		}
	
	#elif StackType == StackLinkedList
		if(Stack_enumStackErrorIsEmpty(PS) == STACK_EMPTY)
			return STACK_EMPTY;
		
		StackNode* ptrToNode = PS->stackTop;
		*element = ptrToNode->value;		
		PS->stackTop = PS->stackTop->next;
		free(ptrToNode);
		PS->size--;
		 
	#endif
	
	return errorState;
}
StackError Stack_enumStackErrorIsFull(Stack* PS) 
{
	StackError errorState = STACK_NOT_FULL;
	#if StackType == StackArray
		if(PS->stackTop == MAX_ELEMENTS)
			errorState = STACK_FULL;
	
	#endif
	
	return errorState;
}
StackError Stack_enumStackErrorIsEmpty(Stack* PS)
{
	StackError errorState = STACK_NOT_EMPTY;
	#if StackType == StackArray
		if(PS->stackTop == 0)
			errorState = STACK_EMPTY;
	
	#elif StackType == StackLinkedList
		if(PS->size == 0)
			errorState = STACK_EMPTY;
	
	#endif
	
	return errorState;
}
StackError Stack_enumStackErrorSize(Stack* PS, int* size)   
{
	StackError errorState = NO_ERROR;
	#if StackType == StackArray
		*size = PS->stackTop;
	
	#elif StackType == StackLinkedList
		*size = PS->size;
	
	#endif
	
	return errorState;
}
StackError Stack_enumStackErrorTop(Stack* PS, int* top)    
{
	StackError errorState = NO_ERROR;
	#if StackType == StackArray
		*top = PS->stackElements[PS->stackTop-1];

	#elif StackType == StackLinkedList
		*top = PS->stackTop->value;
	
	#endif
	
	return errorState;
}

