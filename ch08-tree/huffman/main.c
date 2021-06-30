#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef unsigned char uint8;

typedef struct {
	unsigned int weight;	// 字符权值
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;

// 赫夫曼编码的二位表，注意顺序和HT的顺序是一致的，指向对应的字符
typedef char** HuffmanCode; 

#define MAX_CHAR_SIZE 256

// 遍历所有字符，获取当前字符列表的权值
int UcharWeightTable[MAX_CHAR_SIZE];

 GetUCharWeightTable(const uint8* buff, unsigned int buffLen) {
	 assert(buff != NULL);
	 for (int i = 0; i < buffLen; i++) {
		 UcharWeightTable[buff[i]]++;
	 }
}


// 
// 
// w存放n个字符的权值，构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC
void HuffmanCoding(HuffmanTree* HT, HuffmanCode* HC, int* w, int n) {
	
	if (n <= 1) return;
	int m = 2 * n - 1;
	
	// 0号单元未用
	*HT = (HuffmanTree)malloc(sizeof(HTNode) * (m + 1));
	HuffmanTree p = *HT;
	for (int i = 1; i <= n; ++i, ++p, ++w) {
		p->weight = *w;
		p->lchild = p->rchild = p->parent = 0;
	}

	for (int i = n; i <= m; i++, ++p) {
		p->weight = p->lchild = p->rchild = p->parent = 0;
	}

	// 建赫夫曼树
	int s1, s2;
	for (int i = n + 1; i <= m; ++i) {
		// 在 1... i-1 选择parent=0且weight最小的两个结点，其序号分别为s1和s2
		Select(HT, i - 1, &s1, &s2);
		(*HT + s1)->parent = i, (*HT + s2)->parent = i;
		(*HT + i)->lchild = s1, (*HT + i)->rchild = s2;
		(*HT + i)->weight = (*HT + s1)->weight + (*HT + s2)->weight;
	}

	// 从叶子结点到根逆序求每个字符的赫夫曼编码
	*HC = (HuffmanCode)malloc(sizeof(char*) * (n + 1));

	// 临时空间
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
	
	// 获取n个字符的权值表
	GetUCharWeightTable(message, 6);
	
	// 构造赫夫曼树
	HuffmanTree T;
	HuffmanCoding(&T, )
	return 0;
}