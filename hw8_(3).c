//주석 달기
//HW8-(3)번 문제
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1e9 //i에서 j로 가는 값이 없을때 표현하는 무한대를 이 코드에서는 INF로 표현함

//v1~v7을 a7~a1으로 바꿔야 하므로, W의 배열도 모두 행과 열을 각각 알맞게 뒤집어야 한다.
int W[8][8] = { {0,0,0,0,0,0,0,0},{0,0,INF,INF,8,INF,INF,INF},{0,10,0,INF,INF,INF,INF,INF},{0,INF,INF,0,1,12,INF,INF},{0,5,19,2,0,15,5,INF},{0,INF,INF,INF,INF,0,6,INF},{0,INF,INF,INF,18,INF,0,3},{0,INF,10,INF,INF,INF,4,0} };

int D[8][8]; //가중치 값 저장 배열
int P[8][8]; //경로 저장 배열

void path(int q, int r) //최단거리 경로 구하는 함수
{

	if (P[q][r] != 0)
	{
		path(q, P[q][r]);
		printf("a%d ", P[q][r]); //경로 출력
		path(P[q][r], r);
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

	printf("- 거리(D) 배열 (a1,a2,a3...a7 순서)\n");
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			printf("%d ", D[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("- 직전 경로(P) 배열 (a1,a2,a3...a7 순서)\n");
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			printf("%d ", P[i][j]);
		printf("\n");
	}
	printf("\n\n");


	printf("///a5에서 a2으로 가는 최단 거리 경로 출력///\n");

	printf("a%d ", 5); //a5 출력
	path(5, 2); //a5에서 a2으로 가는 최단거리 경로 구하는 함수
	printf("a%d\n", 2); //a2 출력

	printf("\n");
	printf("정점을 v1 ~ v7로 했을 때와 정점을 a7 ~ a1으로 했을 때의 경로는 표기법만 다를 뿐, 최단거리 경로의 순서는 같다!\n\n");

}