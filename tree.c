#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TREE.H"

TreeNode* makingNode(char data) //�Է¹��� ������� ��带 ���� �� ����� �ּҸ� ��ȯ��
{

    TreeNode* n = (TreeNode*)malloc(sizeof(TreeNode));
    n->value = data; //�ϴ� �����Ͱ��� �־����, 
    n->left = NULL;  //���� ������ ������ ���߿�
    n->right = NULL;   //���� ������ ������ ���߿�
    return n;

}

TreeNode* searchNode(TreeNode* thatNode, char data) //��Ʈ ��忡������ ��� Ž���ϸ�, ���ϴ� ��带 ã�Ҵٸ� �� ����� �ּҸ� ��ȯ�ϴ� �Լ�(Ž��)
{
    if (thatNode != NULL) // thatNode�� null�� �ƴ϶��
    {
        if (thatNode->value == data) //thatNode�� value�� �츮�� ã���� �ϴ� parent(data)�� ��ġ�Ѵٸ�, �ű⿡ ���� Ʈ���� ������Ѿ� �ϹǷ� thatNode ��ȯ
            return thatNode;
        else //thatNode�� value�� ã�� data�� �ƴ϶��, 
        {
            TreeNode* n = searchNode(thatNode->left, data); //��� �Լ� ȣ���Ͽ� ���� ���� Ʈ���� �� Ž���Ѵ�.
            if (n != NULL)
                return n;
            else
                return searchNode(thatNode->right, data); //�ƴϸ� ������ ���� Ʈ���� �� Ž���Ѵ�.
        }
    }
    return NULL; //thatNode �� null�̸� NULL ��ȯ
}

void treeInOrder(TreeNode* currentNode)//����Ž�� �Լ�
{
    //���� ����Ʈ�� > ��Ʈ ��� > ������ ����Ʈ�� ������ ��ȸ�մϴ�.
    if (currentNode == NULL)
        return;
    treeInOrder(currentNode->left);  //����
    printf("%c", currentNode->value); //��Ʈ
    treeInOrder(currentNode->right); //������
}