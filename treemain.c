#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TREE.H"

int main()
{

    int n;
    scanf("%d", &n);
    getchar();  //������ n�� �ش��ϴ� �������� �Է��� �ڿ� ���͸� �ƴµ�, �׶��� ����(���� ����)�� �Է¹޾� ������ �Լ��Դϴ�.

    root = makingNode(NULL);
    p;

    for (int i = 0; i < n; i++)
    {
        char parent, leftChild, rightChild;
        scanf("%c %c %c", &parent, &leftChild, &rightChild); //scanf ����� ���� sdl �˻� '�ƴϿ�'�� �����߽��ϴ�.
        getchar();  //���� ���������� rightChild���� �Է��ϰ� �� ���� �� �ڿ� �ִ� ���� ���ڸ� �����ϴ�.

        p = searchNode(root, parent);

        if (p != NULL)// p�� null�� �ƴ� ��� > �̹� ��Ʈ ���� ���� ���� ��
        {
            p->value = parent;
            if (leftChild != '.')
            {
                p->left = makingNode(leftChild);
            }
            if (rightChild != '.')
            {
                p->right = makingNode(rightChild);
            }
        }
        else //p�� null�� ��� > ���� �ֻ��� ��Ʈ��嵵 �������� ������ �� �Ǿ��� ������, �� ��Ʈ��带 �����մϴ�.
        {
            root->value = parent;
            if (leftChild != '.')
            {
                root->left = makingNode(leftChild);
            }
            if (rightChild != '.')
            {
                root->right = makingNode(rightChild);
            }
        }
    }

    treeInOrder(root); //���� ��ȸ

    printf("\n");
}