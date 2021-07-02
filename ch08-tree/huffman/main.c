#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int Boolean;
#define TRUE  1
#define FALSE 0

typedef struct {
	unsigned int weight;	// �ַ�Ȩֵ
	unsigned int parent;
	unsigned int lchild;
	unsigned int rchild;
}HTNode, *HuffmanTree;

// �շ�������Ķ�λ��ע��˳���HT��˳����һ�µģ�ָ���Ӧ���ַ�
typedef char** HuffmanCode; 


// �Ӻշ�����HT��[1,end]��ѡ��weight��С��parent��Ϊ0�����㣬ͨ��s1��s2����
void Select(HuffmanTree HT, int end, int* s1, int* s2)
{
	int min = 0; // ��С������
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

// ���ַ�������
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
// �����շ�����
// HT�� �շ�����
// HC�� �������ɵĺշ�������
// n��  ��Ҫ���ɺշ��������Ҷ�ӽ����
// weight��  ���n��Ȩֵ������
Boolean HuffmanCoding(HuffmanTree* HT, int* weight, HuffmanCode* HC, int n) {

	if (n <= 1) {
		return FALSE;
	}

	// m�Ǻշ��������ܽ����
	int m = 2 * n - 1;
	int sizeOfTree = sizeof(HTNode) * (m + 1);
	// ��ʼ��
	*HT = (HuffmanTree)malloc(sizeOfTree);
	if (*HT == NULL) {
		printf("malloc memory error\n");
		return FALSE;
	}
	memset(*HT, 0, sizeOfTree);
	
	// ����Ϊ0�Ĳ��ֲ��ã���ʼ�� 1~n �Ĳ���
	HuffmanTree p = *HT;
	p++;

	for (int i = 1; i <= n; ++i, ++p, ++weight) {
		p->weight = *weight;
		p->lchild = 0;
		p->rchild = 0;
		p->parent = 0;
	}

	// ���շ�����������n+1 ~ m+1��
	int s1, s2;
	for (int i = n + 1; i <= m; ++i) {
		// �� 1... i-1 ѡ��parent=0��weight��С��������㣬����ŷֱ�Ϊs1��s2
		Select(*HT, i - 1, &s1, &s2);
		(*HT + s1)->parent = i, (*HT + s2)->parent = i;
		(*HT + i)->lchild = s1, (*HT + i)->rchild = s2;
		(*HT + i)->weight = (*HT + s1)->weight + (*HT + s2)->weight;
	}

	// ��Ҷ�ӽ�㵽�������ȡÿ���ַ��ĺշ�������
	*HC = (HuffmanCode)malloc(sizeof(char*) * (n + 1));

	for (int i = 1; i <= n; ++i) {

		int index = 0;

		// ��ʱ�ռ�
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

		// ������ĺշ�������ת������
		convert(cd);

		// ����
		*(*HC + i) = cd;
	}
	return TRUE;
}

// �շ�������
char* HuffmanEncrypt(HuffmanTree HT, HuffmanCode HC, char* src)
{
	return NULL;
}

// �շ�������
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