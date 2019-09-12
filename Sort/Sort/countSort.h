#pragma once
#include <iostream>
void countSort(int arr[], int n)
{
	int maxVal = arr[0];
	int minVal = arr[0];
	//找出最大的数跟最小的数，以确定辅助数组的长度
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > maxVal)
		{
			maxVal = arr[i];
		}
		if (arr[i] < minVal)
		{
			minVal = arr[i];
		}
	}

	int arrSize = maxVal - minVal + 1;
	int* countArr = new int[arrSize];
	std::memset(countArr, 0, arrSize * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i] - minVal]++; //arr[i] - min 对应辅助数组空间的下标i,在此统计出了arr[i]出现的次数
	}
	int index = 0;
	for (int i = 0; i < arrSize; i++) //countArr[i] 代表（i + minVal）出现的次数
	{
		while (countArr[i]--)
		{
			arr[index++] = i + minVal;//有多少个，就依次往后排
		}
	}
	delete[] countArr;
}
