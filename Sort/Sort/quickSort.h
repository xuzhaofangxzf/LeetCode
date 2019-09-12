#pragma once
#include <iostream>
#include <ctime>
using namespace std;

void partitionSort(int arr[], int l, int r)
{
	if (l >= r)
		return;
	//Ϊ�˱������������˻�ΪO(n2)��ʱ�临�Ӷȣ��������ѡ��һ��������Ϊ��׼����
	srand(time(NULL));
	swap(arr[l], arr[rand() % (r - l + 1) + l]);//�������l...r֮��
	int i = l;
	int j = r;
	int baseValue = arr[l];//ȡ����׼����
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

		//�����ұ������ҵ���һ���Ȼ�����������ŵ�arr[r]��λ��
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
	//Ϊ�˱������������˻�ΪO(n2)��ʱ�临�Ӷȣ��������ѡ��һ��������Ϊ��׼����
	srand(time(NULL));
	swap(arr[l], arr[rand() % (r - l + 1) + l]);//�������l...r֮��
	int i = l;
	int baseValue = arr[l];//ȡ����׼����
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
			//��ʱi����++����Ϊ�����Ԫ�ز�û�б�����������Ҫ��һ�ֽ����ж�
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