#include "BiTree.h"
#include <assert.h>

// 前序遍历的顺序创建二叉树
void CreateBiTree(BiTree* T) {
	char c;
	c = getchar();

	if ('#' == c) {
		*T = NULL;
	}
	else {
		// 这里不判断是否申请成功，实际代码中需要判断
		*T = (BiNode*)malloc(sizeof(BiNode));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

void DestroyTree(BiTree* T)
{
	if (*T != NULL) {
		DestroyTree(&(*T)->lchild);
		DestroyTree(&(*T)->rchild);

		free(*T);
		*T = NULL;
	}
}


void PreOrderTraverse(BiTree* T) {
	if (*T != NULL) {
		printf("%c ", (*T)->data);
		PreOrderTraverse(&(*T)->lchild);
		PreOrderTraverse(&(*T)->rchild);
	}
}

void InOrderTraverse(BiTree* T) {
	if (*T != NULL) {
		PreOrderTraverse(&(*T)->lchild);
		printf("%c ", (*T)->data);
		PreOrderTraverse(&(*T)->rchild);
	}
}

void PostOrderTraverse(BiTree* T) {
	if (*T != NULL) {
		PreOrderTraverse(&(*T)->lchild);
		PreOrderTraverse(&(*T)->rchild);
		printf("%c ", (*T)->data);
	}
}