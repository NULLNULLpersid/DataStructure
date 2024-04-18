/*
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right, *node;
}TreeNode;

TreeNode *NodeCreate(TreeNode *n, int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    if (n =- NULL) {
        node->node = NULL;
    }
    else {
        node->node = n;
    }
    return node;
}

TreeNode* NodeLink(TreeNode *n, int r, int l){
    if (n->data == r) {
        TreeNode *node = NodeCreate(n, l);
        n->left = node;
        return node;
    }
    else if (n->data == l) {
        TreeNode *node = NodeCreate(n, r);
        n->right = node;
        return node;
    }
    else return NULL;
}


int main(void) {
    int number, right, left;
    TreeNode *root = NULL;
    root = NodeCreate(root, 1);
    TreeNode *rightnode = root, *leftnode = root;

    scanf("%d", &number);

    for (int i = 1; i < number; i++) {
        scanf("%d %d", &right, &left);
        if (rightnode->data == right) {
            rightnode = NodeLink(rightnode, right, left);
        }
        else if (leftnode->data == left) {
            leftnode = NodeLink(leftnode, right, left);
        }
    }
    printf("%d > %d", root->data, root->node->data);
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right, *node;
} TreeNode;

TreeNode *NodeCreate(TreeNode *n, int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = node->node = NULL;
    if (n != NULL) {
        node->node = n;
    }
    return node;
}

TreeNode* NodeLink(TreeNode *n, int r, int l){
    if (n->data == r) {
        TreeNode *node = NodeCreate(n, l);
        n->right = node;
        return node;
    }
    else if (n->data == l) {
        TreeNode *node = NodeCreate(n, r);
        n->left = node;
        return node;
    }
    else {
            return NodeLink(n->node, r, l);
    }
}

void TreeNodeCreate(TreeNode *r, int num) {
    int left, right;
    TreeNode *rightnode = r, *leftnode = r;
    for (int i = 1; i < num; i++) {
        scanf("%d %d", &left, &right);
        if (rightnode->data == left) {
            rightnode = NodeLink(rightnode, left, right);
        }
        else if (leftnode->data == right) {
            leftnode = NodeLink(leftnode, left, right);
        }
        else {
            if (rightnode->node->data == left) {
                rightnode = NodeLink(rightnode->node, left, right);
            }
            else if (leftnode->node->data == right) {
                leftnode = NodeLink(leftnode->node, left, right);
            }
        }
    }
}

int FindNode(TreeNode *r, int i) {
    if (r != NULL) {
        if (r->data == i) return r->node->data;
        int left = FindNode(r->left, i);
        if (left != 0) return left;
        int right = FindNode(r->right, i);
        if (right != 0) return right;
    }
    return 0;
}

int main(void) {
    int number;
    TreeNode *root = NodeCreate(NULL, 1);

    scanf("%d", &number);
    TreeNodeCreate(root, number);

    for (int i = 2; i<=number;i++) {
        printf("%d > %d\n", i, FindNode(root, i));
    }
    return 0;
}