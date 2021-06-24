#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



#define BOOL int

#ifndef TRUE
#define TRUE 1
#endif // !TRUE

#ifndef FALSE
#define FALSE 0
#endif // !FALSE

#define LIST_INIT_SIZE 3
#define LIST_INCREMENT 1

typedef int ElemType;


typedef struct _SqList {
	ElemType *data;
	int size;   // 容量
	int length; // 个数
}SqList;


BOOL InitList(SqList** L) {

	assert(L != NULL);

	SqList* p = malloc(sizeof(SqList));
	if (p == NULL) {
		return FALSE;
	}

	p->data = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
	if (p->data == NULL) {
		return FALSE;
	}
	p->size = LIST_INIT_SIZE;
	p->length = 0;
	for (int i = 0; i < p->size; i++) {
		p->data[i] = 0;
	}

	*L = p;
	return TRUE;
}


BOOL DestroyList(SqList** L) {

	assert(L != NULL && *L != NULL);
	if ((*L)->data != NULL) {
		free((*L)->data);
		(*L)->data = NULL;
		(*L)->length = 0;
		(*L)->size = 0;
	}

	if (*L != NULL) {
		free(*L);
		*L = NULL;
	}

	return TRUE;
}


BOOL ClearList(SqList* L) {

	assert(L != NULL && L->data != NULL);
	//for (int i = 0; i < L->length; i++) {
	//	L->data[i] = 0;
	//}
	L->length = 0;
	return TRUE;
}

BOOL ListEmpty(SqList *L) {
	assert(L != NULL);
	return L->length == 0;
}

int ListLength(SqList *L) {
	assert(L != NULL);
	return L->length;
}

void GetElem(SqList *L, int i, ElemType* e) {
	
	assert(L != NULL && L->data != NULL);
	assert(i > 0 && i <= L->length);
	*e = L->data[i - 1];
	return;
}

typedef int (*compare)(ElemType a, ElemType b);
int compareElem(ElemType a, ElemType b) {
	return a - b;
}

int LocateElem(SqList *L, ElemType e, compare v)
{
	assert(L != NULL && L->data != NULL);

	for (int i = 0; i < L->length; i++) {
		if (v(L->data[i], e) == 0) {
			return i + 1;
		}
	}
	return 0;
}

//
//  初始条件：线性表L已存在,1≤i≤ListLength(L)+1
//  操作结果：在L中第i个位置之前插入新的数据元素e, L的长度加1
//
BOOL ListInsert(SqList *L, int i, ElemType e) {

	assert(L != NULL && L->data != NULL);

	// 保证不会超出范围
	if (i < 0 || i > L->length+1) {
		return FALSE;
	}

	// 检查是否有空位，增加空间
	if (L->length == L->size) {
		L->data = (ElemType*)realloc(L->data, sizeof(ElemType) * (L->size + LIST_INCREMENT));
		if (L->data == NULL) {
			return FALSE;
		}
		L->size += LIST_INCREMENT;
	}

	// 数据后移
	for (int k = L->length-1; k >= i-1; --k) {
		L->data[k+1] = L->data[k];
	}

	L->data[i - 1] = e;
	L->length++;
	return TRUE;
}


BOOL ListDelete(SqList *L, int i, ElemType* e)
{
	assert(L != NULL && L->data != NULL);

	if (i  < 0 || i > L->length) {
		return FALSE;
	}

	*e = L->data[i - 1];
	for (int k = i; k < L->length; ++k) {
		L->data[k - 1] = L->data[k];
	}
	L->length--;
	return TRUE;
}


typedef void (*visit)(ElemType e);

void printElem(ElemType e) {
	printf("%d ", e);
}

void ListTraverse(SqList *L, visit v)
{
	assert(L != NULL);

	for (int i = 0; i < L->length; ++i) {
		v(L->data[i]);
	}
	printf("\n");
}



int main()
{
	SqList *L = NULL;
	InitList(&L);

	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);
	ListInsert(L, 4, 4);
	ListInsert(L, 2, 100);
	ListTraverse(L, printElem);


	ElemType e;
	ListDelete(L, 2, &e);
	
	GetElem(L, 2, &e);
	assert(e == 2);
	ListTraverse(L, printElem);

	
	assert(LocateElem(L, e, compareElem) == 2);
	ListTraverse(L, printElem);
	

	ClearList(L);
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);

	DestroyList(&L);

	return 0;
}

