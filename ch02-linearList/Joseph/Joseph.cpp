#include <stdio.h>
#include <stdlib.h>

typedef	int	ElemType;

typedef	struct node
{
	ElemType	data;
	struct node *next;
}LNode, *LinkList;

LinkList _Create(int n)	// ����NULL����ѭ������ʧ��
{
	int i;
	LNode	*p = NULL;
	LNode	*s = NULL;
	LNode	*head = NULL;

	if( n<0)
	{
		return NULL;
	}

	for(i = 1; i <= n; i++)
	{
		s = (LNode *)malloc( sizeof(LNode));
		s->data = i;
		if( head == NULL)
			head = s;
		else
			p->next = s;
		p = s;
	}

	p->next = head;
	return p;	//����rearָ��
}

void _ListToKill(LinkList L, int m, int n)	//��ɱ˳��
{
	int i = 1;
	LNode *p = L;
	LNode *temp = L->next;
	
	// �ж��Ƿ�ֻʣ��һ����
	while( p != p->next)
	{
		for( i=1; i<=m-1; i++)
		{
			p = p->next;
		}
			
		temp = p->next;
		p->next = temp->next;
		printf("%d->",temp->data);

		free(temp);
	}
	printf( "%d\n", p->data);		//���һ��
}

int main()
{
	int	num,m;
	LinkList rear;
	printf("Լɪ������,�������������ͼ����:\n");
	scanf_s("%d%d",&num,&m);

	//��������Ϊn��ѭ������
	rear = _Create(num);

	_ListToKill( rear, m, num);
}
