#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

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

typedef struct {
    int data[SIZE];
    int front, rear;
}Queue;

void QueueInit (Queue *queue){
    for (int i = 0; i < SIZE; i++) queue->data[i] = 0;
	queue->front = queue->rear = -1;
}

int QueuFull(Queue* queue) {
	return (queue->rear == SIZE-1) ? 1 : 0;
}

int QueuEmpty(Queue *queue) {
	return (queue->front == queue->rear) ? 1 : 0;
}

void EnQueue(Queue *queue, int data){
	if (QueuFull(queue)) ;
	else {
        queue->data[++(queue->rear)] = data;
    }
}

int DeQueue(Queue *queue) {
	if (QueuEmpty(queue)) ;
    else {
        return queue->data[++(queue->front)];
    }
}

void CreatLevelorder(TreeNode *root, Queue *queue) {
    if (root != NULL) {
        if (root->left != NULL) {
            EnQueue(queue, root->left->data);
        }
        if ((root->right != NULL)) {
            EnQueue(queue, root->right->data);
        }
        CreatLevelorder(root->left, queue);
        CreatLevelorder(root->right, queue);
    }
}

void print(Queue *queue) {
    while (queue->front != queue->rear) {
        printf("%d ", DeQueue(queue));
    }
}

int main(void) {
    TreeNode *root = CreateNode(15);
    NodeLink(root);
    Queue queue;
    QueueInit(&queue);
    CreatLevelorder(root, &queue);
    printf("%d ", root->data);
    print(&queue);
    return 0;
}