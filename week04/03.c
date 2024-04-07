#include <stdio.h>
#define SIZE 10
typedef char element;
typedef struct {
    element arr[SIZE][SIZE];
    int front, rear;
} QueueType;

void init(QueueType *q){
    for (int i = 0; i < SIZE; i++) for (int j = 0; j < SIZE; j++) q->arr[i][j] = '\0';
    q->front = q->rear = 0;
}

int full(QueueType* q) {
	return (q->rear+1)%SIZE == q->front;
}
int empty(QueueType *q){
	return q->front == q->rear;
}
void enqueue(QueueType *q) {
    if (full(q)) printf("대기열이 가득 찼습니다.\n");
    else {
        char name[SIZE];
        scanf("%s", name);
        for (int i = 0; *(name+i) != '\0'; i++) {
            q->arr[(q->rear+1)%SIZE][i] = *(name+i);
        }
        q->rear++;
    }
}
element* dequeue(QueueType *q) {
    if (empty(q)) {
        printf("대기열이 비어 있습니다.\n");
        return '\0';
    } 
    else {
        int i = 0;
        for (;q->arr[(q->front+1)%SIZE][i] != '\0'; i++) {
            q->arr[(q->rear+1)%SIZE][i] = q->arr[(q->front+1)%SIZE][i];
            q->arr[(q->front+1)%SIZE][i] = '\0';
        }
        q->arr[(q->rear+1)%SIZE][i] = '\0';
        q->front++;
        return q->arr[(q->rear+1)%SIZE];
    }
}
void print(QueueType *q) {
    for (int i = (q->front+1)%SIZE; i != SIZE; i++) {
        if (q->arr[(i+1)%SIZE][0] != '\0') printf("%s, ", q->arr[i]);
        else printf("%s", q->arr[i]);
        
    }
    printf("\n");
}

int main(void) {
    QueueType q;
    int choice;
    init(&q);
    do {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            print(&q);
            break;
        }
    } while(choice < 4);
    return 0;
}