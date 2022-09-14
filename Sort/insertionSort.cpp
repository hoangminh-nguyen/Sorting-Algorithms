#include "insertionSort.h"

void insertionSort(int* a, int n)
{
	int i, j, v;
	for (int i = 1; i < n; i++) 
	{
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
	}
}