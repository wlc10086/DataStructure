#include <stdio.h>
#include <stdlib.h>

typedef	int	ElemType;
typedef	struct node
{
	ElemType	data;
	struct node* next;
}LNode, * LinkList;

const int CARD_NUMBER = 13;

//����������ͷ�ڵ�ѭ������,����NULLʧ��
LinkList Create(int n)
{
	int		i;
	LNode* r = NULL;
	LNode* s = NULL;
	LNode* head = NULL;
	for (i = 1; i <= n; i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = 0;
		head == NULL ? head = s : r->next = s;
		r = s;
	}
	r->next = head;
	return head;
}

void Magician(LinkList head)
{
	LinkList p;
	int j;
	int Countnumber = 2;
	p = head;
	p->data = 1;
	while (1)
	{
		for (j = 0; j < Countnumber; j++)	//�ص�˼��
		{
			p = p->next;
			if (p->data != 0) {
				j--;
			}
		}
		if (p->data == 0)
		{
			p->data = Countnumber;
			Countnumber++;
			if (Countnumber == 14)
				break;
		}
	}
}

void main()
{
	int i;
	LinkList L;
	LinkList p;
	L = Create(CARD_NUMBER);
	Magician(L);
	p = L;
	printf("�Ƶ�˳��Ӧ��Ϊ:\n");
	for (i = 1; i <= CARD_NUMBER; i++) {
		printf("����%d\t", p->data);
		p = p->next;
	}
}