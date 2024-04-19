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

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right, *parent;
} TreeNode;

TreeNode *NodeCreate(TreeNode *n, int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = node->parent = NULL;
    if (n != NULL) node->parent = n;
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
            return NodeLink(n->parent, r, l);
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
        if (leftnode->data == right) {
            leftnode = NodeLink(leftnode, left, right);
        }
        else {
            if (rightnode->parent != NULL && leftnode->parent != NULL) {
                if (rightnode->parent->data == right) {
                    rightnode = NodeLink(rightnode->parent, left, right);
                }
                if (leftnode->parent->data == left) {
                    leftnode = NodeLink(leftnode->parent, left, right);
                }
            }
        }
    }
}

TreeNode * FindNode(TreeNode *r, int i) {
    if (r != NULL) {
        if (r->data == i) return r;
        TreeNode * left = FindNode(r->left, i);
        if (left != NULL) return left;
        TreeNode * right = FindNode(r->right, i);
        if (right != NULL) return right;
    }
    return NULL;
}

int main(void) {
    int number;
    TreeNode *root = NodeCreate(NULL, 1);

    scanf("%d", &number);
    TreeNodeCreate(root, number);

    for (int i = 2; i<=number;i++) {
        printf("%d > %d\n", i, FindNode(root, i)->parent->data);
    }
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right, *parent;
} TreeNode;

TreeNode *NodeCreate(int data) {
    TreeNode *n = (TreeNode*)malloc(sizeof(TreeNode));
    n->data = data;
    n->left = n->right = n->parent = NULL;
    return n;
}

TreeNode **NodeList(int num) {
    TreeNode **l = (TreeNode**)malloc(sizeof(TreeNode) * num);
    for (int i = 0; i < num; i++) l[i] = NodeCreate(i+1);
    return l;
}

void NodeLink(TreeNode *p, TreeNode *n, int num, int d, int true){
}

TreeNode* TreeNodeCreate(TreeNode **list, int num) {
    TreeNode *root = list[0];
    int left, right;
    
    for (int i = 1; i < num; i++) {    
        scanf("%d %d", &left, &right);
        if (root->data == left) {

        }
        if (root->data == right) {

        }
    }
    return root;
}

TreeNode * FindTreeNode(TreeNode *r, int i) {
    if (r != NULL) {
        if (r->data == i) return r;
        TreeNode * left = FindNode(r->left, i);
        if (left != NULL) return left;
        TreeNode * right = FindNode(r->right, i);
        if (right != NULL) return right;
    }
    return NULL;
}

void print(TreeNode *r, int num) {
    for (int i = 2; i<=num;i++) {
        printf("%d > %d\n", i, FindTreeNode(r, i)->parent->data);
    }
}

void FreeList(TreeNode **list, int num) {
    for (int i = 0; i < num; i++) {
        free(list[i]);
    }
    free(list);
}

int main(void) {
    int number;
    scanf("%d", &number);
    TreeNode **list = NodeList(number);
    TreeNode * root = TreeNodeCreate(list, number);

    print(root, number);
    FreeList(list, number);
    return 0;
}