#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int count;
} Queue;

Queue* init(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * size);
    q->count = 0;
    return q;
}

int isFull(Queue* q, int size) {
    return q->count == size;
}

int isEmpty(Queue* q) {
    return q->count == 0;
}

void enqueue(Queue* q, int data, int size) {
    if (isFull(q, size)) return;
    q->data[q->count++] = data;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return 0;
    int data = q->data[0];
    for (int i = 1; i < q->count; i++) q->data[i-1] = q->data[i];
    q->count--;
    return data;
}

void print(Queue* q) {
    if (isEmpty(q)) return;
    printf("%d\n", q->data[q->count-1]);
}

int main() {
    int size;
    scanf("%d", &size);
    Queue* q = init(size);

    for (int i = 1; i <= size+1; i++) {
        if (isFull(q, size)) printf("Queue is full. Cannot enqueue.\n");
        else {
            enqueue(q, i, size);
            print(q);
        }
    }
    for (int i = 1; i <= size+1; i++) {
        if (isEmpty(q)) printf("Queue is empty. Cannot dequeue.\n0\n");
        else printf("%d\n", dequeue(q));
    }
    free(q->data);
    free(q);
    return 0;
}