#pragma once
#include <iostream>
#include <ctime>
using namespace std;

void partitionSort(int arr[], int l, int r)
{
	if (l >= r)
		return;
	//为了避免有序数组退化为O(n2)的时间复杂度，首先随机选择一个数据作为基准数据
	srand(time(NULL));
	swap(arr[l], arr[rand() % (r - l + 1) + l]);//随机数在l...r之间
	int i = l;
	int j = r;
	int baseValue = arr[l];//取出基准数据
	while (i < j)
	{
		while (i < j && arr[j] >= baseValue)
		{
			j--;
		}
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}

		//从左到右遍历，找到第一个比基数大的数，放到arr[r]的位置
		while (i < j && arr[i] <= baseValue)
		{
			i++;
		}
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	arr[i] = baseValue;
	partitionSort(arr, l, i - 1);
	partitionSort(arr, j + 1, r);
}
void partitionSort3(int arr[], int l, int r)
{
	if (l >= r)
		return;
	//为了避免有序数组退化为O(n2)的时间复杂度，首先随机选择一个数据作为基准数据
	srand(time(NULL));
	swap(arr[l], arr[rand() % (r - l + 1) + l]);//随机数在l...r之间
	int i = l;
	int baseValue = arr[l];//取出基准数据
	int lt = l;     // arr[l+1...lt] < v
	int gt = r + 1; // arr[gt...r] > v

	while (i < gt)
	{
		if (arr[i] < baseValue)
		{
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if (arr[i] > baseValue)
		{
			swap(arr[gt - 1], arr[i]);
			gt--;
			//此时i不可++，因为后面的元素并没有保存下来，需要下一轮进行判定
		}
		else
		{
			i++;
		}

	}
	swap(arr[l], arr[lt]);

	partitionSort3(arr, l, lt - 1);
	partitionSort3(arr, gt, r);

}
void quickSort(int arr[], int n)
{
	partitionSort(arr, 0, n - 1);
}