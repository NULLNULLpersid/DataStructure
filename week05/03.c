#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data, target_number;
    struct NODE *left, *right;
} Node;

Node* add_node(Node* h, int data, int target_number) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->target_number = target_number;
    if (h == NULL) {
        h = n;
        h->right = n;
        h->left = n;
    } 
    else {
        n->right = h->right;
        h->right->left = n;
        h->right = n;
        n->left = h;
    }
    return n;
}

Node* del_node(Node* h, int move, int target_number) {
    Node* n = h;
    //터트릴 타겟 출력
    printf("%d ",  target_number);
    /*
    터트릴 타겟의 점수만큼 이동 == 다음에 터트릴 타겟
    지금 터트릴 타겟의 점수가 양수일 경우 : 오른쪽 이동
    지금 터트릴 타겟의 점수가 음수일 경우 : 왼쪽 이동
    */
    for (int i = 0; i < abs(move); i++) n =  (move > 0) ? n->right : n->left;
    /*
    다음에 터트릴 타겟이 지금 터트릴 타겟을 경우
    지금 터트릴 타겟의 점수가 양수일 경우 : 오른쪽 이동
    지금 터트릴 타겟의 점수가 음수일 경우 : 왼쪽 이동
    */
    if (n->target_number == target_number) n = (move > 0) ? n->right : n->left;  
    //마지막 타겟의 경우
    if (n->right == n && n->left == n) {
        free(n);
        return NULL;
    }
    //타겟 제거
    h->right->left = h->left;
    h->left->right = h->right;
    free(h);
    //다음 타겟 위치 리턴
    return n;
}

int main() {
    Node *head = NULL;
    int number, score;
    //타겟의 개수 입력받음
    scanf("%d", &number);
    /*
    각 타겟의 점수를 입력
    각 타겟에 번호를 부여하며, 점수를 저장하여 생성
    */
   for (int i = 1; i <= number; i++) {
        scanf("%d", &score);
        head = add_node(head, score, i);
    }
    //첫번째 타겟으로 헤더 이동
    head = head->right;
    /*
    타겟이 전부 없어질때까지 반복
    헤더를 다음 타겟으로 이동
    */
    while (head != NULL) head = del_node(head, head->data, head->target_number);
    return 0;
}