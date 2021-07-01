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
}LinkQueue;

Status	InitQueue(LinkQueue* Q);
int		QueueLength(LinkQueue *Q);
Boolean QueueEmpty(LinkQueue *Q);

Status	EnQueue(LinkQueue* Q, QElemType e); // ���
Status  DeQueue(LinkQueue* Q, QElemType* e); // ����

typedef void(*visit)(QElemType e);
void printQueueELem(QElemType e);
void    QueueTraverse(LinkQueue *Q, visit v);


