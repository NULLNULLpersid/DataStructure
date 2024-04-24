#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, *right;
}TreeNode;

int DATA[2] = {0, 0};

TreeNode *CreateNode(int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void print(TreeNode*root, int deep, int b) {
    if (root != NULL) {
        printf("%d ", root->data);
    }
}

void NodeLink(TreeNode* root) {
    TreeNode *node1 = CreateNode(4);
    TreeNode *node2 = CreateNode(20);
    TreeNode *node3 = CreateNode(1);
    TreeNode *node4 = CreateNode(16);
    TreeNode *node5 = CreateNode(25);
    root->left = node1;
    root->right = node2;
    root->left->left = node3;
    root->right->left = node4;
    root->right->right = node5;
}

int main(void) {
    TreeNode *root = CreateNode(15);
    
    NodeLink(root);

    print(root, 0, 0);

    return 0;
}
