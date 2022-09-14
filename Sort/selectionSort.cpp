#include "selectionSort.h"

void selectionSort(int* a, int n)
{
	int minIdx;
	for (int i = 0; i < n - 1; i++)
	{
		minIdx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[minIdx])
			{
				minIdx = j;
			}
		}
		HoanVi(a[minIdx], a[i]);
	}
}