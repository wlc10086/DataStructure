#include "BiThreadTree.h"
#include <assert.h>

// ����һ�ö�����,Լ���û�����ǰ������ķ�ʽ��������
void CreateBiTree(BiThreadTree* T) {

    assert(*T != NULL);

    char c;
    c = getchar();
    if ('#' == c) {
        *T = NULL;
    }
    else {
        *T = (BiThreadNode*)malloc(sizeof(BiThreadNode));
        (*T)->data = c;
        (*T)->rtag = Link;
        (*T)->ltag = Link;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}


// ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��
BiThreadTree pre;

// ������������� LDR
void InThreading(BiThreadTree T)
{
    if (T) {
        InThreading(T->lchild); //�ݹ����������� 

        if (!T->lchild) { // �������Ϊ��
            T->ltag = Thread;
            T->lchild = pre;  //lchildָ��ոշ��ʵĽ��
        }

        if (!pre->rchild) {  // ���Һ���Ϊ��
            pre->rtag = Thread;
            pre->rchild = T;  //ָ����
        }
        pre = T;
        InThreading(T->rchild);     //�ݹ��Һ���������
    }
}

// ������������
// T: ԭ���Ķ�����
// p: �����ս��
void InOrderThreading(BiThreadTree* p, BiThreadTree T)
{
    // �ս��
    *p = (BiThreadTree)malloc(sizeof(BiThreadNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;  //��ʼ��(Ҫע��TΪ�����)

    if (!T) {
        (*p)->lchild = *p;
    }
    else {
        (*p)->lchild = T;
        pre = *p;
        InThreading(T);
        pre->rtag = Thread;
        pre->rchild = *p;       //��β����
        (*p)->rchild = pre;
    }
}

void visit(char c)
{
    printf("%c", c);
}



// �������������,�ǵݹ�
void InOrderTraverse(BiThreadTree T)
{
    BiThreadTree p;
    p = T->lchild;
    while (p != T) {
        while (p->ltag == Link) {
            p = p->lchild;
        }
        
        visit(p->data);
       
        while (p->rtag == Thread && p->rchild != T) {
            p = p->rchild;
            visit(p->data);
        }
        p = p->rchild;
    }
}
