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
			//��Ԫ���������ƶ�
			arr[preIndex + 1] = arr[preIndex];
			preIndex--;
		}
		//�����arr[preIndex]����Ӧ�÷�preIndex���棬������preIndex = -1,��ʱӦ�÷ŵ�0��
		arr[preIndex + 1] = current;
	}
	return;
}