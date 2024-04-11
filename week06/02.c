#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    char *name;
    struct NODE *next;
}Node;

Node* add_node(Node* h, char *name) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->name = name;
    if (h == NULL) {
        h = n;
        h->next = n;
    } else {
        n->next = h->next;
        h->next = n;
    }
    return n;
}
void print(Node *h) {
    Node *n = h;
    do {
        printf("Current turn=%s\n", n->name);
        n = n->next;
    } while(n != h);
}
int main(void) {
    Node *head = NULL;
    head = add_node(head, "KIM");
    head = add_node(head, "JUNG");
    head = add_node(head, "LEE");
    head = add_node(head, "CHOI");
    head = add_node(head, "PARK");
    head = head->next;
    print(head);
    print(head);
    return 0;
}