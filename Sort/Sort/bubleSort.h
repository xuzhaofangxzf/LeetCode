#pragma once
#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{	
		int swapFlag = 0;//�Ƿ�����˽���(�÷�ʽ��Ϊ�˱����������黹Ҫ���б�����

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
