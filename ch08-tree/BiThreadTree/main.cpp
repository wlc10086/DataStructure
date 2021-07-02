#include "BiThreadTree.h"

int main()
{
    BiThreadTree P, T = NULL;
    
    // 前序遍历的创建一棵树
    CreateBiTree(&T);

    // 线索化
    InOrderThreading(&P, T);
    
    printf("中序遍历输出,结果为: ");
    // 非递归的中序遍历
    InOrderTraverse(P);
    printf("\n");
    return 0;
}