#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>

#define MAX_SIZE 100
typedef int DataType;

class Sort
{
public:
	// ��ӡ 
	void ShowList(DataType R[], int begin, int end);
	
	// ð������ 
	void BobbleSort(DataType R[], int n);
	
	// �������� 
	void QuickSort(DataType R[], int n);
	
	// ֱ�Ӳ������� 
	void InsertSort(DataType R[], int n);
	
	// ϣ������ 
	void ShellSort(DataType R[], int n);
	
	// ѡ������ 
	void SelectSort(DataType R[], int n);
	
	// ������ 
	void HeapSort(DataType R[], int n);
	
	// �鲢���� 
	void MergeSort(DataType R[], int n);
	
private:
	void QuickSort(DataType R[], int left, int right);

	void HeapAdjust(DataType R[], int s, int n);	
	
	void Meging(DataType *R1, int size1, DataType *R2, int size2);
};

#endif //_SORT_H
