
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5 //행렬의 가로, 세로 크기

int W[N + 1][N + 1] = { {0,0,0,0,0,0}, {0,0,8,13,18,20}, {0,3,0,7,8,10}, {0,4,11,0,10,7}, {0,6,6,7,0,11}, {0,10,6,2,1,0} }; //행렬 초기화
//A의 최대 수가 15이기 때문에 배열 D,P의 열의 개수는 널널하게 20개 정도 만들어놓기
int D[N + 1][20]; //dp(가중치 값) 저장 배열. 가령 D[3][12]의 뜻은 v3에서 v1로 가는데에 v4와 v5를 거쳐서 가야 하는 회로들의 최소값을 저장하고 있다.
int P[N + 1][20]; //경로 저장 배열. 최적의 회로를 찾았을 때 경로를 출력 하기 위해 이용한다.

int size;

void travel(int n);
int diff(int A, int j); //배열 A에서 특정 vertex만 제외하는 함수
int isInside(int A, int x); // 배열 A에서 x번째 vertex가 포함되어 있는지 판단하는 함수
int contains(int A, int k); //A 집합 안에 있는 vertex의 개수를 조회하는 함수. A 안에 있는 vertex의 개수가 k개면 1을 반환, 아니면 0을 반환
int getMin(int i, int A); // 최소 경로 찾는 함수
void printArray(); //배열 D와 P를 출력하는 함수(참고용)
void printShortestCircuit(int i, int A); //최적 회로의 경로 출력

int main()
{
	travel(N);

	printArray(); //배열 D와 P를 출력하는 함수(참고용)

	printf("v1에서 시작하여 v1로 돌아오는 최적 회로 : ");
	printf("v1 ");
	printShortestCircuit(1, 15); //최적 회로 경로 출력

	printf("최적 회로의 min 값은 %d이다.\n", D[1][size - 1]); //D[1][15]의 값 출력

	return 0;
}

void travel(int n)
{
	size = (int)pow(2, (double)n - 1);

	for (int i = 1; i <= n; i++)
	{
		D[i][0] = W[i][1]; //i번째 vertex에서 아무것도 거치지 않고 1로 가는 경우(D[i][0])는 i번째 vertex에서 1로 한번에 가는 경로(W[i][1])와 같다.
	}

	for (int i = 1; i <= n; i++) //i번째 vertex에서 아무것도 거치지 않고 1로 가는 경우(D[i][0])는 1을 저장한다. 항상 도착지가 v1이니까.
	{
		P[i][0] = 1;
	}

	for (int k = 1; k <= n - 2; k++)
	{
		for (int A = 1; A < size; A++)
		{
			if (contains(A, k) == 0) continue; //집합 A 안에 k개의 vertex가 있어야 한다.
			for (int i = 2; i <= n; i++)
			{

				if (isInside(A, i) == 1) continue; //i가 1이 아니며, i번째 vertex가 A에 있으면 안됨

				D[i][A] = getMin(i, A);
			}
		}
	}

	//위 3중첩 for 문에서 i=1일 때 처리를 해주지 않았으므로, i=1일 때 처리 해주기!
	for (int A = 1; A < size; A++)
	{
		D[1][A] = getMin(1, A);
	}

}

int diff(int A, int j) //배열 A에서 특정 vertex만 제외하는 함수
{
	return A & ~(1 << (j - 2));
}

int isInside(int A, int x) // 배열 A에서 x번째 vertex가 포함되어 있는지 판단하는 함수
{
	if (((A & (1 << x - 2)) != 0)) //x번쩨 vertex가 A 안에 있다.
		return 1;
	else //x번째 vertex가 A 안에 없다.
		return 0;
}

int contains(int A, int k) //A 집합 안에 있는 vertex의 개수를 조회하는 함수. A 안에 있는 vertex의 개수가 k개면 1을 반환, 아니면 0을 반환
{
	int cnt = 0;
	for (int i = 0; i <= N - 2; i++)
	{
		if ((A & (1 << i)) != 0) cnt++;
	}
	if (cnt != k)
		return 0;
	else
		return 1;
}

int getMin(int i, int A) // 최소 경로 찾는 함수
{

	int m;
	int min = 1e9;
	int minJ = 1e9;
	for (int j = 2; j < size; j++)
	{
		if (isInside(A, j) == 0) continue; //집합 A 안에 j번째 vertex가 있어야 밑의 코드를 진행할 수 있다.

		//(i번째 vertex -> j번째 vertex) + (j번째 vertex에서 v1로 갈 때, j번째 vertex를 제외한 나머지 집합 A의 vertex들을 모두 거쳐서 지나가야 한다)
		m = W[i][j] + D[j][diff(A, j)];

		if (min > m) //만약 이 m이 최소값이면 min을 m으로 초기화한다.
		{
			min = m;
			minJ = j; // 그 때의 j값을 minJ에 저장해놓고,
		}

	}
	P[i][A] = minJ; // 최종적인 minJ값을 P배열에 저장한다.
	return min;
}

void printArray() //배열 D와 P를 출력하는 함수
{
	printf("배열 D의 값입니다.\n\n"); //D 출력
	for (int i = 0; i < N + 1; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%3d", D[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	printf("배열 P의 값입니다.\n\n"); //P 출력
	for (int i = 0; i < N + 1; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%2d", P[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");
}
void printShortestCircuit(int i, int A) //최적 회로의 경로 출력
{
	printf("v%d ", P[i][A]);

	if (A == 0)
	{
		printf("\n");
		return;
	}
	printShortestCircuit(P[i][A], diff(A, P[i][A])); //재귀함수 이용하여 출력
}