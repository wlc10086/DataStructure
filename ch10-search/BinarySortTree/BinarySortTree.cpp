#include <stdio.h>
#include <stdlib.h>

typedef int Status;
#define TRUE 1
#define FALSE 0

typedef int Boolean;
#define OK 1
#define ERROR 0

typedef int DataType;
typedef struct BiSNode
{
	DataType data;
	struct BiSNode* lchild, * rchild;
}BiSNode, *BiSTree;

// 递归从二叉排序树T中是否存在key
// 若查找成功，指针p指向该数据元素结点，并返回TRUE
// 否则指针p指向查找路径上访问的最后一个结点并返回FALSE
Status SearchBST(BiSTree T, int key, BiSTree f, BiSTree* p)
{
	if (T == NULL) {
		*p = f;
		return FALSE;
	}
	else if (key == T->data) {
		*p = T;
		return TRUE;
	}
	else if (key < T->data) {
		SearchBST(T->lchild, key, T, p);
	}
	else {
		SearchBST(T->rchild, key, T, p);
	}
}

Status InsertBST(BiSTree *T, int key)
{
	BiSTree p, s;
	// 找到是否相通的点，找不到则创建新结点进行插入
	if (!SearchBST(*T, key, NULL, &p))
	{
		s = (BiSTree)malloc(sizeof(BiSNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p) {// 连上一个结点都没有
			*T = s; // 插入s为新的根结点
		}
		else if (key < p->data) {
			p->lchild = s;
		}
		else {
			p->rchild = s;
		}
		return TRUE;
	}
	return FALSE;
}


Status Delete(BiSTree* p)
{
	BiSTree q, s;
	// 只有单独的左子树或右子树
	if ((*p)->rchild == NULL) {
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild == NULL) {
		q = *p;
		*p - (*p)->rchild;
		free(q);
	}
	else {
		// 左右子树都存在的情况
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}

		(*p)->data = s->data;

		if (q != *p) {
			q->rchild = s->lchild;
		}else{
			q->lchild = s->lchild;
		}
		free(s);
	}

}

Status DeleteBST(BiSTree* T, int key)
{
	if (!*T) {
		return FALSE;
	}

	if (key == (*T)->data) {
		return Delete(T);
	}
	else if (key < (*T)->data) {
		return DeleteBST(&(*T)->lchild, key);
	}
	else {
		return DeleteBST(&(*T)->rchild, key);
	}
}