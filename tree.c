#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TREE.H"

TreeNode* makingNode(char data) //입력받은 정보들로 노드를 만들어서 그 노드의 주소를 반환함
{

    TreeNode* n = (TreeNode*)malloc(sizeof(TreeNode));
    n->value = data; //일단 데이터값만 넣어놓고, 
    n->left = NULL;  //왼쪽 오른쪽 연결은 나중에
    n->right = NULL;   //왼쪽 오른쪽 연결은 나중에
    return n;

}

TreeNode* searchNode(TreeNode* thatNode, char data) //루트 노드에서부터 계속 탐색하며, 원하는 노드를 찾았다면 그 노드의 주소를 반환하는 함수(탐색)
{
    if (thatNode != NULL) // thatNode가 null이 아니라면
    {
        if (thatNode->value == data) //thatNode의 value가 우리가 찾고자 하는 parent(data)랑 일치한다면, 거기에 서브 트리를 연결시켜야 하므로 thatNode 반환
            return thatNode;
        else //thatNode의 value가 찾는 data가 아니라면, 
        {
            TreeNode* n = searchNode(thatNode->left, data); //재귀 함수 호출하여 왼쪽 서브 트리로 들어가 탐색한다.
            if (n != NULL)
                return n;
            else
                return searchNode(thatNode->right, data); //아니면 오른쪽 서브 트리로 들어가 탐색한다.
        }
    }
    return NULL; //thatNode 가 null이면 NULL 반환
}

void treeInOrder(TreeNode* currentNode)//중위탐색 함수
{
    //왼쪽 서브트리 > 루트 노드 > 오른쪽 서브트리 순서로 순회합니다.
    if (currentNode == NULL)
        return;
    treeInOrder(currentNode->left);  //왼쪽
    printf("%c", currentNode->value); //루트
    treeInOrder(currentNode->right); //오른쪽
}