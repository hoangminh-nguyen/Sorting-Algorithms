#include "bubbleSort.h"

void bubbleSort(int* a, int n)
{
	for (int i = 1; i <n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (a[j] < a[j - 1])
			{
				HoanVi(a[j], a[j - 1]);
			}
		}
	}
}