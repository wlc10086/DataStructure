#pragma once


#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

// �����洢��־λ
// Link(0):��ʾָ�����Һ��ӵ�ָ��
// Thread(1):��ʾָ��ǰ����̵�����
enum PointerTag { Link, Thread } ;

// �����������ڵ�ṹ
typedef struct _BiThreadNode {
    char data;
    struct _BiThreadNode* lchild, * rchild;
    PointerTag ltag, rtag;
} BiThreadNode, * BiThreadTree;


// ����һ�ö�����,Լ���û�����ǰ������ķ�ʽ��������
void CreateBiTree(BiThreadTree* T);


// ������������������
void InOrderThreading(BiThreadTree* p, BiThreadTree T);
void InThreading(BiThreadTree T);


// ����
void InOrderTraverse(BiThreadTree T);
