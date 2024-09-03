#ifndef _STACK_H
#define _STACK_H

#include "config.h"

typedef enum Error_State
{
	NO_ERROR,
	STACK_FULL,
	STACK_NOT_FULL,
	STACK_NOT_EMPTY,
	STACK_EMPTY,
	STACK_NULL,
}StackError;

#if StackType == StackArray
    typedef struct stack
    {
		StackEntry stackElements[MAX_ELEMENTS];
		int stackTop;
    }Stack;

#elif StackType == StackLinkedList
	typedef struct Node
    {
		StackEntry value;
		struct Node* next;
    }StackNode;
		
    typedef struct stack
    {
		StackNode* stackTop;
		int size;
    }Stack;

#endif

StackError Stack_enumStackErrorInit		(Stack* PS);
StackError Stack_enumStackErrorPush		(Stack* PS, StackEntry element);
StackError Stack_enumStackErrorPop 		(Stack* PS, StackEntry* element);
StackError Stack_enumStackErrorIsFull	(Stack* PS);
StackError Stack_enumStackErrorIsEmpty	(Stack* PS);
StackError Stack_enumStackErrorSize		(Stack* PS, int* size);
StackError Stack_enumStackErrorTop		(Stack* PS, int* top);
StackError Stack_enumStackErrorPrint	(Stack* PS);








#endif /* _STACK_H */