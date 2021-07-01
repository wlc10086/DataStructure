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
				//函数声明

void InitStack(LinkStack* s);	//初始化栈

Boolean StackEmpty(LinkStack s);	//栈为空判断

int StackLength(LinkStack s);	//返回当前栈的大小

Status Push(LinkStack* s, ElemType e);	//入栈

Status Pop(LinkStack* s, ElemType* e);	//出栈

/***********************************************************/
#endif // SQSTACK_H_INCLUDED
