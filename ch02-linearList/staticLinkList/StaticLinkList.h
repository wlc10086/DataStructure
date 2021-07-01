#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#ifdef	TRUE
#undef  TRUE
#endif  // TRUE

#ifdef	FALSE
#undef  FALSE
#endif  // FALSE

#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR	0

typedef	int	Boolean;
typedef	int	Status;

typedef	char ElemType;

#define MAXSIZE	10       //静态连表大小
typedef	struct {
	ElemType	data;	//数据
	int			cur;	//游标
}SNode, StaticLinkList[MAXSIZE];

//函数声明

int malloc_SLL(StaticLinkList L);
void free_SLL(StaticLinkList L, int index);

Status	InitList(StaticLinkList L);
Status	ListInsert(StaticLinkList L, int i, ElemType e);	//在静态链表的位置i插入元素e
int		ListLength(StaticLinkList L);	//返回静态链表的长度
Status	ListDelete(StaticLinkList L, int i);	//删除在L中第i个元素


void printElem(ElemType e);
typedef void    (*fVisit)(ElemType e);
void  ListTraverse(StaticLinkList L, fVisit v);
#endif