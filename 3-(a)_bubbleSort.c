#include <stdio.h>
void bubbleSort(int arr[])
{

	for (int i = 0; i < 8 - 1; i++)
	{
		for (int j = 0; j < 8 - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
		/*
		//step1~step5 까지 나타내는 출력문
		printf("%d번째 step! \n\n", i+1);
		for (int k = 0; k < 8; k++)
			printf("%d ", arr[k]);
		printf("\n\n");
		*/
	}
}
int main()
{
	int arr[8] = { 12,70,30,20,55,25,40,50 };
	bubbleSort(arr);
	for (int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	printf("\n");
}