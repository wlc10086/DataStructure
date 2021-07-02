#pragma once


#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

// 线索存储标志位
// Link(0):表示指向左右孩子的指针
// Thread(1):表示指向前驱后继的线索
enum PointerTag { Link, Thread } ;

// 线索二叉树节点结构
typedef struct _BiThreadNode {
    char data;
    struct _BiThreadNode* lchild, * rchild;
    PointerTag ltag, rtag;
} BiThreadNode, * BiThreadTree;


// 创建一棵二叉树,约定用户遵照前序遍历的方式输入数据
void CreateBiTree(BiThreadTree* T);


// 创建中序线索二叉树
void InOrderThreading(BiThreadTree* p, BiThreadTree T);
void InThreading(BiThreadTree T);


// 遍历
void InOrderTraverse(BiThreadTree T);
