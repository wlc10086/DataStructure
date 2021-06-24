#include "StaticLinkList.h"

int main()
{
	StaticLinkList L;
	InitList(L);
	ListInsert(L, 1, 'A');
	ListInsert(L, 2, 'B');
	ListTraverse(L, printElem);

	ListInsert(L, 1, 'C');
	ListTraverse(L, printElem);
}