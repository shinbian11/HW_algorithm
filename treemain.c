#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TREE.H"

int main()
{

    int n;
    scanf("%d", &n);
    getchar();  //위에서 n에 해당하는 정수값을 입력한 뒤에 엔터를 쳤는데, 그때의 엔터(개행 문자)를 입력받아 버리는 함수입니다.

    root = makingNode(NULL);
    p;

    for (int i = 0; i < n; i++)
    {
        char parent, leftChild, rightChild;
        scanf("%c %c %c", &parent, &leftChild, &rightChild); //scanf 허용을 위해 sdl 검사 '아니오'로 변경했습니다.
        getchar();  //위와 마찬가지로 rightChild까지 입력하고 난 다음 맨 뒤에 있는 개행 문자를 버립니다.

        p = searchNode(root, parent);

        if (p != NULL)// p가 null이 아닌 경우 > 이미 루트 노드는 연결 끝난 후
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
        else //p가 null인 경우 > 아직 최상위 루트노드도 서브들과의 연결이 안 되었기 때문에, 그 루트노드를 연결합니다.
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

    treeInOrder(root); //중위 순회

    printf("\n");
}