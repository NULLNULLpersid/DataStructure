/*
50점
aaAbBb -> 3a3b로 출력
*/
#include <stdio.h>
#include <string.h>
#define SIZE 255

typedef struct {
    char data[SIZE];
    int top;
}Stack;

void Init(Stack * stack) {
    for (int i = 0; i < SIZE; i++) stack->data[i] = '\0';
    stack->top = -1;
}

int Full(Stack *stack) {
    return (stack->top >= SIZE - 1) ? 1 : 0;
}

int Empty(Stack *stack) {
    return (stack->top < 0) ? 1 : 0;
}

void push(Stack *stack, char data) {
    if (Full(stack)) return ;
    else {
        stack->top += 1;
        stack->data[stack->top] = data;
    }
}

char pop(Stack *stack) {
    if (Empty(stack)) return '\0';
    else {
        stack->top -= 1;
        return ('a' <= stack->data[stack->top] && stack->data[stack->top] <= 'z') ? stack->data[stack->top] - 32 : stack->data[stack->top];
    }
}

void Start(char str[SIZE], int len) {
    char temp;
    int count = 1;
    Stack stack;
    Init(&stack);
    for (int i = len; 0 <= i; i--) {
        push(&stack, str[i]);
    }
    for (int i = 0; i < len; i++) {
        temp = ('a' <= str[i] && str[i] <= 'z') ? str[i] - 32 : str[i];
        if (temp != pop(&stack)) {
            printf("%d%c", count, temp);
            count = 1;
        }
        else {
            count += 1;
        }
    }
    
}

int main(void) {
    char input[SIZE];
    scanf("%s", input);
    Start(input, strlen(input));
    return 0;
}