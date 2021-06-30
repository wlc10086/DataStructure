#include "Sort.h"

int main(void)
{
	// 统一第0个不存放数据
	//DataType R[10] = {-1, 50,80,10,30,20,40,70,90,60};
	
	DataType R[] = { -1, 20, 50, 40, 30, 10,  60 };
	int size = sizeof(R) / sizeof(DataType);
	Sort s;

	//s.BobbleSort(R, size - 1);
	s.QuickSort(R, size - 1);
	
	// s.SelectSort(R, size - 1);
	
	//s.HeapSort(R, size -1);
	//s.BobbleSort(R, size);
	s.ShowList(R, 1, size);

	return 0;
}