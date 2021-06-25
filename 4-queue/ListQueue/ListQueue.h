#pragma once

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;


typedef char QElemType;

// ���ӽ�������
typedef struct QNode
{
    QElemType       data;  // ������
    struct QNode    *next;// ָ����
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front; // ��ͷָ��
    QueuePtr rear; // ��βָ��
}ListQueue;

Status	InitQueue(ListQueue* Q);
int		QueueLength(ListQueue *Q);
Boolean QueueEmpty(ListQueue *Q);

Status	EnQueue(ListQueue* Q, QElemType e); // ���
Status  DeQueue(ListQueue* Q, QElemType* e); // ����

typedef void(*visit)(QElemType e);
void printQueueELem(QElemType e);
void    QueueTraverse(ListQueue *Q, visit v);


