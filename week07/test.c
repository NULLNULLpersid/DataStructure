#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}Node;
/*
Node *NodeCreate(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    return n;
}

void TreeCreate(Node**list, int r, int l, int n){
    for (int i = 0; i < n; i++) {
        if (list[i]->data == r) {
            for (int j = 0; i < n; j++) {
                
            }
        }
        else if (list[i]->data == l) {

        }
    }
}

int main(void) {
    int number, right, left;
    scanf("%d", &number);
    Node **list = (Node**)malloc(sizeof(Node) * number);
    for (int i = 0; i < number; i++) list[i] = NodeCreate(i+1);
    for (int i = 0; i < number; i++) printf("ÁÖ¼Ò : %p, °ª : %d\n", list[i], list[i]->data);
    Node *root = list[0];

    for (int i = 0; i < number; i++) {
        scanf("%d %d", &right, &left);
        TreeCreate(list, right, left, number);
    }
    return 0;
}
*/