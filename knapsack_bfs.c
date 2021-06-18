//주석 달기
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct item {
	int p;
	int w;
	int level;
} ITEM;

int W = 9; //가방의 무게 제한

int w[5] = { 2,5,7,3,1 }; //물건들의 무게를 기록한 배열
int p[5] = { 20,30,35,12,3 }; //물건들의 가치를 기록한 배열

int profit = 0;
int maxprofit = 0;
int totalprofit = 0;
int weight = 0;

//c언어로는 queue가 지원되지 않으므로, c언어로 큐를 간단히 구현
ITEM queue[100];
int head = 0, tail = 0;

void enqueue(ITEM* queue, ITEM i) //큐에 enqueue 하는 함수
{
	queue[head++] = i; //그냥 enqueue하고 head 인덱스만 증가
}
ITEM dequeue(ITEM* queue) //큐에서 dequeue 하는 함수
{
	return queue[tail++]; //ITEM 자료형의 노드를 반환. dequeue 하고 tail 인덱스 증가
}
int queue_empty(ITEM* queue) //큐가 비었으면 1를 반환, 아니면 0을 반환
{
	//head와 tail의 처음 초기화 할 때 시작점이 0인데, 큐가 비었는지 확인하는 상황은 초기화 상황에서는 확인하면 안되기 때문에 tail != 0이라는 조건도 넣어줌
	return (tail != 0 && head == tail);
}


int promising(int i, int profit, int weight) { //유망한 노드인지 확인

	int j, k;
	int totalweight;
	int bound;

	if (weight >= W) 	// 현재의 weight가 최대 무게를 넘은 경우 0을 리턴
		return 0;
	else {
		j = i + 1;
		bound = profit;
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
void knapsack(int profit, int weight)
{
	ITEM u, v;

	//초기화
	maxprofit = 0;
	v.level = -1;
	v.p = 0; 
	v.w = 0;

	enqueue(queue,v);
	while (!queue_empty(queue)) //큐가 비어있지 않다면
	{
		v = dequeue(queue); //맨 앞의 ITEM을 dequeue한다.

		u.level = v.level + 1; //u는 v의 자식 노드이므로 level은 1 증가한다.

		u.p = v.p + p[u.level];
		u.w = v.w + w[u.level];

		if ((u.w <= W) && (u.p > maxprofit)) //자식 노드의 무게가 W보다 작고, 가치가 maxprofit보다 크면
		{
			maxprofit = u.p; //u.p를 maxprofit에 저장하여 값 갱신
		}

		if (promising(u.level, u.p, u.w)) //자식 노드가 유망한 노드라면 
			enqueue(queue, u); //큐에 넣는다.

		u.p = v.p;
		u.w = v.w;

		if (promising(u.level, u.p, u.w)) //자식 노드가 유망한 노드라면 
			enqueue(queue, u); //큐에 넣는다.
	}
}
int main()
{
	knapsack(profit, weight); //냅색 알고리즘 실행
	
	//출력하기!
	printf("냅색 알고리즘 by bfs\n\n");
	printf("최대 가치 : %d\n", maxprofit);

	return 0;
}