/*
30점

0이면 스택, 1이면 큐
    
a 이면 데이터 추가
r 이면 데이터 제거
e 이면 종료
*/

#include <stdio.h>
#define SIZE 10

typedef struct {
    int data[SIZE];
    int top;
}Stack;

void StackInit(Stack * stack) {
    for (int i = 0; i < SIZE; i++) stack->data[i] = 0;
    stack->top = -1;
}

int StackFull(Stack *stack) {
    return (stack->top >= SIZE - 1) ? 1 : 0;
}

int StackEmpty(Stack *stack) {
    return (stack->top < 0) ? 1 : 0;
}

void push(Stack *stack, int data) {
    if (StackFull(stack)) return ;
    else {
        stack->data[++(stack->top)] = data;
    }
}

void pop(Stack *stack) {
    if (StackEmpty(stack)) return ;
    else {
        stack->top -= 1;
    }
}

void StackPrint(Stack *stack) {
    if (StackEmpty(stack)) printf("Empty\n") ;
    else {
        for (int i = 0; i <= stack->top; i++) {
            (i == stack->top) ? printf("%d\n", stack->data[i]) : printf("%d ", stack->data[i]);
        }
    }
}

void StartStack() {
    char ch;
    int data;
    Stack stack;
    StackInit(&stack);

    do {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'a':
            scanf(" %d", &data);
            push(&stack, data);
            StackPrint(&stack);
            break;

        case 'r':
            pop(&stack);
            StackPrint(&stack);
            break;

        default:
            break;
        }
    } while (ch != 'e');
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

void DeQueue(Queue *queue) {
	if (QueuEmpty(queue)) ;
    else {
        queue->data[++(queue->front)];
    }
}

void QueuePrint(Queue *queue){
    if (QueuEmpty(queue)) printf("Empty\n");
    else {
        for (int i = queue->front + 1; i <= queue->rear; i++) {
            (i == queue->rear) ? printf("%d\n", queue->data[i]) : printf("%d ", queue->data[i]);
        }
    }
}

void StartQueue () {
    char ch;
    int data;
    Queue queue;
    QueueInit(&queue);

    
    do {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'a':
            scanf(" %d", &data);
            EnQueue(&queue, data);
            QueuePrint(&queue);
            break;

        case 'r':
            DeQueue(&queue);
            QueuePrint(&queue);
            break;

        default:
            break;
        }
    } while (ch != 'e');
}

int main(void) {
    int input;
    scanf("%d", &input);
    if (input) StartQueue();
    else StartStack();
    return 0;
}