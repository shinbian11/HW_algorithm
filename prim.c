//주석 달기
#include<stdio.h>
#include<stdlib.h>

#define INF 1e9
#define MAX 9  //배열의 인덱스를 1부터 쓰기 위해 8이 아니라 9로 했다.
typedef struct node
{
    int start;
    int end;
    int weight;
} Node;

#ifdef MAX
//MAX 라는 매크로 변수가 정의되어 있다면 Node 형의 변수를 MAX-2개 만큼 만듦. 프림 알고리즘에 의해 연결되는 간선은 vertex-1 개니까!
//n은 최소 가중치 경로들만을 저장해 놓고 나중에 출력할 때 사용할 배열
Node n[MAX - 2];
#endif

// G는 모든 정점들 사이의 가중치를 담고 있는 2차원배열
int G[MAX][MAX] = { {0,0,0,0,0,0,0,0,0},{0,0,11,9,8,INF,INF,INF,INF},{0,11,0,3,INF,8,8,INF,INF},{0,9,3,0,15,INF,12,1,INF},{0,8,INF,15,0,INF,INF,10,INF},{0,INF,8,INF,INF,0,7,INF,4},{0,INF,8,12,INF,7,INF,INF,5},{0,INF,INF,1,10,INF,INF,0,2},{0,INF,INF,INF,INF,4,5,2,0} };
int S[MAX][MAX] = { 0, };  //S은 최소 스패닝 트리의 집합으로 들어갈 정점들 사이의 가중치를 담고 있는 2차원 배열

int Prim(); //프림 알고리즘을 작업하는 함수

int main()
{
    int total_distance = Prim(); //프림 function을 통해 나온 최소비용합을 변수에 저장


    //결과 출력
    printf("****** 프림 알고리즘의 최소 가중치 값들의 합 ******\n%d\n\n", total_distance);
    printf("****** 최소 경로 출력 ******\n");
    for (int i = 0; i < MAX - 2; i++)
    {
        printf("경로 : (v%d,v%d), 가중치 : %d\n", n[i].start, n[i].end, n[i].weight);
    }
    return 0;
}

int Prim()
{
    int C[MAX][MAX]; //간선들간의 가중치를 담고있는 매트릭스. G와 비슷
    int V[MAX];
    int D[MAX], F[MAX];

    //정점사이의 비용을 넣을 매트리스와 집합이 되었을때 최소비용을 저장하는 매트릭스를 만듬
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 1; j < MAX; j++)
        {
            if (G[i][j] == 0) // 같은 정점이라는 뜻
                C[i][j] = INF;
            else
                C[i][j] = G[i][j];
        }
    }

    //초기화
    D[1] = 1;
    V[1] = 1;

    for (int i = 2; i < MAX; i++)
    {
        D[i] = C[1][i];
        F[i] = 1;
        V[i] = 0;
    }

    int mindistance = 0;   //최소거리의 합을 0으로 초기화

    int start, end;
    for (int k = 1; k < MAX - 1; k++)
    {
        int min = INF;
        for (int i = 2; i < MAX; i++) //반복
        {
            if (V[i] == 0) //방문을 아직 하지 않은 노드들 중에서 가중치가 최소값일때
            {
                if (min > D[i])
                {
                    min = D[i];
                    end = i;
                }
            }
        }
        start = F[end];

        //스패닝 트리에 방문한 정점(end)을 추가한다.
        S[start][end] = D[end];
        S[end][start] = D[end];

        V[end] = 1; //이젠 end번째 노드도 방문한 노드이다.

        //방문한 노드가 하나 추가되었으니, 거기에 맞게끔, 각 정점들의 최소 가중치 값들을 담고 있는 배열(distance)도 갱신함. 
        for (int i = 2; i < MAX; i++)
        {
            if (V[i] == 0)
            {
                //방금 추가된 end번째 방문노드와의 거리 가중치가 기존에 기록되어 있던 가중치보다 더 작으면, 그 값으로 갱신해준다.
                if (D[i] > C[i][end])
                {
                    D[i] = C[i][end]; //갱신
                    F[i] = end; //end로부터 왔다.
                }
            }
        }
        mindistance += C[start][end];

        //최소 가중치 경로를 n 배열에 저장해놓기 (나중에 최소 가중치 경로 출력 할 때 사용)
        n[k - 1].start = start;
        n[k - 1].end = end;
        n[k - 1].weight = C[start][end];
    }

    return mindistance;
}

