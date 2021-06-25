#ifndef DULINKLIST_H_INCLUDED
#define DULINKLIST_H_INCLUDED


#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char ElemType;

// 双向链接每个元素的结构
typedef struct DNode
{
	ElemType data;
	struct DNode* prior;	//前驱指针
	struct DNode* next;		//后继指针
}DNode, * DuLinkList;


/* ************************************************** */
// 函数声明

void InitDuList(DuLinkList* L);	//初始化双向链表

Status DuListEmpty(DuLinkList L);	//判断双向链表是否为空
void ListPrintf(DuLinkList L);		//打印出双向链表
int ListLength(DuLinkList L);	//返回双向链表的长度
Status ListInsert(DuLinkList L, int i, ElemType e);	//在双向链表中的位置i插入元素e
Status ListDelete(DuLinkList L, int i, ElemType* e);	//删除位置i的元素，并用e返回

/****************************************************/

#endif // DULINKLIST_H_INCLUDED
