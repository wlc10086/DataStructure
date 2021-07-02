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


// 前序遍历的顺序创建二叉树
void CreateBiTree(BiTree* T);

// 销毁二叉树（使用后序遍历）
void DestroyTree(BiTree* T);

/*初始条件：二叉树T存在。 
	操作结果：将二叉树T清为空树。 */
Boolean ClearBiTree(BiTree T);

/* 初始条件：二叉树T存在。 
	操作结果：若T为空二叉树,则返回TURE,否则FALSE。 */
Boolean TreeEmpty(BiTree T);

/* 初始条件：二叉树T存在。 
	操作结果：返回T的深度。 */
int TreeDepth(BiTree T);

// 三种方法遍历二叉树
void PreOrderTraverse(BiTree* T);
void InOrderTraverse(BiTree* T);
void PostOrderTraverse(BiTree* T);




