#include "Sort.h"
typedef int DataType;


void swap(DataType R[], int i, int j) {
	DataType temp;
	temp = R[i];
	R[i] = R[j];
	R[j] = temp;
}


void Sort::BobbleSort(DataType R[], int n)
{
	bool isSorted = true;

	for (int i = n - 1; i > 0; i--){

		for (int k = 1; k <= i; k++) {

			if (R[k] > R[k + 1]) {
				swap(R, k, k + 1);
				isSorted = false;
			}
		}

		if (isSorted) {
			break;
		}
		isSorted = true;
	}
}
//void Sort::BobbleSort(DataType R[], int n)
//{
//	DataType temp = 0;
//	bool isSorted = true; 	// 有序标志 
//
//	if (R != NULL)
//	{
//		for (int i = n - 1; i > 0; i--)
//		{
//			isSorted = true;
//			for (int j = 0; j < i; j++)
//			{
//				if (R[j] > R[j + 1])
//				{
//					// 比较大的值往后挪动
//					temp = R[j];
//					R[j] = R[j + 1];
//					R[j + 1] = temp;
//					isSorted = false;
//				}
//			}
//
//			if (isSorted)
//			{
//				break; // 如果确定是有序的，跳过后续操作 
//			}
//		}
//	}
//}


void Sort::QuickSort(DataType R[], int n)
{
	if (R != NULL && n > 1)
	{
		QuickSort(R, 1, n);
	}
}




// 下面是内部函数 
void Sort::QuickSort(DataType R[], int left, int right)
{
	int i = left, j = right;
	DataType temp = 0;

	if (left < right)
	{
		temp = R[left];	// 取最左边做为参考值 
		while (i != j)
		{
			while (j > i && R[j] >= temp) j--;
			if (i < j)
			{	// 从右边起，取出比参考值小的数 
				R[i] = R[j];
				i++;
			}

			while (i < j && R[i] <= temp) i++;
			if (j > i)
			{	// 从左边起，取出比参考值大的数 
				R[j] = R[i];
				j--;
			}
			// 把temp值放到适合的位置 
			R[i] = temp;

			// 分组递归操纵 
			QuickSort(R, left, i - 1);
			QuickSort(R, i + 1, right);
		}
	}
}

// 简单插入排序
void Sort::InsertSort(DataType R[], int n)
{
	if (R != NULL && n > 1)
	{
		int i = 0, j = 0;
		DataType temp = 0;
		for (i = 1; i < n; i++)
		{
			// 如果比左边有序列表小，需要插入到其中 
			if (R[i - 1] > R[i])
			{
				temp = R[i];
				for (j = i - 1; j >= 0 && R[j] > temp; j--)
				{
					R[j + 1] = R[j];
				}
				R[j + 1] = temp;
			}
		}
	}
}



// 希尔排序
void Sort::ShellSort(DataType R[], int n)
{
	if (R != NULL && n > 1)
	{
		int i = 0, j = 0;
		DataType temp = 0;
		int gap = n;

		do
		{
			gap = gap / 3 + 1;
			for (i = gap; i < n; i += gap)
			{
				// 如果比左边有序列表小，需要插入到其中 
				if (R[i] < R[i - gap])
				{
					temp = R[i];
					for (j = i - gap; j >= 0 && R[j] > temp; j -= gap)
					{
						R[j + gap] = R[j];
					}
					R[j + gap] = temp;
				}
			}
		} while (gap > 1);
	}
}




// 选择排序：每次从右边选出一个最值，放到左边
void Sort::SelectSort(DataType R[], int n)
{
	DataType temp;
	int min = 0;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (R[j] < R[min]) // 选择最小的一个
				min = j;
		}

		if (min != i){
			swap(R, i, min);
		}
	}
}



// 构造大顶堆 
void Sort::HeapAdjust(DataType R[], int s, int n)
{
	DataType temp = R[s]; // 保存当前结点
	for (int i = 2 * s; i <= n; i *= 2)
	{
		if ( i< n && R[i] < R[i + 1]) // 如果右孩子大于左孩子
			i++;// i指向较大的那个孩子

		if (temp >= R[i]) // 如果结点大于孩子，跳出循环
			break;

		R[s] = R[i]; // 交换当前结点和比他大的孩子
		s = i;
	}
	R[s] = temp;
}

//数组R的，索引0的不用
void Sort::HeapSort(DataType R[], int n)
{
	// 构造大顶堆
	for (int i = n / 2; i > 0; i--)
	 	HeapAdjust(R, i, n);
	// 构造完毕，第一个是最大的

	for (int i = n; i > 1; i--)
	{
		// 交换两个数值，把最大的放到最后面
		swap(R, 1, i);

		// 重新构造大顶堆
		HeapAdjust(R, 1, i - 1);
	}
}



// 归并排序
void Sort::MergeSort(DataType R[], int n)
{
	if (n > 1)
	{
		DataType* list_1 = R;
		int size_1 = n / 2;

		DataType* list_2 = R + size_1;
		int size_2 = n - size_1;

		// 拆分排序 
		MergeSort(list_1, size_1);
		MergeSort(list_2, size_2);

		// 合并阶段
		Meging(list_1, size_1, list_2, size_2);

	}
}

void Sort::Meging(DataType* R1, int size1, DataType* R2, int size2)
{
	int i = 0, j = 0, k = 0;
	DataType temp[MAX_SIZE];

	while (i < size1 && j < size2)
	{
		if (R1[i] < R2[j])
		{
			temp[k++] = R1[i++];
		}
		else
		{
			temp[k++] = R2[j++];
		}
	}

	// 补充剩余的 
	for (; i < size1; i++)
		temp[k++] = R1[i];

	for (; j < size2; j++)
		temp[k++] = R2[j];

	for (k = 0; k < size1 + size2; k++)
	{
		R1[k] = temp[k];
	}
}



void Sort::ShowList(DataType R[], int begin, int end)
{
	if (R != NULL && end > begin )
	{
		for (int i = begin; i < end; i++)
		{
			printf("%d ", R[i]);
		}
		printf("\n");
	}
}





