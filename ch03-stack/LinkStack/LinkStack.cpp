#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void InitStack(LinkStack* s)
{
	assert(s != NULL);

	LinkStackNode* pNode = (LinkStackNode*)malloc(sizeof(LinkStackNode));
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

Boolean StackEmpty(LinkStack s)
{
	assert(s != NULL);
	return s->next == NULL;
}

int StackLength(LinkStack s)
{
	assert(s != NULL);
	int length = 0;
	LinkStackNode* pNode = s->next;
	while (pNode != NULL) {
		length++;
		pNode = pNode->next;
	}
	return length;
}

Status Push(LinkStack *s, ElemType e)
{
	assert(s != NULL);
	LinkStackNode* pNode = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (pNode == NULL) {
		printf("malloc memory fail\n");
		return ERROR;
	}
	pNode->data = e;
	pNode->next = (*s)->next;
	(*s)->next = pNode;
	return OK;
}


Status Pop(LinkStack* s, ElemType* e)
{
	if (StackEmpty(*s)) {
		return FALSE;
	}

	LinkStackNode* pNode = (*s)->next;
	(*s)->next = pNode->next;
	free(pNode);
	return OK;
}




