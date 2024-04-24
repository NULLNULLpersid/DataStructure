#include <stdio.h>
#include <stdlib.h>

//구조체 선언 함수
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

//노드 생성 및 초기화 함수
TreeNode *CreateNode() {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = 1;
    node->left = node->right = NULL;
    return node;
}

//노드의 주소가 들어있는 동적배열 생성 함수
TreeNode ***CreateNodeList(int num) {
    TreeNode ***nodelist = (TreeNode***)malloc(sizeof(TreeNode) * num * num);
    for (int i = 0; i < num; i++) for (int j = 0; j < num; j++) nodelist[i][j] = CreateNode();
    return nodelist;
}



void DataChange(TreeNode ***nodelist, int num, int change) {
    for (int row = 0; row < num; row++) {
        for (int col = 0; col < num; col++) {
            if (nodelist[change][col]->data == 1) nodelist[change][col]->data = 0;
            if (nodelist[row][change]->data == 1) nodelist[row][change]->data = 0;
            if (change+row == col) nodelist[row][col]->data = 0;
        }
    }
}

void FindPossibleOutcomes(TreeNode*** nodelists, int num) {
    for (int change = 0; change < num; change++) {
        DataChange(nodelists, num, change);
    }
}
void print(TreeNode ***nodelist, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            printf("%d ", nodelist[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    int num;
    scanf("%d", &num);
    TreeNode ***nodelist = CreateNodeList(num);
    FindPossibleOutcomes(nodelist, num);

    print(nodelist, num);
    return 0;
}