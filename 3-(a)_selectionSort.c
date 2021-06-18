#include <stdio.h>
void selectionSort(int arr[])
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
		int temp = arr[idx];
		arr[idx] = arr[7 - i];
		arr[7 - i] = temp;

		/*
		//step1~step5 까지 나타내는 출력문
		printf("%d번째 step! \n\n", i + 1);
		for (int k = 0; k < 8; k++)
			printf("%d ", arr[k]);
		printf("\n\n");
		*/
	}
	
}
int main()
{
	int arr[8] = { 12,70,30,20,55,25,40,50 };
	selectionSort(arr);
	for (int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	printf("\n");
}