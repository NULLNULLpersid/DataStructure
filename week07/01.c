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
    if (n == NULL) {
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
        n->right = node;
        return node;
    }
    else if (n->data == l) {
        TreeNode *node = NodeCreate(n, r);
        n->left = node;
        return node;
    }
    else {
        if (n->node->data == r) {
            TreeNode *node = NodeCreate(n->node, l);
            n->node->right = node;
            return node;
        }
        else if (n->node->data == l) {
            TreeNode *node = NodeCreate(n->node, r);
            n->node->left = node;
            return node;
        }
    }
}

int FindNode(TreeNode *r, int i) {
    if (r) {
        if (r->data == i) return r->node->data;
        FindNode(r->left, i);
        FindNode(r->right, i);
    }
}

int main(void) {
    int number, right, left;
    TreeNode *root = NULL;
    scanf("%d", &number);
    root = NodeCreate(root, 1);
    TreeNode *node = root, *rightnode = root, *leftnode = root;

    for (int i = 1; i < number; i++) {
        scanf("%d %d", &right, &left);
        if (rightnode->data == right) {
            rightnode = NodeLink(rightnode, right, left);
        }
        if (leftnode->data == left) {
            leftnode = NodeLink(leftnode, left, right);
        }
    }
    for (int i = 2; i<=number;i++) {
        printf("%d > %d\n", i, FindNode(root, i));
    }
    return 0;
}