//�ּ� �ޱ�
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct item {
	int p;
	int w;
	int level;
} ITEM;

int W = 9; //������ ���� ����

int w[5] = { 2,5,7,3,1 }; //���ǵ��� ���Ը� ����� �迭
int p[5] = { 20,30,35,12,3 }; //���ǵ��� ��ġ�� ����� �迭

int profit = 0;
int maxprofit = 0;
int totalprofit = 0;
int weight = 0;

//c���δ� queue�� �������� �����Ƿ�, c���� ť�� ������ ����
ITEM queue[100];
int head = 0, tail = 0;

void enqueue(ITEM* queue, ITEM i) //ť�� enqueue �ϴ� �Լ�
{
	queue[head++] = i; //�׳� enqueue�ϰ� head �ε����� ����
}
ITEM dequeue(ITEM* queue) //ť���� dequeue �ϴ� �Լ�
{
	return queue[tail++]; //ITEM �ڷ����� ��带 ��ȯ. dequeue �ϰ� tail �ε��� ����
}
int queue_empty(ITEM* queue) //ť�� ������� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ
{
	//head�� tail�� ó�� �ʱ�ȭ �� �� �������� 0�ε�, ť�� ������� Ȯ���ϴ� ��Ȳ�� �ʱ�ȭ ��Ȳ������ Ȯ���ϸ� �ȵǱ� ������ tail != 0�̶�� ���ǵ� �־���
	return (tail != 0 && head == tail);
}


int promising(int i, int profit, int weight) { //������ ������� Ȯ��

	int j, k;
	int totalweight;
	int bound;

	if (weight >= W) 	// ������ weight�� �ִ� ���Ը� ���� ��� 0�� ����
		return 0;
	else {
		j = i + 1;
		bound = profit;
		totalweight = weight;

		while ((j < 5) && (totalweight + w[j] <= W)) //W���� ���԰� Ŀ�� ������ ������ ��������(���԰� ������ִ� ������ ���ϱ�)
		{
			totalweight += w[j];
			bound += p[j];
			j++;
		}
		k = j;
		if (k < 5)
		{
			bound += (W - totalweight) * p[k] / w[k]; //�Ѱ�ġ�� ���ϴ� �۾� (������ �κ��� ����� ä��� ������ ����ؼ�, �Ѱ�ġ�� ���Ѵ�)
		}
		return bound > maxprofit;
		//�� ��谪�� maxprofit���� �۴ٸ�, ������ �ƹ��� ����غ��� ������ ���� ���� Ȯ���� ���� ����̹Ƿ�, 0�� ��ȯ�Ͽ� �� ��忡���� Ž���� �����Ѵ�.
	}
}
void knapsack(int profit, int weight)
{
	ITEM u, v;

	//�ʱ�ȭ
	maxprofit = 0;
	v.level = -1;
	v.p = 0; 
	v.w = 0;

	enqueue(queue,v);
	while (!queue_empty(queue)) //ť�� ������� �ʴٸ�
	{
		v = dequeue(queue); //�� ���� ITEM�� dequeue�Ѵ�.

		u.level = v.level + 1; //u�� v�� �ڽ� ����̹Ƿ� level�� 1 �����Ѵ�.

		u.p = v.p + p[u.level];
		u.w = v.w + w[u.level];

		if ((u.w <= W) && (u.p > maxprofit)) //�ڽ� ����� ���԰� W���� �۰�, ��ġ�� maxprofit���� ũ��
		{
			maxprofit = u.p; //u.p�� maxprofit�� �����Ͽ� �� ����
		}

		if (promising(u.level, u.p, u.w)) //�ڽ� ��尡 ������ ����� 
			enqueue(queue, u); //ť�� �ִ´�.

		u.p = v.p;
		u.w = v.w;

		if (promising(u.level, u.p, u.w)) //�ڽ� ��尡 ������ ����� 
			enqueue(queue, u); //ť�� �ִ´�.
	}
}
int main()
{
	knapsack(profit, weight); //���� �˰��� ����
	
	//����ϱ�!
	printf("���� �˰��� by bfs\n\n");
	printf("�ִ� ��ġ : %d\n", maxprofit);

	return 0;
}