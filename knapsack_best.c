//주석 달기

//미완성.. 구글링을 통해 c언어로 최대한 우선순위 큐를 구현해보려고 했지만 원하는 결과는 얻지 못했습니다..

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct item {
	int p;
	int w;
	int level; //각 노드의 레벨
} ITEM;

int W = 9; //가방의 무게 제한

int w[5] = { 2,5,7,3,1 }; //물건들의 무게를 기록한 배열
int p[5] = { 20,30,35,12,3 }; //물건들의 가치를 기록한 배열

int profit = 0;
int maxprofit = 0;
int totalprofit = 0;
int weight = 0;
int idx = 0;
//c언어로는 우선순위 queue가 지원되지 않으므로, c언어로 우선순위 큐를 구현

ITEM p_queue[100]; //힙을 구성

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insert(ITEM* p_queue, ITEM p, int idx) //우선순위 큐에 insert 하는 함수
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

ITEM delete(ITEM* p_queue, int idx) //우선순위 큐에서 delete 하는 함수
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

int Isempty(ITEM* p_queue) //우선순위 큐가 비었으면 1를 반환, 아니면 0을 반환
{
	if (idx == 0)
		return 1;
	else
		return 0;
}

int promising(int i, int profit, int weight) { //유망한 노드인지 확인(이 부분은 bfs 와 거의 같다)

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

	insert(p_queue, v, idx);

	while(!Isempty(p_queue))
	{
		v = delete(p_queue, idx);

		if (promising(v.level,v.p,v.w))
		{
			u.level = v.level + 1; //u는 v의 자식 노드이므로 level은 1 증가한다.

			u.p = v.p + p[u.level];
			u.w = v.w + w[u.level];

			if ((u.w <= W) && (u.p > maxprofit)) //자식 노드의 무게가 W보다 작고, 가치가 maxprofit보다 크면
			{
				maxprofit = u.p; //u.p를 maxprofit에 저장하여 값 갱신
			}

			if (promising(u.level, u.p, u.w)) //자식 노드가 유망한 노드라면 
			{
				insert(p_queue, u, idx);
			}

			u.p = v.p;
			u.w = v.w;

			if (promising(u.level, u.p, u.w)) //자식 노드가 유망한 노드라면 
			{
				insert(p_queue, u, idx);
			}
		}

	}
}
int main()
{
	knapsack(profit, weight); //냅색 알고리즘 실행

	//출력하기!
	printf("냅색 알고리즘 by best\n\n");
	printf("최대 가치 : %d\n", maxprofit);

	return 0;
}