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
//	bool isSorted = true; 	// �����־ 
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
//					// �Ƚϴ��ֵ����Ų��
//					temp = R[j];
//					R[j] = R[j + 1];
//					R[j + 1] = temp;
//					isSorted = false;
//				}
//			}
//
//			if (isSorted)
//			{
//				break; // ���ȷ��������ģ������������� 
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




// �������ڲ����� 
void Sort::QuickSort(DataType R[], int left, int right)
{
	int i = left, j = right;
	DataType temp = 0;

	if (left < right)
	{
		temp = R[left];	// ȡ�������Ϊ�ο�ֵ 
		while (i != j)
		{
			while (j > i && R[j] >= temp) j--;
			if (i < j)
			{	// ���ұ���ȡ���Ȳο�ֵС���� 
				R[i] = R[j];
				i++;
			}

			while (i < j && R[i] <= temp) i++;
			if (j > i)
			{	// �������ȡ���Ȳο�ֵ����� 
				R[j] = R[i];
				j--;
			}
			// ��tempֵ�ŵ��ʺϵ�λ�� 
			R[i] = temp;

			// ����ݹ���� 
			QuickSort(R, left, i - 1);
			QuickSort(R, i + 1, right);
		}
	}
}

// �򵥲�������
void Sort::InsertSort(DataType R[], int n)
{
	if (R != NULL && n > 1)
	{
		int i = 0, j = 0;
		DataType temp = 0;
		for (i = 1; i < n; i++)
		{
			// �������������б�С����Ҫ���뵽���� 
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



// ϣ������
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
				// �������������б�С����Ҫ���뵽���� 
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




// ѡ������ÿ�δ��ұ�ѡ��һ����ֵ���ŵ����
void Sort::SelectSort(DataType R[], int n)
{
	DataType temp;
	int min = 0;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (R[j] < R[min]) // ѡ����С��һ��
				min = j;
		}

		if (min != i){
			swap(R, i, min);
		}
	}
}



// ����󶥶� 
void Sort::HeapAdjust(DataType R[], int s, int n)
{
	DataType temp = R[s]; // ���浱ǰ���
	for (int i = 2 * s; i <= n; i *= 2)
	{
		if ( i< n && R[i] < R[i + 1]) // ����Һ��Ӵ�������
			i++;// iָ��ϴ���Ǹ�����

		if (temp >= R[i]) // ��������ں��ӣ�����ѭ��
			break;

		R[s] = R[i]; // ������ǰ���ͱ�����ĺ���
		s = i;
	}
	R[s] = temp;
}

//����R�ģ�����0�Ĳ���
void Sort::HeapSort(DataType R[], int n)
{
	// ����󶥶�
	for (int i = n / 2; i > 0; i--)
	 	HeapAdjust(R, i, n);
	// ������ϣ���һ��������

	for (int i = n; i > 1; i--)
	{
		// ����������ֵ�������ķŵ������
		swap(R, 1, i);

		// ���¹���󶥶�
		HeapAdjust(R, 1, i - 1);
	}
}



// �鲢����
void Sort::MergeSort(DataType R[], int n)
{
	if (n > 1)
	{
		DataType* list_1 = R;
		int size_1 = n / 2;

		DataType* list_2 = R + size_1;
		int size_2 = n - size_1;

		// ������� 
		MergeSort(list_1, size_1);
		MergeSort(list_2, size_2);

		// �ϲ��׶�
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

	// ����ʣ��� 
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





