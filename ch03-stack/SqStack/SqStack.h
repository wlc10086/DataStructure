#ifndef SQSTACK_H_INCLUDED
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

typedef struct
{
	ElemType* base; // ջ��
	ElemType* top;  // ջ��
	int StackSize;	//��ǰջ���������
}SqStack;

/***********************************************************/
				//��������

void InitStack(SqStack* s);	//��ʼ��ջ

Boolean StackEmpty(SqStack* s);	//ջΪ���ж�

int StackLength(SqStack* s);	//���ص�ǰջ�Ĵ�С

Status Push(SqStack* s, ElemType e);	//��ջ

Status Pop(SqStack* s, ElemType* e);	//��ջ

/***********************************************************/
#endif // SQSTACK_H_INCLUDED
