//주석 달기
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int W = 9; //가방의 무게 제한

bool include[5] = { 0, }; //물건들의 포함 여부를 기록하는 배열
bool bestset[5] = { 0, };

int w[5] = { 2,5,7,3,1 }; //물건들의 무게를 기록한 배열
int p[5] = { 20,30,35,12,3 }; //물건들의 가치를 기록한 배열

int profit = 0;
int maxprofit = 0;
int totalprofit = 0;
int weight = 0;

int promising(int i,int weight)
{
	int j, bound, totalweight, k;
	if (weight >= W) 	// 현재의 weight가 최대 무게를 넘은 경우 0을 리턴
		return 0;
	else
	{
		j = i + 1;
		bound = totalprofit;
		totalweight = weight;
		while ((j < 5) && (totalweight + w[j] <= W)) //W보다 무게가 커서 가방이 터지기 직전까지(무게가 허락해주는 곳까지 더하기)
		{
			totalweight += w[j];
			bound += p[j];
			j++;
		}
		k = j;
		if (k < 5)
		{
			bound += (W - totalweight) * p[k] / w[k]; //한계치를 구하는 작업 (나머지 부분을 가루로 채우는 개념을 사용해서, 한계치를 정한다)
		}
		return bound > maxprofit; 
		//그 경계값이 maxprofit보다 작다면, 앞으로 아무리 노력해봤자 최적의 값이 나올 확률이 없는 노드이므로, 0을 반환하여 그 노드에서의 탐색은 종료한다.
	}
}

void knapsack(int i, int profit, int weight)
{
	if (weight <= W && profit > maxprofit) //(가치가) 이때까지 구한 것들 중 가장 최고의 값이면
	{
		maxprofit = profit; //profit을 maxprofit에 복사하여 값 갱신
		for (int i = 0; i < 5; i++) //현재 상태가 최대의 가치를 가질 때의 현재의 include 배열을 bestset 배열에 복사
			bestset[i] = include[i];
	}
	if (promising(i,weight)) // 유망하다면
	{
		include[i + 1] = true; //w[i+1]의 물건을 더한다(포함시킴)
		totalprofit = profit + p[i + 1];
		knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);

		include[i + 1] = false; //w[i+1]의 물건을 더하지 않는다(포함 안 시킴)
		totalprofit = profit;
		knapsack(i + 1, profit, weight);
	}
}
int main()
{

	knapsack(-1, profit, weight); //냅색 알고리즘 실행

	//출력하기!
	printf("냅색 알고리즘 by dfs\n\n");
	for (int i = 0; i < 5; i++)
	{
		if (bestset[i] != 0)
		{
			printf("%d번째 물건 사용! \n%d번째 물건의 무게 : %d, 가치 : %d\n\n", i + 1,i+1,w[i],p[i]);
		}
	}

	printf("최대 가치 : %d\n", maxprofit);

	return 0;
}