#include <stdlib.h>
#include "DuLinkList.h"
#include <stdio.h>

void InitDuList(DuLinkList* L)	//初始化双向链表
{
	(*L) = NULL;

	// 头空节点
	(*L) = (DNode*)malloc(sizeof(DNode));

	if ((*L) == NULL){
		printf("InitDuList failed.\n");
		exit(ERROR);
	}

	(*L)->data = 0;
	(*L)->prior = NULL;
	(*L)->next = NULL;
}

Status DuListEmpty(DuLinkList L)
{
	if (L == NULL){
		printf("DuLinkList have not Init.\n");
		exit(ERROR);
	}

	return L->next == NULL ? TRUE : FALSE;
}

int ListLength(DuLinkList L)
{
	int len = 0;
	if (L == NULL){
		printf("DuLinkList have not Init.\n");
		exit(ERROR);
	}

	L = L->next;
	while (L != NULL){
		len++;
		L = L->next;
	}
	return len;
}


// 在双向链表中的任意位置i插入元素e
Status ListInsert(DuLinkList L, int i, ElemType e)
{
	DuLinkList s = NULL, p = L;

	// 插入位置异常
	if (i < 0 || i > ListLength(L) + 1){
		printf("where your want to insert is out of range.\n");
		return FALSE;
	}

	s = (DNode*)malloc(sizeof(DNode));
	if (s == NULL){
		printf("could not malloc sapce.\n");	//申请空间失败
		return FALSE;
	}

	s->data = e, s->next = NULL, s->prior = NULL;

	while (i--){
		p = p->next;
	}

	// 插入位置在最后时
	if (p->next == NULL){
		s->prior = p;
		p->next = s;
	}else{   
		p = p->next;
		s->prior = p->prior;
		s->next = p;
		p->prior = s;
		s->prior->next = s;
	}

	return TRUE;
}

Status ListDelete(DuLinkList L, int i, ElemType* e)
{
	DuLinkList p = NULL;
	DuLinkList q = NULL;

	// 越界
	if (i < 0 || i > ListLength(L))	{
		printf("Delete Failed:what your want to delete is out of range.\n");
		return FALSE;
	}

	// 为空没东西删
	if (DuListEmpty(L)){
		printf("DuLinkList is Empty.\n");
		return FALSE;
	}

	p = L;
	q = p->next;
	while (i--){
		q = q->next;
	}

	p = q->prior;
	if (q->next == NULL){ //若删除的是尾结点	
		p->next = NULL;

	}else{	//删除的是非尾结点
		p->next = q->next;
		q->next->prior = p;
	}

	if (e != NULL){
		*e = q->data;
		printf("your delete in i is:%d\n", *e);
	}


	free(q);
	return TRUE;
}


// 打印出双向链表
void ListPrintf(DuLinkList L)
{
	DuLinkList p = NULL;

	// 非空判断
	if (DuListEmpty(L) == FALSE){
		p = L->next;
		while (p != NULL){
			printf("%c->", p->data);
			p = p->next;
		}
	}
	printf("NULL\n");
}
