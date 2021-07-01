#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void InitStack(SqStack* s)
{
	assert(s != NULL);
	s->base = (ElemType*)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
	if (s->base == NULL) {
		printf("malloc memory error\n");
		return;
	}
	s->StackSize = STACK_INIT_SIZE;
	s->top = s->base;
}

Boolean StackEmpty(SqStack* s)
{
	assert(s != NULL);
	return s->base == s->top;
}

int StackLength(SqStack* s)
{
	assert(s != NULL);
	return s->top - s->base;
}

Status Push(SqStack* s, ElemType e)
{
	assert(s != NULL);
	int length = StackLength(s);

	if( length == s->StackSize) {
		free(s->base);
		
		int newStackSize = length + STACK_INCREMENT;
		s->base = (ElemType*)malloc(sizeof(ElemType) * newStackSize);
		if (s->base == NULL) {
			printf("malloc memory fail\n");
			return ERROR;
		}
		s->StackSize = newStackSize;
		s->top = s->base + length;
	}

	*(s->top) = e;
	s->top++;
	return OK;
}

Status Pop(SqStack* s, ElemType* e)
{
	if (StackEmpty(s)) {
		printf("stack is empty\n");
		return FALSE;
	}
	*e = *(--s->top);
	return TRUE;
}




