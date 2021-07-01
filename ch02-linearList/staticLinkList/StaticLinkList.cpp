#include "StaticLinkList.h"
#include <stdio.h>

// 从静态链表申请空间
int malloc_SLL(StaticLinkList L) {
	
	// 没有空间
	if (L[0].cur == MAXSIZE - 1) {
		return 0;
	}

	int index = L[0].cur;
	L[0].cur = L[index].cur;

#ifdef _DEBUG
	L[index].data = 0;
	L[index].cur = -1;
#endif // _DEBUG

	return index;
}

// 静态链表回收空间
void free_SLL(StaticLinkList L, int index) {

	if (index > 0 && index < MAXSIZE - 1) {
		L[index].cur = L[0].cur;
		L[0].cur = index;
	}
}

Status InitList(StaticLinkList L)
{
	for (int i = 0; i < MAXSIZE - 1; ++i) {
		L[i].cur = i + 1;
	}
	L[MAXSIZE - 1].cur = 0;
	return 0;
}

Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	// 检查是否超出范围
	if (i<1 || i > ListLength(L) + 1) {
		return ERROR;
	}

	int x = malloc_SLL(L);
	if (x == 0) {	// 申请空间失败
		return ERROR;
	}

	int k = MAXSIZE - 1;
	while (--i) { // 移动到特定位置
		k = L[k].cur;
	}

	L[x].data = e;
	L[x].cur = L[k].cur;
	L[k].cur = x;
	return OK;
}

int ListLength(StaticLinkList L)
{
	int length = 0;
	for (int i = L[MAXSIZE - 1].cur; i != 0; i = L[i].cur) {
		length++;
	}
	return length;
}

Status ListDelete(StaticLinkList L, int i)
{
	// 去除无效范围
	if (i <= 0 || i > ListLength(L)) {
		return ERROR;
	}

	int k = MAXSIZE - 1;
	int j;
	for (j = 1; j <= i - 1; j++) {
		k = L[k].cur;
	}

	j = L[k].cur;
	L[k].cur = L[j].cur;
	free_SLL(L, j);
	return OK;
}

void printElem(ElemType e) {
	printf("%c ", e);
}

void  ListTraverse(StaticLinkList L, fVisit v)
{
	for (int i = L[MAXSIZE - 1].cur; i != 0; i = L[i].cur) {
		v(L[i].data);
	}
	printf("\n");
}