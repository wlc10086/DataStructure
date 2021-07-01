#include <stdlib.h>
#include "DuLinkList.h"
#include <stdio.h>

void InitDuList(DuLinkList* L)	//��ʼ��˫������
{
	(*L) = NULL;

	// ͷ�սڵ�
	(*L) = (DNode*)malloc(sizeof(DNode));

	if ((*L) == NULL){
		printf("InitDuList failed.\n");
		exit(ERROR);
	}

	(*L)->data = 0;
	(*L)->prior = NULL;
	(*L)->next = NULL;
}

Status DuListEmpty(DuLinkList L)
{
	if (L == NULL){
		printf("DuLinkList have not Init.\n");
		exit(ERROR);
	}

	return L->next == NULL ? TRUE : FALSE;
}

int ListLength(DuLinkList L)
{
	int len = 0;
	if (L == NULL){
		printf("DuLinkList have not Init.\n");
		exit(ERROR);
	}

	L = L->next;
	while (L != NULL){
		len++;
		L = L->next;
	}
	return len;
}


// ��˫�������е�����λ��i����Ԫ��e
Status ListInsert(DuLinkList L, int i, ElemType e)
{
	DuLinkList s = NULL, p = L;

	// ����λ���쳣
	if (i < 0 || i > ListLength(L) + 1){
		printf("where your want to insert is out of range.\n");
		return FALSE;
	}

	s = (DNode*)malloc(sizeof(DNode));
	if (s == NULL){
		printf("could not malloc sapce.\n");	//����ռ�ʧ��
		return FALSE;
	}

	s->data = e, s->next = NULL, s->prior = NULL;

	while (i--){
		p = p->next;
	}

	// ����λ�������ʱ
	if (p->next == NULL){
		s->prior = p;
		p->next = s;
	}else{   
		p = p->next;
		s->prior = p->prior;
		s->next = p;
		p->prior = s;
		s->prior->next = s;
	}

	return TRUE;
}

Status ListDelete(DuLinkList L, int i, ElemType* e)
{
	DuLinkList p = NULL;
	DuLinkList q = NULL;

	// Խ��
	if (i < 0 || i > ListLength(L))	{
		printf("Delete Failed:what your want to delete is out of range.\n");
		return FALSE;
	}

	// Ϊ��û����ɾ
	if (DuListEmpty(L)){
		printf("DuLinkList is Empty.\n");
		return FALSE;
	}

	p = L;
	q = p->next;
	while (i--){
		q = q->next;
	}

	p = q->prior;
	if (q->next == NULL){ //��ɾ������β���	
		p->next = NULL;

	}else{	//ɾ�����Ƿ�β���
		p->next = q->next;
		q->next->prior = p;
	}

	if (e != NULL){
		*e = q->data;
		printf("your delete in i is:%d\n", *e);
	}


	free(q);
	return TRUE;
}


// ��ӡ��˫������
void ListPrintf(DuLinkList L)
{
	DuLinkList p = NULL;

	// �ǿ��ж�
	if (DuListEmpty(L) == FALSE){
		p = L->next;
		while (p != NULL){
			printf("%c->", p->data);
			p = p->next;
		}
	}
	printf("NULL\n");
}
