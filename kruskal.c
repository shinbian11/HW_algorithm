//�ּ� �ޱ�
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 14 //MAX�� ����9�� �����ִ� �׸��� ����Ǿ� �ִ� ������ ����
#define VERTEX 8

//������ ����ġ(weight)�� �� �� ������ ���� ���θ� �����ϴ� Node��� ����ü�� ����
typedef struct node
{
	int start;
	int end;
	int weight;
	int connect; //connect�� 1�̸� �ּ� ���� Ʈ�� �˰��� ���Ͽ� ����� �����̰�, 0�̸� ������� ���� �����̴�.
} Node;

#ifdef MAX
Node n[MAX]; //MAX ��� ��ũ�� ������ ���ǵǾ� �ִٸ� Node ���� ������ MAX�� ��ŭ ����.
#endif

#ifdef VERTEX
	// set �迭�� ����Ŭ�� �߻��ϴ��� ���θ� üũ�ϱ� ���� ����Ŭ ���̺�
int set[VERTEX]; //VERTEX ��� ��ũ�� ������ ���ǵǾ� �ִٸ� int ���� ������ VERTEX�� ��ŭ ����.
#endif
void initNode();//MAX���� Node ���� ������ �ʱ�ȭ.
int cmp(const Node* a, const Node* b); //qsort�� ���Լ�
int getParent(int set[], int x); //�θ� ��带 ������
void unionParent(int set[], int a, int b); //�θ� ��带 ����
int find(int set[], int a, int b); //�θ� ��尡 ������ Ȯ��
int main()
{
	initNode();

	qsort(n, MAX, sizeof(Node), cmp); //����ġ�� �������� ������������ Node �迭�� ����

	//set �迭 �ʱ�ȭ.
	for (int i = 0; i < VERTEX; i++)
		set[i] = i;

	int mindistance = 0; //�ּҰŸ��� ���� 0���� �ʱ�ȭ
	for (int i = 0; i < MAX; i++) //Node �迭�� index=0���� ������ ��������!
	{
		if (find(set, n[i].start - 1, n[i].end - 1) == 0) //� ������ �� ���� VERTEX���� �θ� ���� ���� �� => ����Ŭ�� ������ ���� ��
		{
			mindistance += n[i].weight; //�ּҰŸ��� �տ� �� ���ؼ� �ֱ�
			unionParent(set, n[i].start - 1, n[i].end - 1); //�θ� ����
			n[i].connect = 1; //����Ǿ����ϱ� 1�� �ٲٱ�
		}
	}

	//���
	printf("****** ũ�罺Į �˰����� �ּ� ����ġ ������ �� ******\n%d\n\n", mindistance);
	printf("****** �ּ� ��� ��� ******\n");
	for (int i = 0; i < MAX; i++)
	{
		if (n[i].connect == 1)
		{
			printf("��� : (v%d,v%d), ����ġ : %d\n", n[i].start, n[i].end, n[i].weight);
		}
	}
}

int getParent(int set[], int x) //�θ� ��带 ������
{
	if (set[x] == x)
		return x;
	else
		return set[x] = getParent(set, set[x]);
}
void unionParent(int set[], int a, int b) //�θ� ��带 ����
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a < b)
		set[b] = a;
	else
		set[a] = b;
}
int find(int set[], int a, int b) //�θ� ��尡 ������ Ȯ��
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b)
		return 1;
	else
		return 0;
}
int cmp(const Node* a, const Node* b) //qsort�� �� �Լ� (��������)
{
	if (a->weight > b->weight)
		return 1;
	else if (a->weight < b->weight)
		return -1;
	else
		return 0;
}
void initNode() //�ʱ�ȭ
{
	n[0].start = 1;
	n[0].end = 2;
	n[0].weight = 11;
	n[0].connect = 0;

	n[1].start = 1;
	n[1].end = 3;
	n[1].weight = 9;
	n[1].connect = 0;

	n[2].start = 1;
	n[2].end = 4;
	n[2].weight = 8;
	n[2].connect = 0;

	n[3].start = 2;
	n[3].end = 3;
	n[3].weight = 3;
	n[3].connect = 0;

	n[4].start = 2;
	n[4].end = 5;
	n[4].weight = 8;
	n[4].connect = 0;

	n[5].start = 2;
	n[5].end = 6;
	n[5].weight = 8;
	n[5].connect = 0;

	n[6].start = 3;
	n[6].end = 4;
	n[6].weight = 15;
	n[6].connect = 0;

	n[7].start = 3;
	n[7].end = 6;
	n[7].weight = 12;
	n[7].connect = 0;

	n[8].start = 3;
	n[8].end = 7;
	n[8].weight = 1;
	n[8].connect = 0;

	n[9].start = 4;
	n[9].end = 7;
	n[9].weight = 10;
	n[9].connect = 0;

	n[10].start = 5;
	n[10].end = 6;
	n[10].weight = 7;
	n[10].connect = 0;

	n[11].start = 5;
	n[11].end = 8;
	n[11].weight = 4;
	n[11].connect = 0;

	n[12].start = 6;
	n[12].end = 8;
	n[12].weight = 5;
	n[12].connect = 0;

	n[13].start = 7;
	n[13].end = 8;
	n[13].weight = 2;
	n[13].connect = 0;

}