//주석 달기
//HW8-(2)번 문제 (O(n^3) 의 시간복잡도)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1e9 //i에서 j로 가는 값이 없을때 표현하는 무한대를 이 코드에서는 INF로 표현함

int W[8][8] = { {0,0,0,0,0,0,0,0}, {0,0,4,INF,INF,INF,10,INF},{0,3,0,INF,18,INF,INF,INF},{0,INF,6,0,INF,INF,INF,INF},{0,INF,5,15,0,2,19,5},{0,INF,INF,12,1,0,INF,INF}, {0,INF,INF,INF,INF,INF,0,10},{0,INF,INF,INF,8,INF,INF,0} };
int D[8][8]; //가중치 값 저장 배열
int P[8][8]; //경로 저장 배열

void path(int q, int r) //최단거리 경로 구하는 함수
{

	if (P[q][r] != 0)
	{
		path(q, P[q][r]);
		printf("v%d ", P[q][r]); //경로 출력
		path(P[q][r], r); //중간 경로인 (P[q][r])에서 r로 갈 때의 경로 구하는 함수
	}
}
int main()
{
	int n = 8; //index를 1 ~ 7 로 사용하기 위해 n을 7이 아닌 8로 저장

	// D,P 배열 초기화
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			D[i][j] = W[i][j]; //초기 D배열은 W 배열과 같은 값으로
			P[i][j] = 0; //P배열도 일단 0으로 초기화
		}
	}

	//플로이드 와샬 알고리즘 사용
	for (int k = 1; k < n; k++)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (D[i][j] > D[i][k] + D[k][j]) //i에서 j로 갈때, 한번에 가는 것보다 거쳐서 가는 것이 더 optimal하다면
				{
					D[i][j] = D[i][k] + D[k][j]; //D[i][j]를 optimal한 경로의 값으로 바꾸고
					P[i][j] = k; //그때의 중간 경로를 k로 저장
				}
			}
		}
	}

	//플로이드 와샬 알고리즘을 사용한 이후(배열 D,P 출력, a5에서 a2으로 가는 최단 경로 출력)

	printf("///////플로이드 와샬 알고리즘 완료 후 테이블!///////\n\n");

	printf("- 거리(D) 배열\n");
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			printf("%d ", D[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("- 직전 경로(P) 배열\n");
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			printf("%d ", P[i][j]);
		printf("\n");
	}
	printf("\n\n");


	printf("///v3에서 v6으로 가는 최단 거리 경로 출력///\n");

	printf("v%d ", 3); //v3 출력
	path(3, 6); //v3에서 v6으로 가는 최단거리 경로 구하는 함수
	printf("v%d\n", 6); //v6 출력	
}