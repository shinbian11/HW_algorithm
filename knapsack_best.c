//�ּ� �ޱ�

//�̿ϼ�.. ���۸��� ���� c���� �ִ��� �켱���� ť�� �����غ����� ������ ���ϴ� ����� ���� ���߽��ϴ�..

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct item {
	int p;
	int w;
	int level; //�� ����� ����
} ITEM;

int W = 9; //������ ���� ����

int w[5] = { 2,5,7,3,1 }; //���ǵ��� ���Ը� ����� �迭
int p[5] = { 20,30,35,12,3 }; //���ǵ��� ��ġ�� ����� �迭

int profit = 0;
int maxprofit = 0;
int totalprofit = 0;
int weight = 0;
int idx = 0;
//c���δ� �켱���� queue�� �������� �����Ƿ�, c���� �켱���� ť�� ����

ITEM p_queue[100]; //���� ����

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insert(ITEM* p_queue, ITEM p, int idx) //�켱���� ť�� insert �ϴ� �Լ�
{
	if (idx <= 0)
		return;

	int insertValue = p.p;
	p_queue[idx]= p;
	
	int current, parent;
	if (idx == 1)
	{
		current = 1;
		parent = 1;
	}
	else
	{
		current = idx;
		parent = (idx - 1) / 2;
	}


	while (current > 0 && p_queue[current].p > p_queue[parent].p) {
		swap(&p_queue[current].p, &p_queue[parent].p);
		current = parent;
		parent = (parent - 1) / 2;
	}
	idx++;

}

ITEM delete(ITEM* p_queue, int idx) //�켱���� ť���� delete �ϴ� �Լ�
{

	ITEM ans = p_queue[0];

	idx--;
	p_queue[0] = p_queue[idx];

	int current = 0;
	int max = current;
	int leftChild = current * 2 + 1;
	int rightChild = current * 2 + 2;
	

	while (leftChild < idx) {
		if (p_queue[max].p < p_queue[leftChild].p) {
			max = leftChild;
		}
		if (rightChild < idx && p_queue[max].p < p_queue[rightChild].p) {
			max = rightChild;
		}
		if (max == current) break;
		else {
			swap(&p_queue[current].p, &p_queue[max].p);
			current = max;
			leftChild = current * 2 + 1;
			rightChild = current * 2 + 2;
		}
	}
	return ans;
}

int Isempty(ITEM* p_queue) //�켱���� ť�� ������� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ
{
	if (idx == 0)
		return 1;
	else
		return 0;
}

int promising(int i, int profit, int weight) { //������ ������� Ȯ��(�� �κ��� bfs �� ���� ����)

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

	insert(p_queue, v, idx);

	while(!Isempty(p_queue))
	{
		v = delete(p_queue, idx);

		if (promising(v.level,v.p,v.w))
		{
			u.level = v.level + 1; //u�� v�� �ڽ� ����̹Ƿ� level�� 1 �����Ѵ�.

			u.p = v.p + p[u.level];
			u.w = v.w + w[u.level];

			if ((u.w <= W) && (u.p > maxprofit)) //�ڽ� ����� ���԰� W���� �۰�, ��ġ�� maxprofit���� ũ��
			{
				maxprofit = u.p; //u.p�� maxprofit�� �����Ͽ� �� ����
			}

			if (promising(u.level, u.p, u.w)) //�ڽ� ��尡 ������ ����� 
			{
				insert(p_queue, u, idx);
			}

			u.p = v.p;
			u.w = v.w;

			if (promising(u.level, u.p, u.w)) //�ڽ� ��尡 ������ ����� 
			{
				insert(p_queue, u, idx);
			}
		}

	}
}
int main()
{
	knapsack(profit, weight); //���� �˰��� ����

	//����ϱ�!
	printf("���� �˰��� by best\n\n");
	printf("�ִ� ��ġ : %d\n", maxprofit);

	return 0;
}