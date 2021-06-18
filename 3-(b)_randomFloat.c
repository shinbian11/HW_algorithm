#include <stdio.h>
#include <stdlib.h>
double arr[8];
double selection_arr[8];
double bubble_arr[8];
double insertion_arr[8];
double merge_arr[8];
double quick_arr[8];
double heap_arr[8];

//---------------선택 정렬 ----------------------------------------
void selectionSort(double arr[]) 
{

	for (int i = 0; i < 8 - 1; i++)
	{
		int idx = 0;
		for (int j = 0; j < 8 - i; j++)
		{
			if (arr[idx] >= arr[j])
			{
				idx = j;
			}
		}
		double temp = arr[idx];
		arr[idx] = arr[7 - i];
		arr[7 - i] = temp;
	}

}
//--------------버블 정렬 ----------------------------------------
void bubbleSort(double arr[])
{

	for (int i = 0; i < 8 - 1; i++)
	{
		for (int j = 0; j < 8 - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				double tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
//---------------삽입 정렬 ----------------------------------------
void insertionSort(double arr[], int n) { 

    for (int i = 1; i < n; i++) {
        double key = arr[i];

        int j;
        for (j = i - 1; j >= 0 && arr[j] < key; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }

}
//---------------병합 정렬 ----------------------------------------
double sort_arr[8];

void merge(double arr[], int left, int mid, int right) 
{
	int i = left, j = mid + 1, idx = left;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			sort_arr[idx++] = arr[j++];
		}
		else
		{
			sort_arr[idx++] = arr[i++];
		}
	}

	if (i <= mid)
	{
		for (int l = i; l <= mid; l++)
			sort_arr[idx++] = arr[l];
	}
	else
	{
		for (int l = j; l <= right; l++) 
			sort_arr[idx++] = arr[l];
	}

	for (int i = left; i <= right; i++)
		arr[i] = sort_arr[i];
}
void mergeSort(double arr[], int left, int right) 
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
//---------------퀵 정렬 ----------------------------------------
int partition(double arr[], int left, int right) 
{
	int low = left;
	int high = right - 1;
	int pivot = right;

	do {
		while (low <= right && arr[low] > arr[pivot])
		{
			low++;
		}


		while (high >= left && arr[high] < arr[pivot])
		{
			high--;
		}


		if (low < high) {
			double tmp = arr[low];
			arr[low] = arr[high];
			arr[high] = tmp;
		}
	} while (low < high);

	double tmp2 = arr[low];
	arr[low] = arr[pivot];
	arr[pivot] = tmp2;


	return low;

}

void quickSort(double arr[], int left, int right) { 

	if (left < right)
	{
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}

//---------------힙 정렬 ----------------------------------------
void heapify(double arr[], int here, int n) {
	int left = here * 2 + 1;
	int right = here * 2 + 2;
	int max = here;
	if (left < n && arr[left] < arr[max])
		max = left;
	if (right < n && arr[right] < arr[max])
		max = right;

	if (max != here) {
		double tmp = arr[here];
		arr[here] = arr[max];
		arr[max] = tmp;
		heapify(arr, max, n);
	}
}

void buildHeap(double arr[], int n) {

	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, i, n);
	}
}

void heapSort(double arr[], int n) {
	buildHeap(arr, n);
	for (int treeSize = n - 1; treeSize >= 0; treeSize--) {
		double tmp = arr[0];
		arr[0] = arr[treeSize];
		arr[treeSize] = tmp;
		heapify(arr, 0, treeSize);
	}
}
//---------------------메인 --------------------------
int main()
{
	srand(time(NULL));
	for (int i = 0; i < 8; i++)
	{
		arr[i] = (rand() / (double)RAND_MAX*2)-(double)1;

		selection_arr[i] = arr[i];
		bubble_arr[i] = arr[i];
		insertion_arr[i] = arr[i];
		merge_arr[i] = arr[i];
		quick_arr[i] = arr[i];
		heap_arr[i] = arr[i];
	}

	selectionSort(selection_arr);
	bubbleSort(bubble_arr);
	insertionSort(insertion_arr, 8);
	mergeSort(merge_arr, 0, 7);
	quickSort(quick_arr, 0, 7);
	heapSort(heap_arr, 8);

	//*****selectionSort*****

	printf("*****selectionSort 결과!*****\n\n");
	for (int i = 0; i < 8; i++)
		printf("%.3f ", selection_arr[i]);
	printf("\n\n");

	//*****bubbleSort*****

	printf("*****bubbleSort 결과!*****\n\n");
	for (int i = 0; i < 8; i++)
		printf("%.3f ", bubble_arr[i]);
	printf("\n\n");

	//*****insertionSort*****

	printf("*****insertionSort 결과!*****\n\n");
	for (int i = 0; i < 8; i++)
		printf("%.3f ", insertion_arr[i]);
	printf("\n\n");

	//*****mergeSort*****

	printf("*****mergeSort 결과!*****\n\n");
	for (int i = 0; i < 8; i++)
		printf("%.3f ", merge_arr[i]);
	printf("\n\n");

	//*****quickSort*****

	printf("*****quickSort 결과!*****\n\n");
	for (int i = 0; i < 8; i++)
		printf("%.3f ", quick_arr[i]);
	printf("\n\n");

	//*****heapSort*****

	printf("*****heapSort 결과!*****\n\n");
	for (int i = 0; i < 8; i++)
		printf("%.3f ", heap_arr[i]);
	printf("\n\n");

	
}