# 1 "Stack.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "Stack.c"







# 1 "config.h" 1
# 11 "config.h"
        
# 11 "config.h"
#pragma message ("Compiling with StackArray")
# 11 "config.h"
# 9 "Stack.c" 2
# 1 "Stack.h" 1





typedef enum Error_State
{
 NO_ERROR,
 STACK_FULL,
 STACK_NOT_FULL,
 STACK_NOT_EMPTY,
 STACK_EMPTY,
 STACK_NULL,
}StackError;


    typedef struct stack
    {
  int stackElements[100];
  int stackTop;
    }Stack;
# 38 "Stack.h"
StackError Stack_enumStackErrorInit (Stack* PS);
StackError Stack_enumStackErrorPush (Stack* PS, int element);
StackError Stack_enumStackErrorPop (Stack* PS, int* element);
StackError Stack_enumStackErrorIsFull (Stack* PS);
StackError Stack_enumStackErrorIsEmpty (Stack* PS);
StackError Stack_enumStackErrorSize (Stack* PS, int* size);
StackError Stack_enumStackErrorTop (Stack* PS, int* top);
StackError Stack_enumStackErrorPrint (Stack* PS);
# 10 "Stack.c" 2

StackError Stack_enumStackErrorInit(Stack* PS)
{
 StackError errorState = NO_ERROR;

  PS->stackTop = 0;







 return errorState;
}
StackError Stack_enumStackErrorPush(Stack* PS, int element)
{
 StackError errorState = NO_ERROR;

  if(Stack_enumStackErrorIsFull(PS) == STACK_FULL)
   return STACK_FULL;
  else
  {
   PS->stackElements[PS->stackTop] = element;
   PS->stackTop++;
  }
# 51 "Stack.c"
 return errorState;
}
StackError Stack_enumStackErrorPop(Stack* PS, int* element)
{
 StackError errorState = NO_ERROR;

  if(Stack_enumStackErrorIsEmpty(PS) == STACK_EMPTY)
   return STACK_EMPTY;
  else
  {
   *element = PS->stackElements[PS->stackTop-1];
   PS->stackTop--;
  }
# 77 "Stack.c"
 return errorState;
}
StackError Stack_enumStackErrorIsFull(Stack* PS)
{
 StackError errorState = STACK_NOT_FULL;

  if(PS->stackTop == 100)
   errorState = STACK_FULL;



 return errorState;
}
StackError Stack_enumStackErrorIsEmpty(Stack* PS)
{
 StackError errorState = STACK_NOT_EMPTY;

  if(PS->stackTop == 0)
   errorState = STACK_EMPTY;







 return errorState;
}
StackError Stack_enumStackErrorSize(Stack* PS, int* size)
{
 StackError errorState = NO_ERROR;

  *size = PS->stackTop;






 return errorState;
}
StackError Stack_enumStackErrorTop(Stack* PS, int* top)
{
 StackError errorState = NO_ERROR;

  *top = PS->stackTop;






 return errorState;
}
