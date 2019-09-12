#pragma once
#include <iostream>
void countSort(int arr[], int n)
{
	int maxVal = arr[0];
	int minVal = arr[0];
	//�ҳ�����������С��������ȷ����������ĳ���
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
		countArr[arr[i] - minVal]++; //arr[i] - min ��Ӧ��������ռ���±�i,�ڴ�ͳ�Ƴ���arr[i]���ֵĴ���
	}
	int index = 0;
	for (int i = 0; i < arrSize; i++) //countArr[i] ����i + minVal�����ֵĴ���
	{
		while (countArr[i]--)
		{
			arr[index++] = i + minVal;//�ж��ٸ���������������
		}
	}
	delete[] countArr;
}
