#include "Sort.h"

void main(void)
{
	DataType R[] = {6,5,8,1,3,2,4,7,9,0};
	int size = sizeof(R) / sizeof(DataType);
	Sort s;

	s.HeapSort(R, size -1);
	//s.BobbleSort(R, size);
	s.ShowList(R, size);
}