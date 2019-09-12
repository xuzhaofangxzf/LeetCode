#pragma once
#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{	
		int swapFlag = 0;//是否进行了交换(该方式是为了避免有序数组还要进行遍历）

		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swapFlag = 1;
				swap(arr[j], arr[j + 1]);
			}
		}
		if (swapFlag == 0)
		{
			return;
		}
	}
}
