//�ּ� �ޱ�
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int W = 9; //������ ���� ����

bool include[5] = { 0, }; //���ǵ��� ���� ���θ� ����ϴ� �迭
bool bestset[5] = { 0, };

int w[5] = { 2,5,7,3,1 }; //���ǵ��� ���Ը� ����� �迭
int p[5] = { 20,30,35,12,3 }; //���ǵ��� ��ġ�� ����� �迭

int profit = 0;
int maxprofit = 0;
int totalprofit = 0;
int weight = 0;

int promising(int i,int weight)
{
	int j, bound, totalweight, k;
	if (weight >= W) 	// ������ weight�� �ִ� ���Ը� ���� ��� 0�� ����
		return 0;
	else
	{
		j = i + 1;
		bound = totalprofit;
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

void knapsack(int i, int profit, int weight)
{
	if (weight <= W && profit > maxprofit) //(��ġ��) �̶����� ���� �͵� �� ���� �ְ��� ���̸�
	{
		maxprofit = profit; //profit�� maxprofit�� �����Ͽ� �� ����
		for (int i = 0; i < 5; i++) //���� ���°� �ִ��� ��ġ�� ���� ���� ������ include �迭�� bestset �迭�� ����
			bestset[i] = include[i];
	}
	if (promising(i,weight)) // �����ϴٸ�
	{
		include[i + 1] = true; //w[i+1]�� ������ ���Ѵ�(���Խ�Ŵ)
		totalprofit = profit + p[i + 1];
		knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);

		include[i + 1] = false; //w[i+1]�� ������ ������ �ʴ´�(���� �� ��Ŵ)
		totalprofit = profit;
		knapsack(i + 1, profit, weight);
	}
}
int main()
{

	knapsack(-1, profit, weight); //���� �˰��� ����

	//����ϱ�!
	printf("���� �˰��� by dfs\n\n");
	for (int i = 0; i < 5; i++)
	{
		if (bestset[i] != 0)
		{
			printf("%d��° ���� ���! \n%d��° ������ ���� : %d, ��ġ : %d\n\n", i + 1,i+1,w[i],p[i]);
		}
	}

	printf("�ִ� ��ġ : %d\n", maxprofit);

	return 0;
}