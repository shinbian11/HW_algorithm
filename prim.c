//�ּ� �ޱ�
#include<stdio.h>
#include<stdlib.h>

#define INF 1e9
#define MAX 9  //�迭�� �ε����� 1���� ���� ���� 8�� �ƴ϶� 9�� �ߴ�.
typedef struct node
{
    int start;
    int end;
    int weight;
} Node;

#ifdef MAX
//MAX ��� ��ũ�� ������ ���ǵǾ� �ִٸ� Node ���� ������ MAX-2�� ��ŭ ����. ���� �˰��� ���� ����Ǵ� ������ vertex-1 ���ϱ�!
//n�� �ּ� ����ġ ��ε鸸�� ������ ���� ���߿� ����� �� ����� �迭
Node n[MAX - 2];
#endif

// G�� ��� ������ ������ ����ġ�� ��� �ִ� 2�����迭
int G[MAX][MAX] = { {0,0,0,0,0,0,0,0,0},{0,0,11,9,8,INF,INF,INF,INF},{0,11,0,3,INF,8,8,INF,INF},{0,9,3,0,15,INF,12,1,INF},{0,8,INF,15,0,INF,INF,10,INF},{0,INF,8,INF,INF,0,7,INF,4},{0,INF,8,12,INF,7,INF,INF,5},{0,INF,INF,1,10,INF,INF,0,2},{0,INF,INF,INF,INF,4,5,2,0} };
int S[MAX][MAX] = { 0, };  //S�� �ּ� ���д� Ʈ���� �������� �� ������ ������ ����ġ�� ��� �ִ� 2���� �迭

int Prim(); //���� �˰����� �۾��ϴ� �Լ�

int main()
{
    int total_distance = Prim(); //���� function�� ���� ���� �ּҺ������ ������ ����


    //��� ���
    printf("****** ���� �˰����� �ּ� ����ġ ������ �� ******\n%d\n\n", total_distance);
    printf("****** �ּ� ��� ��� ******\n");
    for (int i = 0; i < MAX - 2; i++)
    {
        printf("��� : (v%d,v%d), ����ġ : %d\n", n[i].start, n[i].end, n[i].weight);
    }
    return 0;
}

int Prim()
{
    int C[MAX][MAX]; //�����鰣�� ����ġ�� ����ִ� ��Ʈ����. G�� ���
    int V[MAX];
    int D[MAX], F[MAX];

    //���������� ����� ���� ��Ʈ������ ������ �Ǿ����� �ּҺ���� �����ϴ� ��Ʈ������ ����
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 1; j < MAX; j++)
        {
            if (G[i][j] == 0) // ���� �����̶�� ��
                C[i][j] = INF;
            else
                C[i][j] = G[i][j];
        }
    }

    //�ʱ�ȭ
    D[1] = 1;
    V[1] = 1;

    for (int i = 2; i < MAX; i++)
    {
        D[i] = C[1][i];
        F[i] = 1;
        V[i] = 0;
    }

    int mindistance = 0;   //�ּҰŸ��� ���� 0���� �ʱ�ȭ

    int start, end;
    for (int k = 1; k < MAX - 1; k++)
    {
        int min = INF;
        for (int i = 2; i < MAX; i++) //�ݺ�
        {
            if (V[i] == 0) //�湮�� ���� ���� ���� ���� �߿��� ����ġ�� �ּҰ��϶�
            {
                if (min > D[i])
                {
                    min = D[i];
                    end = i;
                }
            }
        }
        start = F[end];

        //���д� Ʈ���� �湮�� ����(end)�� �߰��Ѵ�.
        S[start][end] = D[end];
        S[end][start] = D[end];

        V[end] = 1; //���� end��° ��嵵 �湮�� ����̴�.

        //�湮�� ��尡 �ϳ� �߰��Ǿ�����, �ű⿡ �°Բ�, �� �������� �ּ� ����ġ ������ ��� �ִ� �迭(distance)�� ������. 
        for (int i = 2; i < MAX; i++)
        {
            if (V[i] == 0)
            {
                //��� �߰��� end��° �湮������ �Ÿ� ����ġ�� ������ ��ϵǾ� �ִ� ����ġ���� �� ������, �� ������ �������ش�.
                if (D[i] > C[i][end])
                {
                    D[i] = C[i][end]; //����
                    F[i] = end; //end�κ��� �Դ�.
                }
            }
        }
        mindistance += C[start][end];

        //�ּ� ����ġ ��θ� n �迭�� �����س��� (���߿� �ּ� ����ġ ��� ��� �� �� ���)
        n[k - 1].start = start;
        n[k - 1].end = end;
        n[k - 1].weight = C[start][end];
    }

    return mindistance;
}

