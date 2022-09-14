#include "flashSort.h"

void flashSort(int *a, int n)
{
	if (n == 0) return;
	int m = (int)((0.2 * n) + 2); //so phan lop

	//CLASS FORMATION O(n)
	int min, max, maxIndex = 0;
	min = max = a[0];
	

	for (int i = 1; i < n; i++)
	{
		if (a[i] < min) min = a[i];
		else if (a[i] > max)
		{
			max = a[i];
			maxIndex = i;
		}
	}

	if (max == min)
	{
		return; //all the elements are the same
	}

	int* L = new int[m + 1]; //khong su dung L[0], L la mang chua so phan tu cua tung phan lop
	for (int i = 1; i < m + 1; i++)
	{
		L[i] = 0;
	}

	int K; //K thuoc 1...m
	for (int i = 0; i < n; i++)
	{
		K = 1 + (int)((m - 1) * (a[i] - min) / (max - min));
		L[K] += 1;
	}
	for (K = 2; K <= m; K++)
	{
		L[K] = L[K] + L[K - 1];
	}

	//-------PERMUTATION-------
	HoanVi(a[maxIndex], a[0]);
	int j = 0, numMoves = 0;
	K = m;
	while (numMoves < n)
	{
		while (j >= L[K])
		{
			j++;
			K = 1 + (int)((m - 1) * (a[j] - min) / (max - min));
		}
		int evicted = a[j];
		while (j < L[K])
		{
			K = 1 + (int)((m - 1) * (evicted - min) / (max - min));
			int location = L[K] - 1;
			HoanVi(a[location], evicted);
			L[K] --;
			numMoves++;
		}
	}

	//-------RECURSION or STRAIGHT INSERTION-------
	int threshold = (int)(1.25 * ((n / m) + 1));
	const int minE = 30;
	for (K = m - 1; K >= 1; K--)
	{
		int classSize = L[K + 1] - L[K];
		if (classSize > threshold && classSize > minE)
		{
			flashSort(&a[L[K]], classSize);
		}
		else
		{
			if (classSize > 1) insertionSort(&a[L[K]], classSize);
		}
	}

	delete[] L;
}
