#pragma once
#include <iostream>
void heapify(int arr[], int i, int n)
{
	int lChild = 2 * i + 1;
	int rChild = 2 * i + 2;
	int maxIndex = i;
	if (lChild < n && arr[lChild] > arr[maxIndex])
	{
		maxIndex = lChild;
	}
	if (rChild < n && arr[rChild] > arr[maxIndex])
	{
		maxIndex = rChild;
	}
	if (maxIndex != i)
	{
		std::swap(arr[i], arr[maxIndex]);
		heapify(arr, maxIndex, n);
	}
}
void buildHeap(int arr[], int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		heapify(arr, i, n);
	}
}
void heapSort(int arr[], int n)
{
	buildHeap(arr, n);
	int heapSize = n;
	while (heapSize > 1)
	{
		std::swap(arr[0], arr[heapSize - 1]);
		heapSize--;
		heapify(arr, 0, heapSize);
	}

}
