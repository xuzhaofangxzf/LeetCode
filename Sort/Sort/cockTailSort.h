#pragma once
#include <iostream>
using namespace std;
/*
鸡尾酒排序算法，冒泡排序算法的改进版本，
从左至右，先将最大元素放到最后，然后从右至左，把最小的元素放到前面
*/
void cockTailSort(int arr[], int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		for (int i = left; i < right; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			}
		}
		right--;
		for (int j = right; j > left; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
			}
		}
		left++;
	}
}
