//주석 달기 + 보고서
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[6] = { 2,10,13, 17,22,42, }; //수열
int track[6] = { 0, }; //해에 해당하는 원소들을 저장하는 배열
int W = 52; //우리가 찾는 값(부분 수열을 더해서 W값이 나오는 수열들의 조합을 구해야한다)

int promising(int i, int sum, int total)
{
    //i번째 원소에서 유망한지를 판단하는 여부
    //조건 1 : i번째까지 더한 합(sum)이 W와 일치하거나, i번째까지 더한 합(sum)에 그 다음 원소인 i+1번째 원소를 더했을때 W를 넘어가지 않을 때
    //조건 2 : i번째까지 더한 합 + 나머지 남은 원소들의 합 이 W보다 작지 않을 때 
    //조건 1,2를 모두 만족해야 유망한 것이므로 1을 반환!
    if (((sum == W) || sum + arr[i + 1] <= W) && (sum + total >= W))
        return 1;
    //조건 1을 만족하지 않는 경우 : ex) i번째까지 더한 합(sum)에 그 다음 원소인 i+1번째 원소를 더했을때 W를 넘어 갈 때
    //(비내림차순으로 정렬했으므로 탐색을 하면 할수록 더 큰 수가 나온다. 그러므로 이미 한번 W를 넘어갔다면 그것은 가지치기를 해야 하는 대상이다.)
    //조건 2를 만족하지 않는 경우 : i번째까지 더한 합 + 나머지 남은 원소들의 합 이 W보다 작을 때
    //(sum + total이 W보다 작다면, 어짜피 계속 해봤자 W에 도달할 수 없기 때문에 그것은 가지치기를 해야 하는 대상이다.)
    //조건 1이나 2 중에서 하나라도 만족하지 않는다면 유망하지 않은 것이므로 0을 반환
    else
        return 0;
}

void printAll() //조합 출력
{
    printf("(");
    for (int i = 0; i < 6; i++)
    {
        if (track[i] != 0) //0이 아닌 원소들을 모두 출력하면, 그 원소들의 합이 곧 우리가 찾는 W값과 같으므로, 조건에 합당하다.
        {
            printf(" %d ", track[i]);
        }
    }
    printf(")");
    printf("\n");
}
void dfs(int i, int sum, int total)
{

    if (promising(i, sum, total) == 1) //i번째 원소가 유망한 원소라면
    {
        if (sum == W) //이때까지 더한 합계가 우리가 찾는 그 값과 동일하다면
        {
            printAll(); //그 조합들을 인쇄해라!
        }
        else //이때까지 더한 합계가 우리가 찾는 그 값과 아직 동일하지 않다면
        {
            //case 1 : i+1번째 원소를 더하는 경우
            track[i + 1] = arr[i + 1];
            dfs(i + 1, sum + arr[i + 1], total - arr[i + 1]);

            //case 2 : i+1번째 원소를 안 더하는 경우
            track[i + 1] = 0;
            dfs(i + 1, sum, total - arr[i + 1]);
        }
    }

}

int main() {

    int total = 0;

    for (int i = 0; i < 6; i++) //일단 배열의 모든 원소의 합(total)을 구한다.
        total += arr[i];

    dfs(-1, 0, total);

    return 0;
}