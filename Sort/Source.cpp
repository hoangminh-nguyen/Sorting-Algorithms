#include "DataGenerator.h"
#include "sortingAlgorithms.h"
#include <chrono>
using namespace std::chrono;
int main()
{
	int *a;
	int n = 100000;
	a = new int[n];
	for (int i = 0; i < 4; i++)
	{
		GenerateData(a, n, i);
		//printArray(a, n);
		cout << endl;
		auto start = high_resolution_clock::now();
		//selectionSort(a, n);
		//insertionSort(a, n);
		//bubbleSort(a, n);
		quickSort(a, 0, n-1);
		//mergeSort(a, n);
		//heapSort(a, n);
		//radixSort(a, n);
		//binaryInsertionSort(a, n);
		//shakerSort(a, n);
		//shellSort(a, n);
		//flashSort(a, n);
		//countingSort(a, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		//printArray(a, n);
		cout << "\tRun time: " << duration.count() << " milliseconds" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	}
	delete[]a;
	return 0;
}