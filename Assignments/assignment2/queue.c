#include "queue.h"

struct Queue initQueue()
{
	struct Queue q;
	q.currSize=0;
	q.front=NULL;
	q.rear=NULL;
	return q;
}

void enqueue(struct Queue *qPtr, struct Data d)
{
	struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
	newNode->data=d; 
	newNode->next=NULL;
	if (qPtr->currSize==0)
	{
		qPtr->front=newNode;
		qPtr->rear=newNode;
	}
	else
	{
		qPtr->rear->next=newNode;
		qPtr->rear=newNode;
	}
	qPtr->currSize++;
}

struct Data dequeue(struct Queue *qPtr)
{
	
	struct Node *temp=qPtr->front->next;
	struct Data returnData=qPtr->front->data;
	free(qPtr->front);
	qPtr->front=temp;
	qPtr->currSize--;
	if (qPtr->currSize==0)
	{
		qPtr->rear=NULL;
	}
	return returnData;
}
void freeQueue(struct Queue *qPtr)
{
	while (qPtr->currSize>0)
	{
		dequeue(qPtr);
	}

}
