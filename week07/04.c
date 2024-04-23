#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, *right;
}TreeNode;

TreeNode *CreateNode(int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
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

void PreorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}
void InorderTraversal(TreeNode* root) {
    if (root != NULL) {
        InorderTraversal(root->left);
        printf("%d ", root->data);
        InorderTraversal(root->right);
    }
}
void PostorderTraversal(TreeNode* root) {
    if (root != NULL) {
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main(void) {
    TreeNode *root = CreateNode(15);
    
    NodeLink(root);

    InorderTraversal(root);
    printf("\n");
    PreorderTraversal(root);
    printf("\n");
    PostorderTraversal(root);

    return 0;
}