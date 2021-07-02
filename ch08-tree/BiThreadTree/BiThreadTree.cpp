#include "BiThreadTree.h"
#include <assert.h>

// 创建一棵二叉树,约定用户遵照前序遍历的方式输入数据
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

// 线索化二叉树
// T: 原来的二叉树
// p: 辅助空结点
void InOrderThreading(BiThreadTree* p, BiThreadTree T)
{
    // 空结点
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
        pre->rtag = Thread;
        pre->rchild = *p;       //收尾操作
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
