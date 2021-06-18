#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _TreeNode {
    char value;
    struct _TreeNode* left;
    struct _TreeNode* right;
} TreeNode;

TreeNode* root;
TreeNode* p;

TreeNode* makingNode(char value);   //노드들을 만들어서 연결!
TreeNode* searchNode(TreeNode* thatNode, char data); //원하는 노드를 찾아서 그 노드의 주소를 반환하는 함수(탐색)
void treeInOrder(TreeNode* currentNode);    //중위탐색 함수