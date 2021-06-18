//(a) ���� ������ ��ġ�� �ڵ��Դϴ�.
//���������� ���Ҹ� ���ĺ����� ǥ��������, ���ǻ� �ڵ忡���� ���ڷ� ǥ���߽��ϴ� (ex. a=1, b=2 ... z=26)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int p[4];
int rank[4];

int find(int x) //x�� �θ� ��带 ��������� �����ϸ� ���� ã��
{
	if (p[x] == x)
		return x;
	else
	{
		return p[x] = find(p[x]); //��� ���൵ �ѹ��� �Ҽ� �ְԲ� ����ȭ
	}
}

void union_(int x, int y) //��ħ
{
	x = find(x); //x�� ��Ʈ ��� ã��
	y = find(y); //y�� ��Ʈ ��� ã��
	if (x == y)
		return;
	if (rank[x] < rank[y]) //y�� �����ִ� Ʈ���� ��Ʈ ����� ��ũ�� �� ũ�ٸ� (y�� �����ִ� Ʈ���� �� ũ�ٸ�)
		p[x] = y; 
	else //�ƴϸ�
		p[y] = x;
	if (rank[x] == rank[y])
		rank[x]++;
}

int findParent(int a, int b) //�θ� ������ �ٸ��� �Ǵ������ν� ���� ���տ� �����ִ��� �ƴ����� �� �� ����
{
	a = find(a);// a�� �θ� ��� ã��
	b = find(b); // b�� �θ� ��� ã��
	if (a == b) return 1; // ���� �θ� ������ 1�� ����
	else return 0; // �ƴϸ� 0 ����
}

int main()
{
	for (int i = 1; i <= 3; i++)
	{
		p[i] = i;
		rank[i] = 0;
	}

	union_(1, 2); //1 <- 2 ������ ���� �����
	union_(1, 3); //1 <- 2 ������ ���հ� 3 ������ ������ ��ġ��

	//������ union �Ǿ����� Ȯ���غ��� (���Ƿ� �ΰ��� ���Ҹ� �Է��Ͽ� ���� ���տ� ���ԵǾ��ִ��� ���θ� �������ν� Ȯ�ΰ����ϴ�)
	while (true)
	{
		for (int i = 1; i <= 3; i++)
		{
			printf("%d ", i);
		}
		printf("�߿��� ���� ���տ� �ִ��� �ñ��� ���� �� ���� �Է��غ����� (����� 0 0 �Է�)> ");

		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			return 0;
		findParent(a, b) ? printf("%d �� %d �� ���� ���տ� �����ֽ��ϴ�.\n\n", a, b) : printf("%d �� %d �� ���� ���տ� �������� �ʽ��ϴ�.\n", a, b);
	}
	
} 