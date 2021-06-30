#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef unsigned char uint8;

typedef struct {
	unsigned int weight;	// �ַ�Ȩֵ
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;

// �շ�������Ķ�λ��ע��˳���HT��˳����һ�µģ�ָ���Ӧ���ַ�
typedef char** HuffmanCode; 

#define MAX_CHAR_SIZE 256

// ���������ַ�����ȡ��ǰ�ַ��б��Ȩֵ
int UcharWeightTable[MAX_CHAR_SIZE];

 GetUCharWeightTable(const uint8* buff, unsigned int buffLen) {
	 assert(buff != NULL);
	 for (int i = 0; i < buffLen; i++) {
		 UcharWeightTable[buff[i]]++;
	 }
}


// 
// 
// w���n���ַ���Ȩֵ������շ�����HT�������n���ַ��ĺշ�������HC
void HuffmanCoding(HuffmanTree* HT, HuffmanCode* HC, int* w, int n) {
	
	if (n <= 1) return;
	int m = 2 * n - 1;
	
	// 0�ŵ�Ԫδ��
	*HT = (HuffmanTree)malloc(sizeof(HTNode) * (m + 1));
	HuffmanTree p = *HT;
	for (int i = 1; i <= n; ++i, ++p, ++w) {
		p->weight = *w;
		p->lchild = p->rchild = p->parent = 0;
	}

	for (int i = n; i <= m; i++, ++p) {
		p->weight = p->lchild = p->rchild = p->parent = 0;
	}

	// ���շ�����
	int s1, s2;
	for (int i = n + 1; i <= m; ++i) {
		// �� 1... i-1 ѡ��parent=0��weight��С��������㣬����ŷֱ�Ϊs1��s2
		Select(HT, i - 1, &s1, &s2);
		(*HT + s1)->parent = i, (*HT + s2)->parent = i;
		(*HT + i)->lchild = s1, (*HT + i)->rchild = s2;
		(*HT + i)->weight = (*HT + s1)->weight + (*HT + s2)->weight;
	}

	// ��Ҷ�ӽ�㵽��������ÿ���ַ��ĺշ�������
	*HC = (HuffmanCode)malloc(sizeof(char*) * (n + 1));

	// ��ʱ�ռ�
	char* cd = (char*)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; ++i) {
		start = n - 1;
		for(c =i; f=
	}
}

int main()
{
	const uint8 message[] = "Hello";
	
	// ��ȡn���ַ���Ȩֵ��
	GetUCharWeightTable(message, 6);
	
	// ����շ�����
	HuffmanTree T;
	HuffmanCoding(&T, )
	return 0;
}