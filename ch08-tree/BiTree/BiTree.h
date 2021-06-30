#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct BiNode {
	DataType data;
	struct BiNode* lchild, * rchild;
}BiNode, *BiTree;

// 
void PreOrderTraverse(BiTree* T) {
	if (*T != NULL) {
		printf("%c", (*T)->data);
		PreOrderTraverse(&(*T)->lchild);
		PreOrderTraverse(&(*T)->rchild);
	}
}

void InOrderTraverse(BiTree* T) {
	if (*T != NULL) {
		PreOrderTraverse(&(*T)->lchild);
		printf("%c", (*T)->data);
		PreOrderTraverse(&(*T)->rchild);
	}
}

void PostOrderTraverse(BiTree* T) {
	if (*T != NULL) {
		PreOrderTraverse(&(*T)->lchild);
		PreOrderTraverse(&(*T)->rchild);
		printf("%c", (*T)->data);
	}
}

// ǰ�������˳�򴴽�������
void CreateBiTree(BiTree* T) {
	char c;
	scanf_s("%c", &c);
	if ('#' == c) {
		*T = NULL;
	}
	else {
		*T = (BiNode*)malloc(sizeof(BiNode));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

// ɾ����������ʹ�ú��������˳��
void DeleteBiTree(BiTree* T) {
	if (*T != NULL) {
		DeleteBiTree(&(*T)->lchild);
		DeleteBiTree(&(*T)->rchild);
		
		free(*T);
		*T = NULL;
	}
}