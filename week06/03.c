#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE* next;
}Node;

Node* add_node(Node* h, int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = h;
    return n;
}

Node* del_node(Node* h) {
    Node *n = h->next;
    free(h);
    return n;
}

void print(Node *h) {
    while (h != NULL) {
        printf("%d->", h->data);
        h = h->next;
    }
    printf("NULL\n");
}
int peek_min(Node *h){
    int m = h->data;
    while (h != NULL) {
        if (h->data < m) m = h->data;
        h = h->next;
    }
    return m;
}

int main(void) {
    Node *head = NULL;
    int l[4] = {3, 5, 2, 1};
    printf("Pushing elements onto the stack...\n");
    for (int i = 0; i < 4; i++) {
        head = add_node(head, l[i]);
        print(head);
        printf("Min: %d\n", peek_min(head));
    }
    printf("Popping elements from the stack...\n");
    for (int i = 0; i < 3; i++) {
        head = del_node(head);
        print(head);
        printf("Min: %d\n", peek_min(head));
    }
    return 0;
}