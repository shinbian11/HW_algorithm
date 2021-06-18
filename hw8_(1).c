//�ּ� �ޱ�
//HW8-(1)�� ���� (O(n^4) �� �ð����⵵)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1e9 //i���� j�� ���� ���� ������ ǥ���ϴ� ���Ѵ븦 �� �ڵ忡���� INF�� ǥ����

int W[8][8] = { {0,0,0,0,0,0,0,0}, {0,0,4,INF,INF,INF,10,INF},{0,3,0,INF,18,INF,INF,INF},{0,INF,6,0,INF,INF,INF,INF},{0,INF,5,15,0,2,19,5},{0,INF,INF,12,1,0,INF,INF}, {0,INF,INF,INF,INF,INF,0,10},{0,INF,INF,INF,8,INF,INF,0} };
int D[8][8]; //����ġ �� ���� �迭
int P[8][8]; //��� ���� �迭

int main()
{
	int n = 8; //index�� 1 ~ 7 �� ����ϱ� ���� n�� 7�� �ƴ� 8�� ����

	// D,P �迭 �ʱ�ȭ
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			D[i][j] = W[i][j]; //�ʱ� D�迭�� W �迭�� ���� ������!
		}
	}


	for (int m = 2; m < n; m++) //m == 1 �϶��� D[i][j] = W[i][j]�̴�. ������ ó����.
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				int min = INF;
				//min(D[i][k] + W[k][j])�� D[i][j]�� �ִ� ����
				for (int k = 1; k < n; k++)
				{
					if (min > D[i][k] + W[k][j]) //�ּڰ� ���ϱ�
					{
						min = D[i][k] + W[k][j];
					}
				}
				D[i][j] = min;
			}
		}
	}

	//��� �������� �ٸ� ��� �������� ���� �ִܰ��(�� ���õ鸶�� �ϳ��ϳ��� ������)�� ���� ����!

	printf("///////O(n^4) �˰��� ���� �Ϸ� �� ���̺�!///////\n\n");

	printf("- �Ÿ�(D) �迭\n");
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
}