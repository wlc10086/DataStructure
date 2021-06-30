#include <stdio.h>
#include <stdlib.h>


#define LH 1
#define EH 0
#define RH -1

typedef struct BiTNode {
	int data;
	int bf;
	struct  BiTNode* lchild, * rchild;
}BiTNode, *BiTree;


void LeftBanlance(BiTree* T) {
	
}

bool InsertAVL(BiTree* T, int e, bool *taller)
{
	if (!*T)
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = true;
	}
	else
	{
		if (e == (*T)->data)
		{
			*taller = false;
			return false;
		}
		if (e < (*T)->data)
		{
			if (!InsertAVL(&(*T)->lchild, e, taller)) {
				return false;
			}
			
			// 插入了，如果长高了
			if (*taller)
			{
				switch ((*T)->bf)
				{
				case LH: // 检查之前是否左边高，或者右边高
					LeftBanlance(T);
					*taller = false;
					break;
				case EH:
					(*T)->bf = LH;
					*taller = true;
					break;
				case RH:
					(*T)->bf = EH;
					*taller = false;
					break;
				}
			}
		}
		else
		{
			if (!InsertAVL(&(*T)->rchild, e, taller))
			{
				// 插入了，检查长高了没
				if (*taller)
				{
					switch ((*T)->bf)
					{
					case LH: // 检查之前是否左边高，或者右边高
						(*T)->bf = EH;
						*taller = false;
						break;

					case EH:
						(*T)->bf = RH;
						*taller = true;
						break;
					case RH:
						RightBanlance(T);
						*taller = false;
						break;
					}
				}
			}
		}
	}
}