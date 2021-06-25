#pragma once

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;


typedef char QElemType;

// 链队结点的类型
typedef struct QNode
{
    QElemType       data;  // 数据域
    struct QNode    *next;// 指针域
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front; // 队头指针
    QueuePtr rear; // 队尾指针
}ListQueue;

Status	InitQueue(ListQueue* Q);
int		QueueLength(ListQueue *Q);
Boolean QueueEmpty(ListQueue *Q);

Status	EnQueue(ListQueue* Q, QElemType e); // 入队
Status  DeQueue(ListQueue* Q, QElemType* e); // 出队

typedef void(*visit)(QElemType e);
void printQueueELem(QElemType e);
void    QueueTraverse(ListQueue *Q, visit v);


