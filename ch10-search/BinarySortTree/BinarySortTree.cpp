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

// �ݹ�Ӷ���������T���Ƿ����key
// �����ҳɹ���ָ��pָ�������Ԫ�ؽ�㣬������TRUE
// ����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE
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
	// �ҵ��Ƿ���ͨ�ĵ㣬�Ҳ����򴴽��½����в���
	if (!SearchBST(*T, key, NULL, &p))
	{
		s = (BiSTree)malloc(sizeof(BiSNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p) {// ����һ����㶼û��
			*T = s; // ����sΪ�µĸ����
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
	// ֻ�е�������������������
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
		// �������������ڵ����
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