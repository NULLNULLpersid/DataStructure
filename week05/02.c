#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
} Node;

Node* add_node(Node* h, int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    if (h == NULL) {
        h = n;
        h->next = n;
    } else {
        n->next = h->next;
        h->next = n;
    }
    return n;
}

Node* del_node(Node* h) {
    Node* n = h->next;
    if (n == h) {
        free(h);
        return NULL;
    }
    h->next = n->next;
    free(n);
    return h;
}

void print(Node* h) {
    printf("%d, ", h->data);
}

int main() {
    Node *head = NULL;
    int N, K;
    scanf("%d %d", &N, &K);
    
    for (int i = 0; i < N; i++) head = add_node(head, i+1);
    
    while (head->next != head) {
        for (int i = 0; i < K-1; i++) head = head->next;
        printf("%d, ", head->next->data);
        head = del_node(head);
    }
    printf("%d ", head->data);
    free(head);
    return 0;
}