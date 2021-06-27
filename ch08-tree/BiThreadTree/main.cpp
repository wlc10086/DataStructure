#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
// 线索存储标志位
// Link(0):表示指向左右孩子的指针
// Thread(1):表示指向前驱后继的线索
typedef enum { Link, Thread } PointerTag;

// 线索二叉树节点结构
typedef struct _BiThreadNode {
    char data;
    struct _BiThreadNode* lchild, * rchild;
    PointerTag ltag, rtag;
} BiThreadNode, * BiThreadTree;

// 创建一棵二叉树,约定用户遵照前序遍历的方式输入数据
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
// 全局变量，始终指向刚刚访问过的结点
BiThreadTree pre;

// 中序遍历线索化 LDR
void InThreading(BiThreadTree T)
{
    if (T) {
        InThreading(T->lchild); //递归左孩子线索化 

        if (!T->lchild) { // 如果左孩子为空
            T->ltag = Thread;
            T->lchild = pre;  //lchild指向刚刚访问的结点
        }

        if (!pre->rchild) {  // 如右孩子为空
            pre->rtag = Thread;
            pre->rchild = T;  //指向后继
        }
        pre = T;
        InThreading(T->rchild);     //递归右孩子线索化
    }
}

// 创建中序线索二叉树
void InOrderThreading(BiThreadTree* p, BiThreadTree T)
{
    *p = (BiThreadTree)malloc(sizeof(BiThreadNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;  //初始化(要注意T为空情况)
    if (!T) {
        (*p)->lchild = *p;
    }
    else {
        (*p)->lchild = T;
        pre = *p;
        InThreading(T);
        pre->rchild = *p;       //收尾操作
        pre->rtag = Thread;
        (*p)->rchild = pre;
    }
}

void visit(char c)
{
    printf("%c", c);
}

// 中序遍历二叉树,非递归
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

    // 线索化
    InOrderThreading(&P, T);
    printf("中序遍历输出,结果为: ");
    InOrderTraverse(P);
    printf("\n");
    return 0;
}