#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
// �����洢��־λ
// Link(0):��ʾָ�����Һ��ӵ�ָ��
// Thread(1):��ʾָ��ǰ����̵�����
typedef enum { Link, Thread } PointerTag;

// �����������ڵ�ṹ
typedef struct _BiThreadNode {
    char data;
    struct _BiThreadNode* lchild, * rchild;
    PointerTag ltag, rtag;
} BiThreadNode, * BiThreadTree;

// ����һ�ö�����,Լ���û�����ǰ������ķ�ʽ��������
void CreateBiTree(BiThreadTree* T) {
    char c;
    scanf_s("%c", &c);
    if ('#' == c) {
        *T = NULL;
    }
    else {
        *T = (BiThreadNode*)malloc(sizeof(BiThreadNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;
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

// ������������������
void InOrderThreading(BiThreadTree* p, BiThreadTree T)
{
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
        pre->rchild = *p;       //��β����
        pre->rtag = Thread;
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


int main()
{
    BiThreadTree P, T = NULL;
    CreateBiTree(&T);

    // ������
    InOrderThreading(&P, T);
    printf("����������,���Ϊ: ");
    InOrderTraverse(P);
    printf("\n");
    return 0;
}