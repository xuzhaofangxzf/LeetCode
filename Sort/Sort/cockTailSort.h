#pragma once
#include <iostream>
using namespace std;
/*
��β�������㷨��ð�������㷨�ĸĽ��汾��
�������ң��Ƚ����Ԫ�طŵ����Ȼ��������󣬰���С��Ԫ�طŵ�ǰ��
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
