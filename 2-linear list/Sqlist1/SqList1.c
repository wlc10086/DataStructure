#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LIST_MAX_SIZE 100
typedef int ElemType;

#define BOOL int

#ifndef TRUE
#define TRUE 1
#endif // !TRUE

#ifndef FALSE
#define FALSE 0
#endif // !FALSE

typedef struct _SqList {
	ElemType data[LIST_MAX_SIZE];
	int length;
}*SqList;


BOOL InitList(SqList* L) {
	
	assert(L != NULL);
	SqList p = (SqList)malloc(sizeof(struct _SqList));
	if (p == NULL) {
		return FALSE;
	}
	
	p->length = 0;
	for (int i = 0; i < LIST_MAX_SIZE; ++i) {
		p->data[i] = 0;
	}
	*L = p;
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

BOOL ClearList(SqList* L) {
	
	assert(L != NULL);
	
	if (*L != NULL) {
		for (int i = 0; i < (*L)->length; i++) {
			(*L)->data[i] = 0;
		}
		(*L)->length = 0;
	}
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

void GetElem(SqList L, int i, ElemType* e) {
	assert(L != NULL);
	assert(i > 0 && i <= L->length);
	*e = L->data[i - 1];
	return;
}

typedef int (*compare)(ElemType a, ElemType b);
int compareElem(ElemType a, ElemType b) {
	return a - b;
}

int LocateElem(SqList L,ElemType e, compare v)
{
	assert(L != NULL);
	for (int i = 0; i < L->length; i++) {
		if (v(L->data[i], e) == 0) {
			return i+1;
		}
	}
	return 0;
}

BOOL ListInsert(SqList L, int i, ElemType e) {
	assert(L != NULL);
	if (L->length == LIST_MAX_SIZE) {
		return FALSE;
	}
	if (i - 1 > L->length || i < 0) {
		return FALSE;
	}

	// Êý¾ÝºóÒÆ 
	for (int k = L->length; k > i; --k) {
		L->data[k + 1] = L->data[k];
	}

	L->data[i - 1] = e;
	L->length++;
	return TRUE;
}


BOOL ListDelete(SqList L, int i, ElemType* e)
{
	assert(L != NULL);
	if (i  < 0 || i > L->length) {
		return FALSE;
	}

	*e = L->data[i-1];
	for (int k = i; k < L->length; ++k) {
		L->data[k-1] = L->data[k];
	}
	L->length--;
	return TRUE;
}

typedef void (*visit)(ElemType e);

void printElem(ElemType e) {
	printf("%d ", e);
}

void ListTraverse(SqList L, visit v)
{
	assert(L != NULL);
	for (int i = 0; i < L->length; ++i) {
		v(L->data[i]);
	}
	printf("\n");
}



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

