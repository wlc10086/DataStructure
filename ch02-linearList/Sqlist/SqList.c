#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	SqList L = NULL;
	InitList(&L);

	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);
	ListTraverse(L, printElem);

	ElemType e;
	ListDelete(L, 2, &e);

	GetElem(L, 2, &e);
	assert(e == 3);
	ListTraverse(L, printElem);

	assert(LocateElem(L, e, compareElem) == 2);
	ListTraverse(L, printElem);

	DestroyList(&L);

	return 0;
}


BOOL InitList(SqList* L) {

	assert(L != NULL);

	*L = (SqList)malloc(sizeof(struct _SqList));
	if (*L == NULL) {
		printf("malloc memory fail\n");
		return FALSE;
	}

	for (int i = 0; i < LIST_MAX_SIZE; ++i) {
		(*L)->data[i] = 0;
	}
	(*L)->length = 0;
	return TRUE;
}

BOOL DestroyList(SqList* L) {

	assert(L != NULL);
	if (*L != NULL) {
		free(*L);
		*L = NULL;
	}
	return TRUE;
}

BOOL ClearList(SqList L) {

	assert(L != NULL);
	L->length = 0;
	return TRUE;
}

BOOL ListEmpty(SqList L) {
	assert(L != NULL);
	return L->length == 0;
}

int ListLength(SqList L) {
	assert(L != NULL);
	return L->length;
}

BOOL GetElem(SqList L, int index, ElemType* e) {

	assert(L != NULL);
	if (index <1 || index > ListLength(L)) {
		printf("out of range\n");
		return FALSE;
	}

	*e = L->data[index - 1];
	return TRUE;
}


int LocateElem(SqList L, ElemType e, fCompare compare)
{
	assert(L != NULL);

	for (int i = 1; i <= L->length; i++) {
		if (compare(L->data[i-1], e) == 0) {
			return i;
		}
	}
	return 0;
}

BOOL ListInsert(SqList L, int index, ElemType e) {
	
	assert(L != NULL);

	if (L->length == LIST_MAX_SIZE) {
		printf("list is full\n");
		return FALSE;
	}
	
	if (index < 1 || index > ListLength(L) + 1) {
		printf("out of range\n");
		return FALSE;
	}

	// 数据后移 
	for (int k = L->length; k >= index; --k) {
		L->data[k] = L->data[k-1];
	}

	L->data[index-1] = e;
	L->length++;
	return TRUE;
}


BOOL ListDelete(SqList L, int index, ElemType* e)
{
	assert(L != NULL);
	if (index  < 1 || index > L->length) {
		printf("out of range\n");
		return FALSE;
	}

	*e = L->data[index - 1];

	// 数据左移
	for (int k = index; k < L->length; ++k) {
		L->data[k - 1] = L->data[k];
	}
	L->length--;
	return TRUE;
}



void ListTraverse(SqList L, fVisit v)
{
	assert(L != NULL);
	for (int i = 0; i < L->length; ++i) {
		v(L->data[i]);
	}
	printf("\n");
}



