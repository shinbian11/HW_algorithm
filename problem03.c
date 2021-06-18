#include <stdio.h>
#include <stdbool.h>

int arr[13] = { 0 };
bool visited[13] = { false };
int element[8] = { 10,20,30,40,33,46,50,60 };

int main()
{

	for (int i = 0; i < 8; i++)
	{
		if (visited[element[i] % 13] == false) //원소 mod 13에 해당하는 인덱스에 아직 값이 저장이 되지 않았다면
		{
			arr[element[i] % 13] = element[i]; // 저장해주고
			visited[element[i] % 13] = true; // 그 부분을 저장했다고 true로 바꾸어주기
		}
		else //이미 값이 저장되어 있다면, 충돌이 발생하므로, 선형 조사 방법 이용
		{
			for (int k = 1;; k++)
			{
				if (visited[(element[i] + k) % 13] == false)
				{
					arr[(element[i] + k) % 13] = element[i];
					visited[(element[i] + k) % 13] = true;
					break;
				}
			}
		}

		//print 하는 부분
		printf("%d를 넣었을 때!\n", element[i]);
		for (int j = 0; j < 13; j++)
		{
			if (arr[j] != 0)
				printf("%-d %5d\n", j, arr[j]);
			else
				printf("%-3d %5s\n", j, "NULL"); //값이 없는 공간은 편의상 NULL로 표기했습니다.
		}
		printf("\n\n");
	}
		
}