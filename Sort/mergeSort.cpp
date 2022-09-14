#include "mergeSort.h"

void mergeSort(int* &a, int n)
{
	if (n == 1) return;
	else
	{
		int sizeL = (n) / 2;
		int sizeR = n - sizeL;
		int* L = new int[sizeL];
		for (int i = 0; i < sizeL; i++)
		{
			L[i] = a[i];
		}

		int* R = new int[sizeR];
		for (int i = 0; i < sizeR; i++)
		{
			R[i] = a[i + sizeL];
		}

		mergeSort(L, sizeL);
		mergeSort(R, sizeR);
		merge(L, sizeL, R, sizeR, a);
	}
}
void merge(int* &L, int sizeL, int* &R, int sizeR, int* &a)
{
	a = new int[sizeL + sizeR];
	int i = 0, j = 0, k = 0;
	while (i < sizeL && j < sizeR)
	{
		a[k++] = L[i] < R[j] ? L[i++] : R[j++];
	}
	while (i < sizeL)
	{
		a[k++] = L[i++];
	}
	while (j < sizeR)
	{
		a[k++] = R[j++];
	}
}