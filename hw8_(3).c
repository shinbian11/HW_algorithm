//�ּ� �ޱ�
//HW8-(3)�� ����
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1e9 //i���� j�� ���� ���� ������ ǥ���ϴ� ���Ѵ븦 �� �ڵ忡���� INF�� ǥ����

//v1~v7�� a7~a1���� �ٲ�� �ϹǷ�, W�� �迭�� ��� ��� ���� ���� �˸°� ������� �Ѵ�.
int W[8][8] = { {0,0,0,0,0,0,0,0},{0,0,INF,INF,8,INF,INF,INF},{0,10,0,INF,INF,INF,INF,INF},{0,INF,INF,0,1,12,INF,INF},{0,5,19,2,0,15,5,INF},{0,INF,INF,INF,INF,0,6,INF},{0,INF,INF,INF,18,INF,0,3},{0,INF,10,INF,INF,INF,4,0} };

int D[8][8]; //����ġ �� ���� �迭
int P[8][8]; //��� ���� �迭

void path(int q, int r) //�ִܰŸ� ��� ���ϴ� �Լ�
{

	if (P[q][r] != 0)
	{
		path(q, P[q][r]);
		printf("a%d ", P[q][r]); //��� ���
		path(P[q][r], r);
	}
}
int main()
{
	int n = 8; //index�� 1 ~ 7 �� ����ϱ� ���� n�� 7�� �ƴ� 8�� ����

	// D,P �迭 �ʱ�ȭ
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			D[i][j] = W[i][j]; //�ʱ� D�迭�� W �迭�� ���� ������
			P[i][j] = 0; //P�迭�� �ϴ� 0���� �ʱ�ȭ
		}
	}

	//�÷��̵� �ͼ� �˰��� ���
	for (int k = 1; k < n; k++)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (D[i][j] > D[i][k] + D[k][j]) //i���� j�� ����, �ѹ��� ���� �ͺ��� ���ļ� ���� ���� �� optimal�ϴٸ�
				{
					D[i][j] = D[i][k] + D[k][j]; //D[i][j]�� optimal�� ����� ������ �ٲٰ�
					P[i][j] = k; //�׶��� �߰� ��θ� k�� ����
				}
			}
		}
	}

	//�÷��̵� �ͼ� �˰����� ����� ����(�迭 D,P ���, a5���� a2���� ���� �ִ� ��� ���)

	printf("///////�÷��̵� �ͼ� �˰��� �Ϸ� �� ���̺�!///////\n\n");

	printf("- �Ÿ�(D) �迭 (a1,a2,a3...a7 ����)\n");
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			printf("%d ", D[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("- ���� ���(P) �迭 (a1,a2,a3...a7 ����)\n");
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			printf("%d ", P[i][j]);
		printf("\n");
	}
	printf("\n\n");


	printf("///a5���� a2���� ���� �ִ� �Ÿ� ��� ���///\n");

	printf("a%d ", 5); //a5 ���
	path(5, 2); //a5���� a2���� ���� �ִܰŸ� ��� ���ϴ� �Լ�
	printf("a%d\n", 2); //a2 ���

	printf("\n");
	printf("������ v1 ~ v7�� ���� ���� ������ a7 ~ a1���� ���� ���� ��δ� ǥ����� �ٸ� ��, �ִܰŸ� ����� ������ ����!\n\n");

}