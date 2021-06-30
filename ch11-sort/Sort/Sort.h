#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>

#define MAX_SIZE 100
typedef int DataType;


void swap(DataType R[], int i, int j);


class Sort
{
public:
	// ¥Ú”° 
	void ShowList(DataType R[], int begin, int end);
	
	// √∞≈›≈≈–Ú 
	void BobbleSort(DataType R[], int n);
	
	// øÏÀŸ≈≈–Ú 
	void QuickSort(DataType R[], int n);
 	
	// ÷±Ω”≤Â»Î≈≈–Ú 
	void InsertSort(DataType R[], int n);
	
	// œ£∂˚≈≈–Ú 
	void ShellSort(DataType R[], int n);
	
	// —°‘Ò≈≈–Ú 
	void SelectSort(DataType R[], int n);
	
	// ∂—≈≈–Ú 
	void HeapSort(DataType R[], int n);
	
	// πÈ≤¢≈≈–Ú 
	void MergeSort(DataType R[], int n);
	
private:
	void QuickSort(DataType R[], int left, int right);

	void HeapAdjust(DataType R[], int s, int n);	
	
	void Meging(DataType *R1, int size1, DataType *R2, int size2);
};

#endif //_SORT_H
