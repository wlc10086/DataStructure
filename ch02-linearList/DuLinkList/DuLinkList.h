#ifndef DULINKLIST_H_INCLUDED
#define DULINKLIST_H_INCLUDED


#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char ElemType;

// ˫������ÿ��Ԫ�صĽṹ
typedef struct DNode
{
	ElemType data;
	struct DNode* prior;	//ǰ��ָ��
	struct DNode* next;		//���ָ��
}DNode, * DuLinkList;


/* ************************************************** */
// ��������

void InitDuList(DuLinkList* L);	//��ʼ��˫������

Status DuListEmpty(DuLinkList L);	//�ж�˫�������Ƿ�Ϊ��
void ListPrintf(DuLinkList L);		//��ӡ��˫������
int ListLength(DuLinkList L);	//����˫������ĳ���
Status ListInsert(DuLinkList L, int i, ElemType e);	//��˫�������е�λ��i����Ԫ��e
Status ListDelete(DuLinkList L, int i, ElemType* e);	//ɾ��λ��i��Ԫ�أ�����e����

/****************************************************/

#endif // DULINKLIST_H_INCLUDED
