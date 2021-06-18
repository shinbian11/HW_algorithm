//�ּ� �ޱ� + ����
//monte carlo(�̿ϼ�)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int arr[6] = { 2,10,13, 17,22,42, };
int track[6] = { 0, };
int mon[20] = { 0, };
int W = 52; //�츮�� ã�� ��(�κ� ������ ���ؼ� W���� ������ �������� ������ ���ؾ��Ѵ�)
int cnt = 0;
int total = 0;

int promising(int i, int sum, int total)
{
    for (int l = 0; l < i; l++)
    {
        if (((sum == W) || sum + arr[l + 1] <= W) && (sum + total >= W))
            return 1;
        else
            return 0;
    }
}

int dfs(int i, int sum, int total) {

    int n = 6;
    int mprod = 1, numnodes = 1, m = 1;
    int prom_children[7] = { 0, };
    int index = 0, flag = 0;
    while (m != 0 && i != n)
    {
        mprod = mprod * m;
        numnodes += mprod * n;
        i++;
        m = 0;
        for (int j = 0; j < n; j++)
        {
            track[i] = j;
            if (promising(j, sum, total))
            {
                m++;
                for (int k = 0; k < n; k++)
                {
                    if (prom_children[k] == 0)
                    {
                        prom_children[k] = j;
                        break;
                    }
                }
            }
        }

        if (m != 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (prom_children[j] != 0)
                    index++;
            }

            srand((unsigned)time(NULL));
            flag = (rand() % index);
            int j = prom_children[flag];
            track[i] = j;
            index = 0;
        }
    }
    return numnodes;
}

int main() {

    int anstotal = 0;
    for (int i = 0; i < 6; i++)
        total += arr[i];


    for (int i = 0; i < 20; i++) //20�� �ݺ�
    {
        printf("%d : %d\n", i + 1, mon[i] = dfs(-1, 0, total));
        anstotal += mon[i];
    }
    printf("��� Ƚ�� : %d\n", anstotal / 20);
    return 0;

}