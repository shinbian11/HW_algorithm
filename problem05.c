#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* p;
} Node; //��带 �ϳ� ������

Node* arr[13];
bool visited[13] = { false };
int element[8] = { 10,20,30,40,33,46,50,60 };

int main()
{
	for (int i = 0; i < 8; i++)
	{ 
		
		if (visited[element[i] % 13] == false) //���� mod 13�� �ش��ϴ� �ε����� ���� ���� ������ ���� �ʾҴٸ�
		{
			Node* n = (Node*)malloc(sizeof(Node)); //���ο� ��带 �ϳ� ����
			n->data = element[i]; // �װ��� data������ element[i]���� �����ϰ�
			n->p = NULL; //������ �κп��� NULL �� ����
			arr[element[i] % 13] = n;
			visited[element[i] % 13] = true; //��尡 ����� ���� true�� ���� ����
		}
		else //���� mod 13�� �ش��ϴ� �ε����� �̹� � ���(��) ��(��) ����Ǿ� �ִٸ� => �浹 �߻� �� => ���ʿ� ����
		{
			Node* n = (Node*)malloc(sizeof(Node));
			n->data = element[i]; 
			n->p = arr[element[i] % 13]; // ���ο� ����� ������ �κп� ���� arr[element[i] % 13]�� ����Ű�� �ִ� ����� �ּҸ� ����
			arr[element[i] % 13] = n; //�׸��� arr[element[i] % 13]���� ���� ���� ����� �ּҸ� ����
		}

		//print �ϴ� �κ�
		printf("%d �� ����!\n\n", element[i]);

		for (int j = 0; j < 13; j++)
		{
			Node* node = (Node*)malloc(sizeof(Node));
			if (arr[j] == NULL)
				printf("%-3d %4s\n", j, "NULL"); // ���ǻ� ��尡 ���� �Ǿ����� ���� ���� NULL �� ǥ����
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