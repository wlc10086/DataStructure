#include "SqQueue.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "..\ListQueue\ListQueue.h"

Status InitQueue(SqQueue* Q)
{
	assert(Q != NULL);
	Q->base = (QElemType*)malloc(sizeof(QElemType) * MAXQSIZE);
	if (Q->base == NULL) {
		return ERROR;
	}
#ifdef _DEBUG
	for (int i = 0; i < MAXQSIZE; i++) {
		Q->base[i] = 0;
	}
#endif // _DEBUG

	Q->front = Q->rear = 0;
	return OK;
}

int QueueLength(SqQueue Q)
{
	if (Q.rear > Q.front) {
		return Q.rear - Q.front;
	}
	else {
		return Q.rear + MAXQSIZE - Q.front;
	}
}

Boolean QueueEmpty(SqQueue Q)
{
	return Q.front == Q.rear;
}

Status EnQueue(SqQueue* Q, QElemType e)
{
	assert(Q != NULL);
	if (QueueLength(*Q)+1 == MAXQSIZE) {
		return ERROR;
	}
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue* Q, QElemType* e)
{
	assert(Q != NULL);
	if (QueueEmpty(*Q)) {
		return ERROR;
	}

	*e = Q->base[Q->front];
#ifdef _DEBUG
	Q->base[Q->front] = '\0';
#endif // _DEBUG

	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}


void printQueueELem(QElemType e)
{
	printf("%c ", e);
}

void QueueTraverse(SqQueue Q, visit v)
{
	for (int i = Q.front; i != Q.rear; i= (i+1)%MAXQSIZE) {
		v(Q.base[i]);
	}
	printf("\n");
}
