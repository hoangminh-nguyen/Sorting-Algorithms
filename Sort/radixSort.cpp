#include "radixSort.h"

void radixSort(int* a, int n)
{
	int k = findMax(a, n);
	int exp = 1;
	for (; k / exp > 0; exp *= 10)
	{
		sort(a, n, exp);
	}
}
void sort(int* a, int n, int exp)
{
	int count[10] = { 0 };
	for (int i = 0; i < n; i++)
	{
		count[a[i] / exp % 10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	int* b = new int[n];
	for (int i = n - 1; i >= 0; i--)
	{
		b[count[a[i] / exp % 10] - 1] = a[i];
		count[a[i] / exp % 10]--;
	}
	for (int i = 0; i <n; i++)
	{
		a[i] = b[i];
	}
	delete[]b;
}