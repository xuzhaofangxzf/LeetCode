#pragma once
#include<iostream>
void merge(int arr[], int left, int mid, int r)
{
	//定义一个临时数组，保存排序后的数组
	int* arrTemp = new int[r - left + 1];
	//memset(arrTemp, 0, (r - left + 1) * 4);

	int i = left;
	int j = mid + 1;
	int index = 0;
	while (i <= mid && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			arrTemp[index++] = arr[i++];
		}
		else
		{
			arrTemp[index++] = arr[j++];
		}
	}
	//左侧的没有比较完
	while (i <= mid)
	{
		arrTemp[index++] = arr[i++];

	}
	//右侧的没有比较完
	while (j <= r)
	{
		arrTemp[index++] = arr[j++];
	}
	index = 0;
	while (left <= r)
	{
		arr[left++] = arrTemp[index++];
	}
	delete[] arrTemp;
	return;
}

void split(int arr[], int left, int r)
{
	if (left >= r)
		return;
	int mid = (r + left) / 2;
	split(arr, left, mid);
	split(arr, mid + 1, r);
	merge(arr, left, mid, r);
}
void mergeSort(int arr[], int n)
{
	split(arr, 0, n - 1);
	return;
}
