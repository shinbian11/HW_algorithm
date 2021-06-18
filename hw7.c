
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5 //����� ����, ���� ũ��

int W[N + 1][N + 1] = { {0,0,0,0,0,0}, {0,0,8,13,18,20}, {0,3,0,7,8,10}, {0,4,11,0,10,7}, {0,6,6,7,0,11}, {0,10,6,2,1,0} }; //��� �ʱ�ȭ
//A�� �ִ� ���� 15�̱� ������ �迭 D,P�� ���� ������ �γ��ϰ� 20�� ���� ��������
int D[N + 1][20]; //dp(����ġ ��) ���� �迭. ���� D[3][12]�� ���� v3���� v1�� ���µ��� v4�� v5�� ���ļ� ���� �ϴ� ȸ�ε��� �ּҰ��� �����ϰ� �ִ�.
int P[N + 1][20]; //��� ���� �迭. ������ ȸ�θ� ã���� �� ��θ� ��� �ϱ� ���� �̿��Ѵ�.

int size;

void travel(int n);
int diff(int A, int j); //�迭 A���� Ư�� vertex�� �����ϴ� �Լ�
int isInside(int A, int x); // �迭 A���� x��° vertex�� ���ԵǾ� �ִ��� �Ǵ��ϴ� �Լ�
int contains(int A, int k); //A ���� �ȿ� �ִ� vertex�� ������ ��ȸ�ϴ� �Լ�. A �ȿ� �ִ� vertex�� ������ k���� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ
int getMin(int i, int A); // �ּ� ��� ã�� �Լ�
void printArray(); //�迭 D�� P�� ����ϴ� �Լ�(�����)
void printShortestCircuit(int i, int A); //���� ȸ���� ��� ���

int main()
{
	travel(N);

	printArray(); //�迭 D�� P�� ����ϴ� �Լ�(�����)

	printf("v1���� �����Ͽ� v1�� ���ƿ��� ���� ȸ�� : ");
	printf("v1 ");
	printShortestCircuit(1, 15); //���� ȸ�� ��� ���

	printf("���� ȸ���� min ���� %d�̴�.\n", D[1][size - 1]); //D[1][15]�� �� ���

	return 0;
}

void travel(int n)
{
	size = (int)pow(2, (double)n - 1);

	for (int i = 1; i <= n; i++)
	{
		D[i][0] = W[i][1]; //i��° vertex���� �ƹ��͵� ��ġ�� �ʰ� 1�� ���� ���(D[i][0])�� i��° vertex���� 1�� �ѹ��� ���� ���(W[i][1])�� ����.
	}

	for (int i = 1; i <= n; i++) //i��° vertex���� �ƹ��͵� ��ġ�� �ʰ� 1�� ���� ���(D[i][0])�� 1�� �����Ѵ�. �׻� �������� v1�̴ϱ�.
	{
		P[i][0] = 1;
	}

	for (int k = 1; k <= n - 2; k++)
	{
		for (int A = 1; A < size; A++)
		{
			if (contains(A, k) == 0) continue; //���� A �ȿ� k���� vertex�� �־�� �Ѵ�.
			for (int i = 2; i <= n; i++)
			{

				if (isInside(A, i) == 1) continue; //i�� 1�� �ƴϸ�, i��° vertex�� A�� ������ �ȵ�

				D[i][A] = getMin(i, A);
			}
		}
	}

	//�� 3��ø for ������ i=1�� �� ó���� ������ �ʾ����Ƿ�, i=1�� �� ó�� ���ֱ�!
	for (int A = 1; A < size; A++)
	{
		D[1][A] = getMin(1, A);
	}

}

int diff(int A, int j) //�迭 A���� Ư�� vertex�� �����ϴ� �Լ�
{
	return A & ~(1 << (j - 2));
}

int isInside(int A, int x) // �迭 A���� x��° vertex�� ���ԵǾ� �ִ��� �Ǵ��ϴ� �Լ�
{
	if (((A & (1 << x - 2)) != 0)) //x���� vertex�� A �ȿ� �ִ�.
		return 1;
	else //x��° vertex�� A �ȿ� ����.
		return 0;
}

int contains(int A, int k) //A ���� �ȿ� �ִ� vertex�� ������ ��ȸ�ϴ� �Լ�. A �ȿ� �ִ� vertex�� ������ k���� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ
{
	int cnt = 0;
	for (int i = 0; i <= N - 2; i++)
	{
		if ((A & (1 << i)) != 0) cnt++;
	}
	if (cnt != k)
		return 0;
	else
		return 1;
}

int getMin(int i, int A) // �ּ� ��� ã�� �Լ�
{

	int m;
	int min = 1e9;
	int minJ = 1e9;
	for (int j = 2; j < size; j++)
	{
		if (isInside(A, j) == 0) continue; //���� A �ȿ� j��° vertex�� �־�� ���� �ڵ带 ������ �� �ִ�.

		//(i��° vertex -> j��° vertex) + (j��° vertex���� v1�� �� ��, j��° vertex�� ������ ������ ���� A�� vertex���� ��� ���ļ� �������� �Ѵ�)
		m = W[i][j] + D[j][diff(A, j)];

		if (min > m) //���� �� m�� �ּҰ��̸� min�� m���� �ʱ�ȭ�Ѵ�.
		{
			min = m;
			minJ = j; // �� ���� j���� minJ�� �����س���,
		}

	}
	P[i][A] = minJ; // �������� minJ���� P�迭�� �����Ѵ�.
	return min;
}

void printArray() //�迭 D�� P�� ����ϴ� �Լ�
{
	printf("�迭 D�� ���Դϴ�.\n\n"); //D ���
	for (int i = 0; i < N + 1; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%3d", D[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	printf("�迭 P�� ���Դϴ�.\n\n"); //P ���
	for (int i = 0; i < N + 1; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%2d", P[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");
}
void printShortestCircuit(int i, int A) //���� ȸ���� ��� ���
{
	printf("v%d ", P[i][A]);

	if (A == 0)
	{
		printf("\n");
		return;
	}
	printShortestCircuit(P[i][A], diff(A, P[i][A])); //����Լ� �̿��Ͽ� ���
}