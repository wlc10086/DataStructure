#include "SqQueue.h"
#include <assert.h>

int main()
{
	SqQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, 'A');
	EnQueue(&Q, 'B');
	EnQueue(&Q, 'C');

	assert(QueueLength(Q) == 3);
	QElemType e;
	DeQueue(&Q, &e);
	assert(e == 'A');

	
	DeQueue(&Q, &e);
	assert(e == 'B');

	EnQueue(&Q, 'D');
	EnQueue(&Q, 'E');
	EnQueue(&Q, 'F');
	EnQueue(&Q, 'G');
	EnQueue(&Q, 'H');

	QueueTraverse(Q, printQueueELem);

	return 0;
}