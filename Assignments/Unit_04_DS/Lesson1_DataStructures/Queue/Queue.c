/*
*
********************** Queue.c ***************************
*
*
*/

#include "Queue.h"
#include "config.h"
#include <stdlib.h>

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
QueueError Queue_enumQueueErrorEnqueue(Queue* PQ, QueueEntry element)   
{
	QueueError errorState = NO_ERROR;
	#if QueueType == QueueArray
		if(Queue_enumQueueErrorIsFull(PQ) == QUEUE_FULL)
			return QUEUE_FULL;
		else
		{	
			PQ->rear = (PQ->rear+1) % MAX_ELEMENTS;
			PQ->queueElements[PQ->rear] = element;
			PQ->size++;
		}
		
	#elif QueueType == QueueLinkedList
		QueueNode* newNode= (QueueNode*)malloc(sizeof(QueueNode));
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
QueueError Queue_enumQueueErrorDequeue(Queue* PQ, QueueEntry* element) 
{
	QueueError errorState = NO_ERROR;
	#if QueueType == QueueArray
		if(Queue_enumQueueErrorIsEmpty(PQ) == QUEUE_EMPTY)
			return QUEUE_EMPTY;
		else
		{
			*element = PQ->queueElements[PQ->front];
			PQ->front = (PQ->front+1) % MAX_ELEMENTS;
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
QueueError Queue_enumQueueErrorIsFull(Queue* PQ) 
{
	QueueError errorState = QUEUE_NOT_FULL;
	#if QueueType == QueueArray
		if(PQ->size == MAX_ELEMENTS)
			errorState = QUEUE_FULL;
	
	#endif
	
	return errorState;
}
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

