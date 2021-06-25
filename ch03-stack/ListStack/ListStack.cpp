#include "ListStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void InitStack(ListStack* s)
{
	assert(s != NULL);

	ListStackNode* pNode = (ListStackNode*)malloc(sizeof(ListStackNode));
	if (pNode == NULL) {
		printf("malloc memory error\n");
		return;
	}

#ifdef _DEBUG
	pNode->data = '*';
#endif // _DEBUG
	
	pNode->next = NULL;
	(*s) = pNode;
}

Boolean StackEmpty(ListStack s)
{
	assert(s != NULL);
	return s->next == NULL;
}

int StackLength(ListStack s)
{
	assert(s != NULL);
	int length = 0;
	ListStackNode* pNode = s->next;
	while (pNode != NULL) {
		length++;
		pNode = pNode->next;
	}
	return length;
}

Status Push(ListStack *s, ElemType e)
{
	assert(s != NULL);
	ListStackNode* pNode = (ListStackNode*)malloc(sizeof(ListStackNode));
	if (pNode == NULL) {
		printf("malloc memory fail\n");
		return ERROR;
	}
	pNode->data = e;
	pNode->next = (*s)->next;
	(*s)->next = pNode;
	return OK;
}


Status Pop(ListStack* s, ElemType* e)
{
	if (StackEmpty(*s)) {
		return FALSE;
	}

	ListStackNode* pNode = (*s)->next;
	(*s)->next = pNode->next;
	free(pNode);
	return OK;
}




