#include <stdio.h>
#include <stdbool.h>

int arr[13] = { 0 };
bool visited[13] = { false };
int element[8] = { 10,20,30,40,33,46,50,60 };

int main()
{

	for (int i = 0; i < 8; i++)
	{
		if (visited[element[i] % 13] == false) //���� mod 13�� �ش��ϴ� �ε����� ���� ���� ������ ���� �ʾҴٸ�
		{
			arr[element[i] % 13] = element[i]; // �������ְ�
			visited[element[i] % 13] = true; // �� �κ��� �����ߴٰ� true�� �ٲپ��ֱ�
		}
		else //�̹� ���� ����Ǿ� �ִٸ�, �浹�� �߻��ϹǷ�, ���� ���� ��� �̿�
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

		//print �ϴ� �κ�
		printf("%d�� �־��� ��!\n", element[i]);
		for (int j = 0; j < 13; j++)
		{
			if (arr[j] != 0)
				printf("%-d %5d\n", j, arr[j]);
			else
				printf("%-3d %5s\n", j, "NULL"); //���� ���� ������ ���ǻ� NULL�� ǥ���߽��ϴ�.
		}
		printf("\n\n");
	}
		
}