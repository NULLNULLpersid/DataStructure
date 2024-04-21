/*
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right, *node;
}TreeNode;

TreeNode *CreateNode(TreeNode *n, int data) {
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
        TreeNode *node = CreateNode(n, l);
        n->left = node;
        return node;
    }
    else if (n->data == l) {
        TreeNode *node = CreateNode(n, r);
        n->right = node;
        return node;
    }
    else return NULL;
}


int main(void) {
    int number, right, left;
    TreeNode *root = NULL;
    root = CreateNode(root, 1);
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

TreeNode *CreateNode(TreeNode *n, int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = node->parent = NULL;
    if (n != NULL) node->parent = n;
    return node;
}

TreeNode* NodeLink(TreeNode *n, int r, int l){
    if (n->data == r) {
        TreeNode *node = CreateNode(n, l);
        n->right = node;
        return node;
    }
    else if (n->data == l) {
        TreeNode *node = CreateNode(n, r);
        n->left = node;
        return node;
    }
    else {
            return NodeLink(n->parent, r, l);
    }
}

void TreeCreateNode(TreeNode *r, int num) {
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
    TreeNode *root = CreateNode(NULL, 1);

    scanf("%d", &number);
    TreeCreateNode(root, number);

    for (int i = 2; i<=number;i++) {
        printf("%d > %d\n", i, FindNode(root, i)->parent->data);
    }
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

//구조체 선언 함수
typedef struct TreeNode {
    int data, type;
    struct TreeNode *left, *right, *parent;
} TreeNode;

//노드 생성 및 초기화 함수
TreeNode *CreateNode(int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->type = 0;
    node->left = node->right = node->parent = NULL;
    return node;
}

//노드의 주소가 들어있는 동적배열 생성 함수
TreeNode **CreateNodeList(int num) {
    TreeNode **nodelist = (TreeNode**)malloc(sizeof(TreeNode) * num);
    for (int i = 0; i < num; i++) nodelist[i] = CreateNode(i+1);
    return nodelist;
}

//데이터가 들어 있는 노드의 주소 찾는 함수
TreeNode* FindNodeList(TreeNode** nodelist, int data, int num) {
    for (int i = 0; i < num; i++) if (nodelist[i]->data == data) return nodelist[i];
    return NULL;
}

/*
각 노드를 트리로 연결하는 함수
    
    왼쪽노드가 부모가 없고 루트가 아닌 경우 : 왼쪽노드 True
    오른쪽노드가 부모가 없고 루트가 아닌 경우 : 오름쪽노드 True

    왼쪽노드, 오른쪽노드 둘다 True인 경우 : 
        왼쪽노드의 오른쪽을 오른쪽노드에 연결
        오른쪽노드의 왼쪽을 왼쪽노드에 연결
        오른쪽노드, 왼쪽노드 False

    왼쪽노드가 True인 경우 : 
        오른쪽 노드를 부모노드, 왼쪽노드를 자식노드
        
        자식노드에 다른노드가 연결되어있을 경우 : 
            왼쪽노드 False
            다른노드의 연결을 끊고 자식노드를 새로운 부모노드로 다른노드를 자식노드로 변경해서 재귀

        왼쪽노드 False
    
    오른쪽노드가 True인 경우 : 
        왼쪽노드를 부모노드, 오른쪽노드를 자식노드
        
        자식노드에 다른노드가 연결되어있을 경우 : 
            오른쪽노드 False
            다른노드의 연결을 끊고 자식노드를 새로운 부모노드로 다른노드를 자식노드로 변경해서 재귀

        오른쪽노드 False
*/
void NodeLink(TreeNode *leftnode, TreeNode *rightnode){
    if (leftnode->parent == NULL && leftnode->data != 1) leftnode->type = 1;
    if (rightnode->parent == NULL && rightnode->data != 1) rightnode->type = 1;

    if (leftnode->type&&rightnode->type) {
        leftnode->right = rightnode;
        rightnode->left = leftnode;
        leftnode->type = rightnode->type = 0;
    }
    else if (leftnode->type) {
        rightnode->left = leftnode;
        leftnode->parent = rightnode;
        if (leftnode->left != NULL || leftnode->right != NULL) {
            if (leftnode->left != NULL) {
                if (leftnode->left->right == leftnode) {
                    leftnode->left->right = NULL;
                }
                leftnode->type = 0;
                NodeLink(leftnode->left, leftnode);
            }
            if (leftnode->right != NULL) {
                if (leftnode->right->left == leftnode) {
                    leftnode->right->left = NULL;
                }
                leftnode->type = 0;
                NodeLink(leftnode->right, leftnode);
            }
        }
        leftnode->type = 0;
    }
    else if (rightnode->type) {
        leftnode->right = rightnode;
        rightnode->parent = leftnode;
        
        if (rightnode->left != NULL || rightnode->right != NULL) {
            if (rightnode->left != NULL) {
                if (rightnode->left->right == rightnode) {
                    rightnode->left->right = NULL;
                }
                rightnode->type = 0;
                NodeLink(rightnode->left, rightnode);
            }
            if (rightnode->right != NULL){
                if (rightnode->right->left == rightnode) {
                    rightnode->right->left = NULL;
                }
                rightnode->type = 0;
                NodeLink(rightnode->right, rightnode);
            }
        }
        rightnode->type = 0;
    }
    else {
        return ;
    }
}

/*
만든 노드를 트리노드로 바꾸는 함수
*/
TreeNode* CreateTreeNode(TreeNode **nodelist, int num) {
    int left, right;
    
    for (int i = 1; i < num; i++) {    
        scanf("%d %d", &left, &right);
        NodeLink(FindNodeList(nodelist, left, num), FindNodeList(nodelist, right, num));
    }
    return nodelist[0];
}

/*
트리노드를 중위순회
데이터를 못찾은 경우 NULL 반환
데이터를 찾은 경우 데이터가 들어 있는 노드의 주소값 반환
*/
TreeNode* FindTreeNode(TreeNode *root, int data) {
    if (root != NULL) {
        if (root->data == data) return root;
        TreeNode * left = FindTreeNode(root->left, data);
        if (left != NULL) return left;
        TreeNode * right = FindTreeNode(root->right, data);
        if (right != NULL) return right;
    }
    return NULL;
}

/*
출력
2데이터 노드부터 n데이터 노드까지 순차적으로 부모노드를 출력
*/
void print(TreeNode *root, int num) {
    for (int i = 2; i<=num;i++) {
        printf("%d > %d\n", i, FindTreeNode(root, i)->parent->data);
    }
}

//main함수
int main(void) {
    int num;
    scanf("%d", &num);
    
    TreeNode* root = CreateTreeNode(CreateNodeList(num), num);

    print(root, num);

    return 0;
}