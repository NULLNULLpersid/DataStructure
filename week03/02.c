#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return (s->top == -1);
}

void push(Stack* s, char data) {
    s->arr[++(s->top)] = data;
}

char pop(Stack* s) {
    return s->arr[(s->top)--];
}

int isMatchingPair(char s, char e) {
    return (s == e);
}

int isBalanced(char* e) {
    Stack s;
    initialize(&s);
    for (int i = 0; i < strlen(e); i++) {
        switch (*(e + i))
        {
        case '(': case '[': case '{':
            push(&s, *(e + i));
            break;
        case ')': case ']': case '}':
            if (isEmpty(&s) && isMatchingPair(s.arr[s.top], *(e+i))) return 1;
            pop(&s);
            break;
        }
    }
    return (isEmpty(&s));
}

int main() {
    char expression[MAX_SIZE];
    scanf("%s", expression);
    (isBalanced(expression)) ? printf("Balanced\n") : printf("Not Balanced\n");

    return 0;
}