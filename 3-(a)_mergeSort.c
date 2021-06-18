#include <stdio.h>
int sort_arr[8];
void merge(int arr[], int left, int mid, int right)
{
	int i=left, j=mid+1, idx=left;
	
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
		for(int l=i;l<=mid;l++)
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
void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
		
	}
	/*
	//단계별 출력문
	for (int i = left; i <= right; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
	*/
}
int main()
{
	int arr[8] = { 12,70,30,20,55,25,40,50 };
	mergeSort(arr, 0, 7);
	
	for (int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	
	printf("\n");
}