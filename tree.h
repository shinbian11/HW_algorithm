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

TreeNode* makingNode(char value);   //������ ���� ����!
TreeNode* searchNode(TreeNode* thatNode, char data); //���ϴ� ��带 ã�Ƽ� �� ����� �ּҸ� ��ȯ�ϴ� �Լ�(Ž��)
void treeInOrder(TreeNode* currentNode);    //����Ž�� �Լ�