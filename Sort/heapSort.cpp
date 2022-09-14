#include "heapSort.h"
//nlogn
void heapify(int* a, int n, int i)//logn
{
	int max = i; 
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 

	if (left < n && a[left] > a[max])
	{
		max = left;
	}

	if (right < n && a[right] > a[max])
	{
		max = right;
	}

	if (max != i)
	{
		HoanVi(a[i], a[max]);
		heapify(a, n, max);
	}
}
void heapSort(int* a, int n)
{
	// Sap xep lai mang theo dang Heap
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}

	// Sap xep theo thu tu tang dan
	for (int i = n - 1; i >= 0; i--)
	{
		HoanVi(a[0], a[i]);
		heapify(a, i, 0);
	}
}