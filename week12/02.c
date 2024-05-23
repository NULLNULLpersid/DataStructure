#include <stdio.h>
#include <stdlib.h>
#define SIZE 255

size_t strlen(char *str){
    size_t len = 0;
    while (*(str+len) != '\0') len++;
    return len;
}


int main(void) {
    int n;
    char **str = (char **)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) scanf("%s", str[i]);
    printf(" %s", str[0]);

    return 0;
}