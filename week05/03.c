#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int score;
    struct NODE *left, *right;
} Node;

void init(Node * n, int score) {
    n->score = score;
    n->left = n->right = NULL;
}
Node* add_right_node(Node* h, int score) {
    Node *n = (Node*)malloc(sizeof(Node));
    init(n, score);
    if (h == NULL) {
        h = n;
    }
    else {
        h->right = n;
        n->right = h;
    }

}
void print(Node *h) {
    printf("%d", h->score);    
}

int main() {
    Node *head = NULL;
    int N, score;
    for (int i = 0; i < N; i++) {
        scanf("%d", &score);
        head = add_right_node(head, score);
    }
    return 0;
}