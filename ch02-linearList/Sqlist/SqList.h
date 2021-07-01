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


// 构造一个空的线性表L
BOOL InitList(SqList* L);


/*初始条件：线性表L已存在
    操作结果：销毁线性表L*/
BOOL DestroyList(SqList* L);


/*初始条件：线性表L已存在
    操作结果：将线性表L重置为空表*/
BOOL ClearList(SqList L);


// 初始条件：线性表L已存在
// 操作结果：若L为空表, 则返回TRUE, 否则返回FALSE
BOOL ListEmpty(SqList L);


/* 初始条件：线性表L已存在
    操作结果：返回线性表L中数据元素的个数 */
int ListLength(SqList L);


/*初始条件：线性表L已存在, 1≤ index≤ ListLength(L)
    操作结果：用e返回L中第i个数据元素的值*/
BOOL GetElem(SqList  L, int index, ElemType* e);


/* 初始条件：线性表L已存在,compare()是数据元素的判定函数
   操作结果：返回L中第1个与e满足关系compare() 的数据元素的位序。若这样的元素不存在,则返回值为0*/
int LocateElem(SqList L, ElemType e, fCompare compare);


//  初始条件：线性表L已存在,1≤index≤ListLength(L)+1
//  操作结果：在L中第i个位置之前插入新的数据元素e, L的长度加1
BOOL ListInsert(SqList L, int index, ElemType e);


/*初始条件：线性表L已存在,1≤index≤ListLength(L)
    操作结果：删除L的第i个数据元素,并用e返回其值,L的长度减1*/
BOOL ListDelete(SqList L, int index, ElemType* e);


/*初始条件：线性表L已存在
    操作结果：依次对L的每个数据元素调用函数visit( )。一旦visit( )失败,则操作失败*/
void ListTraverse(SqList L, fVisit visit);

#endif // !_SQLIST_H_
