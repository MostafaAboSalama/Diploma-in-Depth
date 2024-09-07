#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

QueueError Queue_enumQueueErrorPrint(Queue* PQ)  
{
	QueueError errorState = NO_ERROR;	
	#if QueueType == QueueArray
		int s;
		printf("####### Printing QueueArray ########\n");
		for(int i = PQ->front, s = 0; s < PQ->size; s++)
		{
			printf("%d\t", PQ->queueElements[i]);
			i = (i+1) % MAX_ELEMENTS;
		}
		printf("\n#########################################\n");
	#elif QueueType == QueueLinkedList
		printf("####### Printing QueueLinkedList ########\n");
		QueueNode* currentNode= PQ->front;
		while(currentNode != NULL)
		{
			printf("%d\t", currentNode->value);
			currentNode = currentNode->next;
		}
		printf("\n#########################################\n");
	
	#endif
	
	return errorState;
}

int main()
{
	Queue Q;
	Queue_enumQueueErrorInit(&Q);
	Queue_enumQueueErrorEnqueue(&Q, 10);
	printf("10 is added\n");	
	Queue_enumQueueErrorEnqueue(&Q, 20);
	printf("20 is added\n");	
	Queue_enumQueueErrorEnqueue(&Q, 30);
	printf("30 is added\n");
	Queue_enumQueueErrorPrint(&Q);
	int e; 	
	Queue_enumQueueErrorDequeue(&Q, &e);
	printf("%d is Dequeued\n", e);
	Queue_enumQueueErrorPrint(&Q);
	Queue_enumQueueErrorDequeue(&Q, &e);
	printf("%d is Dequeued\n", e);
	Queue_enumQueueErrorPrint(&Q);
	if(Queue_enumQueueErrorIsFull(&Q) == QUEUE_FULL)
		printf("Queue Full\n");
	else
		printf("Queue NOT Full\n");
    if(Queue_enumQueueErrorIsEmpty(&Q) == QUEUE_EMPTY)
		printf("Queue Empty\n");
	else
		printf("Queue NOT Empty\n");
	Queue_enumQueueErrorEnqueue(&Q, 40);
	printf("40 is added\n");
	Queue_enumQueueErrorPrint(&Q);
    Queue_enumQueueErrorSize(&Q, &e);
	printf("Size = %d\n", e);
    Queue_enumQueueErrorFront(&Q, &e);
	printf("Queue front = %d\n", e);
	return 0;
}