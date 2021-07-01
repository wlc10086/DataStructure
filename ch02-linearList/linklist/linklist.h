#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#define BOOL int

#ifndef TRUE
#define TRUE 1
#endif // !TRUE

#ifndef FALSE
#define FALSE 0
#endif // !FALSE

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

typedef void (*fVisit)(ElemType e);
typedef int (*fCompare)(ElemType a, ElemType b);


// ����һ���յ����Ա�L
BOOL InitList(LinkList* L);


/*��ʼ���������Ա�L�Ѵ���
    ����������������Ա�L*/
BOOL DestroyList(LinkList* L);


/*��ʼ���������Ա�L�Ѵ���
    ��������������Ա�L����Ϊ�ձ�*/
BOOL ClearList(LinkList L);


// ��ʼ���������Ա�L�Ѵ���
// �����������LΪ�ձ�, �򷵻�TRUE, ���򷵻�FALSE
BOOL ListEmpty(LinkList L);


/* ��ʼ���������Ա�L�Ѵ���
    ����������������Ա�L������Ԫ�صĸ��� */
int ListLength(LinkList L);


/*��ʼ���������Ա�L�Ѵ���, 1�� index�� ListLength(L)
    �����������e����L�е�i������Ԫ�ص�ֵ*/
BOOL GetElem(LinkList  L, int index, ElemType* e);


/* ��ʼ���������Ա�L�Ѵ���,compare()������Ԫ�ص��ж�����
   �������������L�е�1����e�����ϵcompare() ������Ԫ�ص�λ����������Ԫ�ز�����,�򷵻�ֵΪ0*/
int LocateElem(LinkList L, ElemType e, fCompare compare);


//  ��ʼ���������Ա�L�Ѵ���,1��index��ListLength(L)+1
//  �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e, L�ĳ��ȼ�1
BOOL ListInsert(LinkList L, int index, ElemType e);


/*��ʼ���������Ա�L�Ѵ���,1��index��ListLength(L)
    ���������ɾ��L�ĵ�i������Ԫ��,����e������ֵ,L�ĳ��ȼ�1*/
BOOL ListDelete(LinkList L, int index, ElemType* e);


/*��ʼ���������Ա�L�Ѵ���
    ������������ζ�L��ÿ������Ԫ�ص��ú���visit( )��һ��visit( )ʧ��,�����ʧ��*/
void ListTraverse(LinkList L, fVisit visit);

#endif // !_LINKLIST_H_
