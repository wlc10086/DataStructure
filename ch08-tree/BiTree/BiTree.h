#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int Boolean;
#define TRUE 1
#define FALSE 0

typedef char DataType;
typedef struct BiNode {
	DataType data;
	struct BiNode* lchild, * rchild;
}BiNode, * BiTree;

// 


// ǰ�������˳�򴴽�������
void CreateBiTree(BiTree* T);

// ���ٶ�������ʹ�ú��������
void DestroyTree(BiTree* T);

/*��ʼ������������T���ڡ� 
	�����������������T��Ϊ������ */
Boolean ClearBiTree(BiTree T);

/* ��ʼ������������T���ڡ� 
	�����������TΪ�ն�����,�򷵻�TURE,����FALSE�� */
Boolean TreeEmpty(BiTree T);

/* ��ʼ������������T���ڡ� 
	�������������T����ȡ� */
int TreeDepth(BiTree T);

// ���ַ�������������
void PreOrderTraverse(BiTree* T);
void InOrderTraverse(BiTree* T);
void PostOrderTraverse(BiTree* T);




