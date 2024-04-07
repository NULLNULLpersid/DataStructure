#include <stdio.h>
#define MAX_SIZE 30

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top >= 0);
}

void push(Stack *s, char data) {
    s->arr[++(s->top)] = data;
}

char pop(Stack *s) {
    return s->arr[(s->top)--];
}

int main() {
    char input[MAX_SIZE], reversed[MAX_SIZE];
    int i = 0;
  	Stack s;
    initialize(&s);
	
    scanf("%s", input);
    
    for (i = 0; i < MAX_SIZE && *(input+i) != '\0'; i++) push(&s, *(input+i));
    for (i = 0; i < MAX_SIZE && isEmpty(&s); i++) *(reversed + i) = pop(&s);
  	*(reversed + i) = '\0';

    printf("%s", reversed);
    
    return 0;
}