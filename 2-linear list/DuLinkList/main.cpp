#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "DuLinkList.h"

int main()
{
	DuLinkList L;
	InitDuList(&L);
	ListInsert(L, 0, 'A');
	ListInsert(L, 0, 'B');
	ListInsert(L, 0, 'C');

	ListPrintf(L);

	ElemType e;
	//memset(&e, 0, sizeof(e));
	ZeroMemory(&e, sizeof(e));
	ListDelete(L, 1, NULL);

	ListPrintf(L);
	return 0;
}