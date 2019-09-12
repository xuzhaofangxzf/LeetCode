// Sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "insertSort.h"
#include "SortTestHelper.h"
#include "quickSort.h"
#include "mergeSort.h"
#include "bubleSort.h"
#include "cockTailSort.h"
#include "selectionSort.h"
#include "heapSort.h"
#include "countSort.h"
int main()
{
	const int n = 20;
	int* arr = SortTestHelper::generateRandomArray(n, 10, 10000);
	//int arr[] = { 1, 2, 4, 5, 6, 6, 7, 8 };
	SortTestHelper::printArray(arr, n);
	cout << "=======================================================================" << endl;
	//heapSort(arr, n);
	//SortTestHelper::printArray(arr, n);

	SortTestHelper::testSort("Selection Sort", countSort, arr, n);
	if (SortTestHelper::isSorted(arr, n))
	{
		cout << "Arr is Sorted!" << endl;
	}
	else
	{
		cout << "Arr is unSorted!" << endl;

	}
	SortTestHelper::printArray(arr, n);
	return 0;
	//initializer_list<std::string> il{ "a", "an", "the" };

}
