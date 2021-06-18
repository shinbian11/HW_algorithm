//주석 달기
//HW8-(1)번 문제 (O(n^4) 의 시간복잡도)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1e9 //i에서 j로 가는 값이 없을때 표현하는 무한대를 이 코드에서는 INF로 표현함

int W[8][8] = { {0,0,0,0,0,0,0,0}, {0,0,4,INF,INF,INF,10,INF},{0,3,0,INF,18,INF,INF,INF},{0,INF,6,0,INF,INF,INF,INF},{0,INF,5,15,0,2,19,5},{0,INF,INF,12,1,0,INF,INF}, {0,INF,INF,INF,INF,INF,0,10},{0,INF,INF,INF,8,INF,INF,0} };
int D[8][8]; //가중치 값 저장 배열
int P[8][8]; //경로 저장 배열

int main()
{
	int n = 8; //index를 1 ~ 7 로 사용하기 위해 n을 7이 아닌 8로 저장

	// D,P 배열 초기화
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			D[i][j] = W[i][j]; //초기 D배열은 W 배열과 같은 값으로!
		}
	}


	for (int m = 2; m < n; m++) //m == 1 일때는 D[i][j] = W[i][j]이다. 위에서 처리함.
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				int min = INF;
				//min(D[i][k] + W[k][j])을 D[i][j]에 넣는 과정
				for (int k = 1; k < n; k++)
				{
					if (min > D[i][k] + W[k][j]) //최솟값 구하기
					{
						min = D[i][k] + W[k][j];
					}
				}
				D[i][j] = min;
			}
		}
	}

	//모든 정점에서 다른 모든 정점으로 가는 최단경로(각 도시들마다 하나하나씩 일일히)를 구한 이후!

	printf("///////O(n^4) 알고리즘 수행 완료 후 테이블!///////\n\n");

	printf("- 거리(D) 배열\n");
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
}