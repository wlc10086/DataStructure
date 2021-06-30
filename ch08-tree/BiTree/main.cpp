#include "BiTree.h"

int main()
{
	BiTree T;
	CreateBiTree(&T);
	PreOrderTraverse(&T);
	DeleteBiTree(&T);
}