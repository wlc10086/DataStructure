#include "ListQueue.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

Status InitQueue(ListQueue* Q){

	assert(Q != NULL);
	
	// 空节点
	QNode* pNode = (QueuePtr)malloc(sizeof(QNode));
	if (pNode == nullptr) {
		return ERROR;
	}
#ifdef _DEBUG
	pNode->data = '*';
#endif // _DEBUG

	pNode->next = NULL;
	Q->front = Q->rear = pNode;
	return OK;
}


int QueueLength(ListQueue *Q)
{
	assert(Q != NULL);
	int length = 0;
	QueuePtr pNode = Q->front;
	while (pNode->next != NULL) {
		++length;
		pNode = pNode->next;
	}
	return length;
}



Boolean QueueEmpty(ListQueue* Q)
{
	assert(Q != NULL);
	return Q->front == Q->rear;
}

// 入队
Status EnQueue(ListQueue* Q, QElemType e)
{
	assert(Q != NULL);
	QueuePtr pNewNode = (QueuePtr)malloc(sizeof(QNode));
	if (pNewNode == NULL) {
		return ERROR;
	}
	pNewNode->data = e;
	pNewNode->next = NULL;

	// insert to rear
	Q->rear->next = pNewNode;
	Q->rear = pNewNode;
	return OK;
}

// 出队
Status DeQueue(ListQueue* Q, QElemType* e)
{
	assert(Q != NULL);

	if (QueueEmpty(Q)) {
		return ERROR;
	}

	QueuePtr pNode = Q->front->next;
	Q->front->next = pNode->next;
	*e = pNode->data;
	free(pNode);
	return OK;
}

void printQueueELem(QElemType e)
{
	printf("%c ", e);
}

void QueueTraverse(ListQueue *Q, visit v)
{
	if (!QueueEmpty(Q)) {
		QueuePtr pNode = Q->front->next;
		while (pNode != NULL) {
			v(pNode->data);
			pNode = pNode->next;
		}
		printf("\n");
	}
	
}
