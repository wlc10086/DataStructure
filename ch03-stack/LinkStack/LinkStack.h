#ifndef LISTSTACK_H_INCLUDED
#define LISTSTACK_H_INCLUDED

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;
typedef char ElemType;

typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode* next;
}LinkStackNode, *LinkStack;

/***********************************************************/
				//��������

void InitStack(LinkStack* s);	//��ʼ��ջ

Boolean StackEmpty(LinkStack s);	//ջΪ���ж�

int StackLength(LinkStack s);	//���ص�ǰջ�Ĵ�С

Status Push(LinkStack* s, ElemType e);	//��ջ

Status Pop(LinkStack* s, ElemType* e);	//��ջ

/***********************************************************/
#endif // SQSTACK_H_INCLUDED
