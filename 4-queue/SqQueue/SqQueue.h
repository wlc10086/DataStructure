#pragma once

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;


#define MAXQSIZE 5

typedef char QElemType;

typedef struct {
	QElemType* base;  // 数据域
	int front; // 队头
	int rear;  // 队尾
}SqQueue;

Status	InitQueue(SqQueue* Q);
int		QueueLength(SqQueue Q);
Boolean QueueEmpty(SqQueue Q);
Status	EnQueue(SqQueue* Q, QElemType e); // 入队
Status  DeQueue(SqQueue* Q, QElemType* e); // 出队

typedef void(*visit)(QElemType e);
void printQueueELem(QElemType e);
void    QueueTraverse(SqQueue Q, visit v);


