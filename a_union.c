//(a) 번의 집합을 합치는 코드입니다.
//과제에서는 원소를 알파벳으로 표기했지만, 편의상 코드에서는 숫자로 표기했습니다 (ex. a=1, b=2 ... z=26)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int p[4];
int rank[4];

int find(int x) //x의 부모 노드를 재귀적으로 갱신하며 값을 찾음
{
	if (p[x] == x)
		return x;
	else
	{
		return p[x] = find(p[x]); //경로 단축도 한번에 할수 있게끔 최적화
	}
}

void union_(int x, int y) //합침
{
	x = find(x); //x의 루트 노드 찾기
	y = find(y); //y의 루트 노드 찾기
	if (x == y)
		return;
	if (rank[x] < rank[y]) //y가 속해있는 트리의 루트 노드의 랭크가 더 크다면 (y가 속해있는 트리가 더 크다면)
		p[x] = y; 
	else //아니면
		p[y] = x;
	if (rank[x] == rank[y])
		rank[x]++;
}

int findParent(int a, int b) //부모가 같은지 다른지 판단함으로써 같은 집합에 속해있는지 아닌지를 알 수 있음
{
	a = find(a);// a의 부모 노드 찾기
	b = find(b); // b의 부모 노드 찾기
	if (a == b) return 1; // 같은 부모를 가지면 1을 리턴
	else return 0; // 아니면 0 리턴
}

int main()
{
	for (int i = 1; i <= 3; i++)
	{
		p[i] = i;
		rank[i] = 0;
	}

	union_(1, 2); //1 <- 2 형태의 집합 만들기
	union_(1, 3); //1 <- 2 형태의 집합과 3 형태의 집합을 합치기

	//집합이 union 되었는지 확인해보기 (임의로 두개의 원소를 입력하여 같은 집합에 포함되어있는지 여부를 가림으로써 확인가능하다)
	while (true)
	{
		for (int i = 1; i <= 3; i++)
		{
			printf("%d ", i);
		}
		printf("중에서 같은 집합에 있는지 궁금한 원소 두 개를 입력해보세요 (종료는 0 0 입력)> ");

		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			return 0;
		findParent(a, b) ? printf("%d 와 %d 는 같은 집합에 속해있습니다.\n\n", a, b) : printf("%d 와 %d 는 같은 집합에 속해있지 않습니다.\n", a, b);
	}
	
} 