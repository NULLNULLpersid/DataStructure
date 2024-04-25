/*
0이면 스택, 1이면 큐
    
a 이면 추가
r 이면 제거
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

int isFull(Stack *stack) {
    return (stack->top >= SIZE - 1) ? 0 : 1;
}

int isEmpty(Stack *stack) {
    return (stack->top < 0) ? 0 : 1;
}

void push(Stack *stack, int data) {
    if (isFull(stack)) return ;
    else stack->data[++(stack->top)] = data;
}

int pop(Stack *stack) {
    return (isEmpty(stack)) ? printf("Empty") : stack->data[(stack->top)--];
}

void StackPrint(Stack *stack) {
    if (isEmpty(stack)) printf("Empty") ;
    else {
        for (int i = 0; i <= stack->top; i++) {
            (i == stack->top) ? printf("%d\n", stack->data[i]) : printf("%d ", stack->data[i]);
        }
    }
}

void StartStack() {
    char ch;
    int data;
    Stack *stack;
    StackInit(&stack);

    while (1) {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'a':
            scanf(" %d", &data);
            push(stack, data);
            StackPrint(stack);
            break;

        case 'r':
            pop(stack);
            StackPrint(stack);
            break;

        case 'e':
            return ;

        default:
            break;
        }
    }
}

typedef struct {
    int data[SIZE];
    int front, rear;
}Queue;

void QueueInit (Queue *queue){
    for (int i = 0; i < SIZE; i++) queue->data[i] = 0;
	queue->front = queue->rear = 0;
}

void StartQueue () {
    char ch;
    int data;
    Queue *queue;
    QueueInit(&queue);

    
    while (1) {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'a':
            scanf(" %d", &data);
            break;

        case 'r':
            break;

        case 'e':
            return ;

        default:
            break;
        }
    }
}

int main(void) {
    int input;
    scanf("%d", &input);
    if (input) StartStack();
    else StartQueue();
    return 0;
}