#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *CreateNode(char data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

TreeNode **CreateNodeList(int num) {
    TreeNode **nodelist = (TreeNode**)malloc(sizeof(TreeNode) * num);
    for (int i = 0; i < num; i++) nodelist[i] = CreateNode('A'+i);
    return nodelist;
}

TreeNode* FindNodeList(TreeNode** nodelist, char data, int num) {
    for (int i = 0; i < num; i++) if (nodelist[i]->data == data) return nodelist[i];
    return NULL;
}

void NodeLink(TreeNode* root, TreeNode *leftnode, TreeNode *rightnode){
    root->left = leftnode;
    root->right = rightnode;
}

TreeNode* CreateTreeNode(TreeNode **nodelist, int num) {
    char root, left, right;
    
    for (int i = 0; i < num; i++) {    
        scanf(" %c %c %c", &root, &left, &right);
        NodeLink(FindNodeList(nodelist, root, num), FindNodeList(nodelist, left, num), FindNodeList(nodelist, right, num));
    }
    return nodelist[0];
}

void PreorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%c", root->data);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}
void InorderTraversal(TreeNode* root) {
    if (root != NULL) {
        InorderTraversal(root->left);
        printf("%c", root->data);
        InorderTraversal(root->right);
    }
}
void PostorderTraversal(TreeNode* root) {
    if (root != NULL) {
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        printf("%c", root->data);
    }
}

void print(TreeNode* root) {
    PreorderTraversal(root);
    printf("\n");
    InorderTraversal(root);
    printf("\n");
    PostorderTraversal(root);
}

int main(void) {
    int num;
    scanf("%d", &num);
    
    TreeNode* root = CreateTreeNode(CreateNodeList(num), num);

    print(root);

    return 0;
}