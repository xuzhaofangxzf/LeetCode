#pragma once
#include<iostream>
using namespace std;

void insertSort(int arr[], int n)
{
	if (n <= 0)
		return;
	int current;
	for (int i = 0; i < n - 1; i++)
	{
		current = arr[i + 1];
		int preIndex = i;
		while (preIndex >= 0 && current < arr[preIndex])
		{
			//将元素逐个向后移动
			arr[preIndex + 1] = arr[preIndex];
			preIndex--;
		}
		//假如比arr[preIndex]大，则应该放preIndex后面，假如是preIndex = -1,此时应该放到0处
		arr[preIndex + 1] = current;
	}
	return;
}