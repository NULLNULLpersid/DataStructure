#include <stdio.h>
#include <stdlib.h>

//1. 구조체 정의
typedef struct NODE{
    int data;
    struct NODE* next;
}Node;

//2. 리스트의 모든 항목을 순회하면 출력하는 함수
void print(Node *h) {
    Node *n = h;
    do {
        printf("%d->", n->data);
        n = n->next;
    } while(n != NULL);
}

//3. 새로운 노드를 리스트의 첫 부분에 삽입하는 함수
Node *add_first_node(Node*h, int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    h = n;
    h->next = NULL;
    return h;
}

//4. 새로운 노드를 리스트의 마지막 부분에 삽입하는 함수
void add_last_node(Node *h, int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    while (h->next != NULL) {
        h = h->next;
    }
    h->next = n;
    n->next = NULL;
}

int main(void) {
    Node *head = NULL;
    head = add_first_node(head, 10);
    add_last_node(head, 20);
    add_last_node(head, 30);
    add_last_node(head, 40);
    print(head);
    return 0;
}

