#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int Boolean;
#define TRUE  1
#define FALSE 0

typedef struct {
	unsigned int weight;	// 字符权值
	unsigned int parent;
	unsigned int lchild;
	unsigned int rchild;
}HTNode, *HuffmanTree;

// 赫夫曼编码的二位表，注意顺序和HT的顺序是一致的，指向对应的字符
typedef char** HuffmanCode; 


// 从赫夫曼树HT中[1,end]中选出weight最小且parent不为0的两点，通过s1和s2返回
void Select(HuffmanTree HT, int end, int* s1, int* s2)
{
	int min = 0; // 最小的索引
	for (int k = 1; k <= end; k++) {
		if (HT[k].parent == 0) {
			if (min == 0) {
				min = k;
			}
			else {
				if (HT[k].weight < HT[min].weight) {
					min = k;
				}
			}
		}
	}
	*s1 = min;

	min = 0;
	for (int k = 1; k <= end; k++) {
		if (HT[k].parent == 0 && k != *s1) {
			if (min == 0) {
				min = k;
			}
			else {
				if (HT[k].weight < HT[min].weight ) {
					min = k;
				}
			}
		}
	}
	*s2 = min;
}

// 将字符串逆序
void convert(char* array)
{
	int n = strlen(array);
	if (n > 1) {
		char temp;
		for (int i = 0; i < n / 2; i++) {
			temp = array[i];
			array[i] = array[n - i - 1];
			array[n - i - 1] = temp;
		}
	}
}

// 
// 构建赫夫曼树
// HT： 赫夫曼树
// HC： 保存生成的赫夫曼编码
// n：  需要生成赫夫曼编码的叶子结点数
// weight：  存放n个权值的数组
Boolean HuffmanCoding(HuffmanTree* HT, int* weight, HuffmanCode* HC, int n) {

	if (n <= 1) {
		return FALSE;
	}

	// m是赫夫曼树的总结点数
	int m = 2 * n - 1;
	int sizeOfTree = sizeof(HTNode) * (m + 1);
	// 初始化
	*HT = (HuffmanTree)malloc(sizeOfTree);
	if (*HT == NULL) {
		printf("malloc memory error\n");
		return FALSE;
	}
	memset(*HT, 0, sizeOfTree);
	
	// 索引为0的部分不用，初始化 1~n 的部分
	HuffmanTree p = *HT;
	p++;

	for (int i = 1; i <= n; ++i, ++p, ++weight) {
		p->weight = *weight;
		p->lchild = 0;
		p->rchild = 0;
		p->parent = 0;
	}

	// 建赫夫曼树（生成n+1 ~ m+1）
	int s1, s2;
	for (int i = n + 1; i <= m; ++i) {
		// 在 1... i-1 选择parent=0且weight最小的两个结点，其序号分别为s1和s2
		Select(*HT, i - 1, &s1, &s2);
		(*HT + s1)->parent = i, (*HT + s2)->parent = i;
		(*HT + i)->lchild = s1, (*HT + i)->rchild = s2;
		(*HT + i)->weight = (*HT + s1)->weight + (*HT + s2)->weight;
	}

	// 从叶子结点到根逆序获取每个字符的赫夫曼编码
	*HC = (HuffmanCode)malloc(sizeof(char*) * (n + 1));

	for (int i = 1; i <= n; ++i) {

		int index = 0;

		// 临时空间
		char* cd = (char*)malloc(n * sizeof(char));
		if (cd == NULL) {
			printf("malloc memory fail\n");
			return FALSE;
		}
		memset(cd, 0, sizeof(char) * n);
		
		int begin = i;
		int parent = (*HT + begin)->parent;
		while (parent != 0)
		{
			if ((*HT + parent)->lchild == begin) {
				cd[index++] = '0';
			}
			else if ((*HT + parent)->rchild == begin) {
				cd[index++] = '1';
			}
			begin = parent;
			parent = (*HT + parent)->parent;
		}

		// 将逆序的赫夫曼编码转成正序
		convert(cd);

		// 保存
		*(*HC + i) = cd;
	}
	return TRUE;
}

// 赫夫曼加密
char* HuffmanEncrypt(HuffmanTree HT, HuffmanCode HC, char* src)
{
	return NULL;
}

// 赫夫曼解密
char* HuffmanDecrypt(HuffmanTree HT, HuffmanCode HC, char* src)
{
	return NULL;
}

int main()
{
	int w[] = {2,2,3,3,100};
	HuffmanTree HT = NULL;
	HuffmanCode HC = NULL;
	HuffmanCoding(&HT, w, &HC, 5);
	return 0;
}