#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* p;
} Node; //노드를 하나 선언함

Node* arr[13];
bool visited[13] = { false };
int element[8] = { 10,20,30,40,33,46,50,60 };

int main()
{
	for (int i = 0; i < 8; i++)
	{ 
		
		if (visited[element[i] % 13] == false) //원소 mod 13에 해당하는 인덱스에 아직 값이 저장이 되지 않았다면
		{
			Node* n = (Node*)malloc(sizeof(Node)); //새로운 노드를 하나 만들어서
			n->data = element[i]; // 그곳의 data영역에 element[i]값을 저장하고
			n->p = NULL; //포인터 부분에는 NULL 을 저장
			arr[element[i] % 13] = n;
			visited[element[i] % 13] = true; //노드가 저장된 곳은 true로 값을 변경
		}
		else //원소 mod 13에 해당하는 인덱스에 이미 어떤 노드(들) 가(이) 저장되어 있다면 => 충돌 발생 시 => 앞쪽에 삽입
		{
			Node* n = (Node*)malloc(sizeof(Node));
			n->data = element[i]; 
			n->p = arr[element[i] % 13]; // 새로운 노드의 포인터 부분에 원래 arr[element[i] % 13]이 가르키고 있던 노드의 주소를 대입
			arr[element[i] % 13] = n; //그리고 arr[element[i] % 13]에는 새로 만든 노드의 주소를 대입
		}

		//print 하는 부분
		printf("%d 값 삽입!\n\n", element[i]);

		for (int j = 0; j < 13; j++)
		{
			Node* node = (Node*)malloc(sizeof(Node));
			if (arr[j] == NULL)
				printf("%-3d %4s\n", j, "NULL"); // 편의상 노드가 연결 되어있지 않은 곳은 NULL 로 표기함
			else
			{
				printf("%-3d ", j);
				node->p = arr[j];
				while (node->p != NULL)
				{
					printf("%d  ", node->p->data);
					node->p = node->p->p;
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	

}