#include "BiThreadTree.h"

int main()
{
    BiThreadTree P, T = NULL;
    
    // ǰ������Ĵ���һ����
    CreateBiTree(&T);

    // ������
    InOrderThreading(&P, T);
    
    printf("����������,���Ϊ: ");
    // �ǵݹ���������
    InOrderTraverse(P);
    printf("\n");
    return 0;
}