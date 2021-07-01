#ifndef _SQLIST_H_
#define _SQLIST_H_
#include <stdio.h>

#define BOOL int

#ifndef TRUE
#define TRUE 1
#endif // !TRUE

#ifndef FALSE
#define FALSE 0
#endif // !FALSE

typedef int ElemType;

#define LIST_MAX_SIZE 100

typedef struct _SqList {
    ElemType data[LIST_MAX_SIZE];
    int length;
}*SqList;


typedef void (*fVisit)(ElemType e);
typedef int (*fCompare)(ElemType a, ElemType b);


int compareElem(ElemType a, ElemType b) {
    return a - b;
}

void printElem(ElemType e) {
    printf("%d ", e);
}


// ����һ���յ����Ա�L
BOOL InitList(SqList* L);


/*��ʼ���������Ա�L�Ѵ���
    ����������������Ա�L*/
BOOL DestroyList(SqList* L);


/*��ʼ���������Ա�L�Ѵ���
    ��������������Ա�L����Ϊ�ձ�*/
BOOL ClearList(SqList L);


// ��ʼ���������Ա�L�Ѵ���
// �����������LΪ�ձ�, �򷵻�TRUE, ���򷵻�FALSE
BOOL ListEmpty(SqList L);


/* ��ʼ���������Ա�L�Ѵ���
    ����������������Ա�L������Ԫ�صĸ��� */
int ListLength(SqList L);


/*��ʼ���������Ա�L�Ѵ���, 1�� index�� ListLength(L)
    �����������e����L�е�i������Ԫ�ص�ֵ*/
BOOL GetElem(SqList  L, int index, ElemType* e);


/* ��ʼ���������Ա�L�Ѵ���,compare()������Ԫ�ص��ж�����
   �������������L�е�1����e�����ϵcompare() ������Ԫ�ص�λ����������Ԫ�ز�����,�򷵻�ֵΪ0*/
int LocateElem(SqList L, ElemType e, fCompare compare);


//  ��ʼ���������Ա�L�Ѵ���,1��index��ListLength(L)+1
//  �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e, L�ĳ��ȼ�1
BOOL ListInsert(SqList L, int index, ElemType e);


/*��ʼ���������Ա�L�Ѵ���,1��index��ListLength(L)
    ���������ɾ��L�ĵ�i������Ԫ��,����e������ֵ,L�ĳ��ȼ�1*/
BOOL ListDelete(SqList L, int index, ElemType* e);


/*��ʼ���������Ա�L�Ѵ���
    ������������ζ�L��ÿ������Ԫ�ص��ú���visit( )��һ��visit( )ʧ��,�����ʧ��*/
void ListTraverse(SqList L, fVisit visit);

#endif // !_SQLIST_H_
