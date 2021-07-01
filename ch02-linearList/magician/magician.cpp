#include <stdio.h>
#include <stdlib.h>

typedef	int	ElemType;
typedef	struct node
{
	ElemType	data;
	struct node* next;
}LNode, * LinkList;

const int CARD_NUMBER = 13;

//创建不带空头节点循环链表,返回NULL失败
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
		for (j = 0; j < Countnumber; j++)	//重点思想
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
	printf("牌的顺序应该为:\n");
	for (i = 1; i <= CARD_NUMBER; i++) {
		printf("黑桃%d\t", p->data);
		p = p->next;
	}
}