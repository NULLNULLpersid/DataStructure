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
        n->next = h;
    } else {
        n->next = h->next;
        h->next = n;
    }
    return n; // 새로 추가된 노드를 반환
}

Node* del_node(Node* h) {
    if (h == NULL) return NULL;
    Node* n = h->next;
    if (n == h) { // 리스트에 하나의 노드만 있는 경우
        free(h);
        return NULL;
    }
    h->next = n->next;
    free(n);
    return h; // 헤드 노드를 반환
}

void print(Node* h) {
    if (h == NULL) return;
    Node* n = h;
    do {
        printf("%d ", n->data);
        n = n->next;
    } while (n != h); // 리스트의 처음 노드까지 출력
    printf("\n");
}

int main() {
    Node *head = NULL;
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) head = add_node(head, i);
    
    for (int i = 0; i < K-1; i++) head = head->next;
    head = del_node(head);
    print(head);
    for (int i = 0; i < K-1; i++) head = head->next;
    head = del_node(head);
    print(head);
    return 0;
}