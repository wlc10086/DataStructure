#include "SqStack.h"
#include <stdio.h>

int main()
{
	ElemType e;
	SqStack s;
	InitStack(&s);
	if (StackEmpty(&s))
	{
		printf("Stack is Empty.\n");
	}
	Push(&s, 'B');
	Push(&s, 'C');
	printf("StackLength=%d\n", StackLength(&s));

	Push(&s, 'A');
	Push(&s, 'D');
	Push(&s, 'E');
	Push(&s, 'F');
	printf("StackLength=%d\n", StackLength(&s));

	Pop(&s, &e);
	Pop(&s, &e);
	Pop(&s, &e);
	Pop(&s, &e);
	printf("StackLength=%d\n", StackLength(&s));
	printf("size of s:%zd\n", sizeof(s));

	return 0;
}
