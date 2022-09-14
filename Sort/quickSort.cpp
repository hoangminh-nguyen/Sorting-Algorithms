#include "quickSort.h"

int Partition(int* a, int left, int right)
{
	int p = a[left];
	int i = left;
	int j = right + 1;
	do {
		do i++; while (a[i] < p);
		do j--; while (a[j] > p);
		swap(a[i], a[j]);
	} while (i < j);
	swap(a[i], a[j]);
	swap(a[left], a[j]);
	return j;
}
void quickSort(int* a, int left, int right)
{
	if (left < right)
	{
		int s = Partition(a, left, right); //s la vi tri cuoi cung cua a[left] trong mang sau khi sort
		quickSort(a, left, s - 1);
		quickSort(a, s+1, right);
	}
}