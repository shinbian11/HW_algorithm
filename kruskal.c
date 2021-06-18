//주석 달기
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 14 //MAX는 과제9에 나와있는 그림에 연결되어 있는 간선의 개수
#define VERTEX 8

//간선의 가중치(weight)와 양 끝 정점과 연결 여부를 저장하는 Node라는 구조체를 선언
typedef struct node
{
	int start;
	int end;
	int weight;
	int connect; //connect이 1이면 최소 신장 트리 알고리즘에 의하여 연결된 간선이고, 0이면 연결되지 않은 간선이다.
} Node;

#ifdef MAX
Node n[MAX]; //MAX 라는 매크로 변수가 정의되어 있다면 Node 형의 변수를 MAX개 만큼 만듦.
#endif

#ifdef VERTEX
	// set 배열은 사이클이 발생하는지 여부를 체크하기 위한 사이클 테이블
int set[VERTEX]; //VERTEX 라는 매크로 변수가 정의되어 있다면 int 형의 변수를 VERTEX개 만큼 만듦.
#endif
void initNode();//MAX개의 Node 형의 변수를 초기화.
int cmp(const Node* a, const Node* b); //qsort의 비교함수
int getParent(int set[], int x); //부모 노드를 가져옴
void unionParent(int set[], int a, int b); //부모 노드를 병합
int find(int set[], int a, int b); //부모 노드가 같은지 확인
int main()
{
	initNode();

	qsort(n, MAX, sizeof(Node), cmp); //가중치를 기준으로 오름차순으로 Node 배열을 정렬

	//set 배열 초기화.
	for (int i = 0; i < VERTEX; i++)
		set[i] = i;

	int mindistance = 0; //최소거리의 합을 0으로 초기화
	for (int i = 0; i < MAX; i++) //Node 배열을 index=0부터 끝까지 차례차례!
	{
		if (find(set, n[i].start - 1, n[i].end - 1) == 0) //어떤 간선의 양 끝점 VERTEX들의 부모가 같지 않을 때 => 사이클이 생기지 않을 때
		{
			mindistance += n[i].weight; //최소거리의 합에 값 더해서 넣기
			unionParent(set, n[i].start - 1, n[i].end - 1); //부모 병합
			n[i].connect = 1; //연결되었으니까 1로 바꾸기
		}
	}

	//출력
	printf("****** 크루스칼 알고리즘의 최소 가중치 값들의 합 ******\n%d\n\n", mindistance);
	printf("****** 최소 경로 출력 ******\n");
	for (int i = 0; i < MAX; i++)
	{
		if (n[i].connect == 1)
		{
			printf("경로 : (v%d,v%d), 가중치 : %d\n", n[i].start, n[i].end, n[i].weight);
		}
	}
}

int getParent(int set[], int x) //부모 노드를 가져옴
{
	if (set[x] == x)
		return x;
	else
		return set[x] = getParent(set, set[x]);
}
void unionParent(int set[], int a, int b) //부모 노드를 병합
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a < b)
		set[b] = a;
	else
		set[a] = b;
}
int find(int set[], int a, int b) //부모 노드가 같은지 확인
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b)
		return 1;
	else
		return 0;
}
int cmp(const Node* a, const Node* b) //qsort의 비교 함수 (오름차순)
{
	if (a->weight > b->weight)
		return 1;
	else if (a->weight < b->weight)
		return -1;
	else
		return 0;
}
void initNode() //초기화
{
	n[0].start = 1;
	n[0].end = 2;
	n[0].weight = 11;
	n[0].connect = 0;

	n[1].start = 1;
	n[1].end = 3;
	n[1].weight = 9;
	n[1].connect = 0;

	n[2].start = 1;
	n[2].end = 4;
	n[2].weight = 8;
	n[2].connect = 0;

	n[3].start = 2;
	n[3].end = 3;
	n[3].weight = 3;
	n[3].connect = 0;

	n[4].start = 2;
	n[4].end = 5;
	n[4].weight = 8;
	n[4].connect = 0;

	n[5].start = 2;
	n[5].end = 6;
	n[5].weight = 8;
	n[5].connect = 0;

	n[6].start = 3;
	n[6].end = 4;
	n[6].weight = 15;
	n[6].connect = 0;

	n[7].start = 3;
	n[7].end = 6;
	n[7].weight = 12;
	n[7].connect = 0;

	n[8].start = 3;
	n[8].end = 7;
	n[8].weight = 1;
	n[8].connect = 0;

	n[9].start = 4;
	n[9].end = 7;
	n[9].weight = 10;
	n[9].connect = 0;

	n[10].start = 5;
	n[10].end = 6;
	n[10].weight = 7;
	n[10].connect = 0;

	n[11].start = 5;
	n[11].end = 8;
	n[11].weight = 4;
	n[11].connect = 0;

	n[12].start = 6;
	n[12].end = 8;
	n[12].weight = 5;
	n[12].connect = 0;

	n[13].start = 7;
	n[13].end = 8;
	n[13].weight = 2;
	n[13].connect = 0;

}