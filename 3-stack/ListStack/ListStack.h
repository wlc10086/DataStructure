#ifndef LISTSTACK_H_INCLUDED
#define LISTSTACK_H_INCLUDED

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;
typedef char ElemType;

#define STACK_INIT_SIZE 2	//��ʼ������
#define STACK_INCREMENT 1	//��������

typedef struct ListStackNode
{
	ElemType data;
	struct ListStackNode* next;
}ListStackNode, *ListStack;

/***********************************************************/
				//��������

void InitStack(ListStack* s);	//��ʼ��ջ

Boolean StackEmpty(ListStack s);	//ջΪ���ж�

int StackLength(ListStack s);	//���ص�ǰջ�Ĵ�С

Status Push(ListStack* s, ElemType e);	//��ջ

Status Pop(ListStack* s, ElemType* e);	//��ջ

/***********************************************************/
#endif // SQSTACK_H_INCLUDED
