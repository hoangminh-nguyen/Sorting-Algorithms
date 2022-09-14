#include "binaryInsertionSort.h"
//n2
void binaryInsertionSort(int* a, int n)
{
	int i, j, v;
	for (int i = 1; i < n; i++) 
	{
		v = a[i];
		j = i - 1;
		int search = binarySearch(a, j, a[i]);
		while (j >= search) 
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
	}
}

int binarySearch(int* a, int n, int key){
	int left = 0;
	int right = n;
	int mid = (left + right) / 2;
	while (left < right){
		if (a[mid] == key) return mid + 1;
		if (a[mid] > key){
			right = mid-1;
			mid = (left + right) / 2;
		}
		else if (a[mid] < key){
			left = mid+1;
			mid = (left + right) / 2;
		}
	}
	return key > a[left] ? left+1 : left;
}

