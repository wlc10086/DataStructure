#include <stdio.h>
#include <stdlib.h>

typedef	int	ElemType;

typedef	struct node
{
	ElemType	data;
	struct node *next;
}LNode, *LinkList;

LinkList _Create(int n)	// 返回NULL创建循环链表失败
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
	return p;	//返回rear指针
}

void _ListToKill(LinkList L, int m, int n)	//自杀顺序
{
	int i = 1;
	LNode *p = L;
	LNode *temp = L->next;
	
	// 判断是否只剩下一个人
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
	printf( "%d\n", p->data);		//最后一个
}

int main()
{
	int	num,m;
	LinkList rear;
	printf("约瑟夫问题,请输入总人数和间隔数:\n");
	scanf_s("%d%d",&num,&m);

	//创建长度为n的循环链表
	rear = _Create(num);

	_ListToKill( rear, m, num);
}
