#include "linklist.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void printElem(ElemType e) {
	printf("%d ", e);
}

int compareElem(ElemType a, ElemType b) {
	return a - b;
}


int main()
{
	LinkList L = NULL;
	InitList(&L);

	assert(ListEmpty(L));

	assert(ListLength(L) == 0);

	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 1, 100);
	ListInsert(L, 2, 200);
	ListInsert(L, 5, 500);

	ListTraverse(L, printElem);

	assert(!ListEmpty(L));

	assert(ListLength(L) == 5);

	ElemType e;
	GetElem(L, 1, &e);
	assert(e == 100);

	GetElem(L, 5, &e);
	assert(e == 500);

	assert(1 == LocateElem(L, 100, compareElem));
	assert(5 == LocateElem(L, 500, compareElem));


	ListDelete(L, 1, &e);
	ListDelete(L, 3, &e);


	ClearList(L);
	DestroyList(&L);
	return 0;
}


BOOL InitList(LinkList* L) {

	assert(L != NULL);

	// 头空节点
	*L = malloc(sizeof(LNode));
	assert(*L != NULL);

	(*L)->data = 0xffffffff;
	(*L)->next = NULL;

	return TRUE;
}

BOOL DestroyList(LinkList* L) {

	assert(L != NULL);
	ClearList(*L);
	free((*L));
	*L = NULL;
	return TRUE;
}

BOOL ClearList(LinkList L) {

	assert(L != NULL);
	LNode* pNode = L, *pDelNode = NULL;
	while (pNode->next != NULL) {
		pDelNode = pNode->next;
		pNode->next = pDelNode->next;
		free(pDelNode);
	}
	return TRUE;
}

BOOL ListEmpty(LinkList L) {
	assert(L != NULL);
	return L->next == NULL;
}


int ListLength(LinkList L) {
	
	assert(L != NULL);

	LNode* p = L->next;
	int length = 0;
	while (p != NULL) {
		p = p->next;
		++length;
	}
	return length;
}


// 
BOOL GetElem(LinkList  L, int index, ElemType* e) {

	assert(L != NULL);

	if (index <1 || index > ListLength(L)) {
		printf("out of range\n");
		return FALSE;
	}

	LNode* p = L;
	for (int i = 1; i <= index; i++) {
		p = p->next;
	}

	*e = p->data;
	return FALSE;
}


int LocateElem(LinkList L, ElemType e, fCompare compare)
{
	assert(L != NULL);
	LNode* pNode = L->next;
	int index = 0;

	while (pNode != NULL) {
		if (compare(pNode->data, e) == 0) {
			return ++index;
		}
		++index;
		pNode = pNode->next;
	}
	return 0;
}



BOOL ListInsert(LinkList L, int index, ElemType e) {

	assert(L != NULL);

	int length = ListLength(L);
	if (index <1 || index > length + 1) {
		printf("out of range\n");
		return FALSE;
	}

	// 新建点
	LNode* pNewNode = (LNode*)malloc(sizeof(LNode));
	if (pNewNode == NULL) {
		printf("malloc fail\n");
		return FALSE;
	}
	pNewNode->next = NULL;
	pNewNode->data = e;

	LNode* pNode = L; // 指向头空节点

	// 移动到待插入点
	for (int i = index; i > 1; i--) {
		pNode = pNode->next;
	}

	if (index == length + 1) { // 尾部插入
		pNode->next = pNewNode;
	}else {	
		// 插入点在中间
		pNewNode->next = pNode->next;
		pNode->next = pNewNode;
	}

	return TRUE;
}


BOOL ListDelete(LinkList L, int index, ElemType* e)
{
	assert(L != NULL);

	int length = ListLength(L);
	
	if (index <1 || index > length) {
		printf("out of range\n");
		return FALSE;
	}

	LNode* pNode = L;
	// 移动到要删除点的前一个位置
	for (int i = 1; i < index; i++) {
		pNode = pNode->next;
	}

	LNode* pDelNode = pNode->next;
	pNode->next = pDelNode->next;
	free(pDelNode);
	return TRUE;
}



void ListTraverse(LinkList L, fVisit visit)
{
	assert(L != NULL);
	for (LNode* pNode = L->next; pNode != NULL; pNode = pNode->next) {
		visit(pNode->data);
	}
	printf("\n");
}
