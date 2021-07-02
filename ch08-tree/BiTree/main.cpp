#include "BiTree.h"


int main()
{
	BiTree T;
	CreateBiTree(&T);
	
	PreOrderTraverse(&T);
	printf("\n");
	
	InOrderTraverse(&T);
	printf("\n");
	
	PostOrderTraverse(&T);
	printf("\n");

	DestroyTree(&T);
}