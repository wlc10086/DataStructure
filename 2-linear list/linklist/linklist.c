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

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

// 
BOOL InitList(LinkList* L) {

	assert(L != NULL);

	// 头空节点
	LinkList pNode = malloc(sizeof(LNode));
	if (pNode == NULL) {
		return FALSE;
	}
	pNode->data = 0xffffffff;
	pNode->next = NULL;
	*L = pNode;
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
BOOL GetElem(LinkList  L, int i, ElemType* e) {

	assert(L != NULL);
	LNode* p = L->next;
	int index = 0;
	while (p != NULL) {
	
		if (index == i-1) {
			*e = p->data;
			return TRUE;
		}

		p = p->next;
		++index;
	}
	return FALSE;
}




// 
BOOL ListDelete(LinkList L, int i, ElemType* e)
{
	assert(L != NULL);
	assert(i > 0);

	int index = 1;
	LNode* pPre = L;
	LNode* pNode = L->next;

	while (pNode != NULL) {
		if (index == i) {
			*e = pNode->data;

			pPre->next = pNode->next;
			free(pNode);
			return TRUE;
		}

		pPre = pNode;
		pNode = pNode->next;
		++index;
	}

	return FALSE;
}


BOOL ClearList(LinkList L) {

	assert(L != NULL);
	LNode* pNode = L->next;

	while (pNode != NULL) {
		LNode* pTmp = pNode;
		pNode = pNode->next;
		L->next = pNode;

#ifdef _DEBUG
		pTmp->data = 0;
		pTmp->next = NULL;
#endif // _DEBUG
		free(pTmp);
	}
	return TRUE;
}


BOOL DestroyList(LinkList* L) {

	assert(L != NULL);
	ClearList(*L);

	free((*L));
	*L = NULL;
	return TRUE;
}







typedef int (*compare)(ElemType a, ElemType b);
int compareElem(ElemType a, ElemType b) {
	return a - b;
}

int LocateElem(LinkList L, ElemType e, compare v)
{
	assert(L != NULL);
	LNode* pNode = L->next;
	int index = 0;

	while (pNode != NULL) {
		if (v(pNode->data, e) == 0) {
			return ++index;
		}

		++index;
		pNode = pNode->next;
	}
	return 0;
}



//
//  初始条件：线性表L已存在,1≤i≤ListLength(L)+1
//  操作结果：在L中第i个位置之前插入新的数据元素e, L的长度加1
//
BOOL ListInsert(LinkList L, int i, ElemType e) {

	assert(L != NULL);

	int index = 0;
	LNode* pNode = L; // 指向头空节点

	while (pNode != NULL) {
		
		if (index == i - 1) { // 找到位置
			
			LNode* node = (LNode*)malloc(sizeof(LNode));
			if (node == NULL) {
				return FALSE;
			}
			node->next = NULL;
			node->data = e;
			
			// 在尾部，直接插入到尾部
			if (pNode->next == NULL) {
				pNode->next = node;
			}else {
				// 不是尾部
				node->next = pNode->next;
				pNode->next = node;
			}
			return TRUE;
		}

		index++;
		pNode = pNode->next;
	}

	return FALSE;
}





typedef void (*visit)(ElemType e);

void printElem(ElemType e) {
	printf("%d ", e);
}

void ListTraverse(LinkList L, visit v)
{
	assert(L != NULL);
	LNode* pNode = L->next;
	while (pNode != NULL) {
		v(pNode->data);
		pNode = pNode->next;
	}
	printf("\n");
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