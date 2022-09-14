#include "countingSort.h"
//n+k, k:ragne of input
void countingSort(int* a, int n)
{
	int b = findMax(a, n)+1;
	int* count = new int[b];
	for (int i = 0; i < b; i++)
	{
		count[i] = 0;
	}
	//dem so lan xuat hien cua cac phan tu
	for (int i = 0; i < n; i++)
	{
		count[a[i]]++;
	}
	for (int i = 1; i < b; i++)
	{
		count[i] += count[i - 1];
	}
	int* temp = new int[n];
	for (int i = 0; i < n; i++) 
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}
	for (int i = 0; i < n; i++)
	{
		a[i]=temp[i];
	}
	delete []count, temp;
}
int findMax(int* a, int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}