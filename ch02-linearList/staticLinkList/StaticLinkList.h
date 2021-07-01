#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#ifdef	TRUE
#undef  TRUE
#endif  // TRUE

#ifdef	FALSE
#undef  FALSE
#endif  // FALSE

#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR	0

typedef	int	Boolean;
typedef	int	Status;

typedef	char ElemType;

#define MAXSIZE	10       //��̬�����С
typedef	struct {
	ElemType	data;	//����
	int			cur;	//�α�
}SNode, StaticLinkList[MAXSIZE];

//��������

int malloc_SLL(StaticLinkList L);
void free_SLL(StaticLinkList L, int index);
Status	InitList(StaticLinkList L);
Status	ListInsert(StaticLinkList L, int i, ElemType e);	//�ھ�̬�����λ��i����Ԫ��e
int		ListLength(StaticLinkList L);	//���ؾ�̬����ĳ���
Status	ListDelete(StaticLinkList L, int i);	//ɾ����L�е�i��Ԫ��


void printElem(ElemType e);
typedef void    (*fVisit)(ElemType e);
void  ListTraverse(StaticLinkList L, fVisit v);
#endif