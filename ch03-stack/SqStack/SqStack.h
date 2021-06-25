#ifndef SQSTACK_H_INCLUDED
#define LISTSTACK_H_INCLUDED

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;
typedef char ElemType;

#define STACK_INIT_SIZE 2	//初始化容量
#define STACK_INCREMENT 1	//后续增量

typedef struct
{
	ElemType* base; // 栈底
	ElemType* top;  // 栈定
	int StackSize;	//当前栈的最大容量
}SqStack;

/***********************************************************/
				//函数声明

void InitStack(SqStack* s);	//初始化栈

Boolean StackEmpty(SqStack* s);	//栈为空判断

int StackLength(SqStack* s);	//返回当前栈的大小

Status Push(SqStack* s, ElemType e);	//入栈

Status Pop(SqStack* s, ElemType* e);	//出栈

/***********************************************************/
#endif // SQSTACK_H_INCLUDED
