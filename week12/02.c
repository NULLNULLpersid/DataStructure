// #include <stdio.h>
// #include <stdlib.h>
// #define SIZE 255

// size_t strlen(char *str){
//     size_t len = 0;
//     while (*(str+len) != '\0') len++;
//     return len;
// }


// int main(void) {
//     int n;
//     char **str = (char **)malloc(sizeof(char*) * n);
//     for (int i = 0; i < n; i++) scanf("%s", str[i]);
//     printf(" %s", str[0]);

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 101

// 비교 함수: 길이가 짧은 순, 길이가 같으면 사전순
int compare(const void *a, const void *b) {
    char *word1 = *(char **)a;
    char *word2 = *(char **)b;
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len1 != len2) {
        return len1 - len2;
    } else {
        return strcmp(word1, word2);
    }
}

int main() {
    int N;
    char *words[MAX_WORDS];
    char buffer[MAX_LENGTH];

    // 입력 받기
    scanf("%d", &N);
    getchar(); // 개행 문자 제거

    int count = 0;
    for (int i = 0; i < N; i++) {
        fgets(buffer, MAX_LENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // 개행 문자 제거

        // 중복 제거를 위해 이미 있는지 확인
        int exists = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(words[j], buffer) == 0) {
                exists = 1;
                break;
            }
        }

        if (!exists) {
            words[count] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(words[count], buffer);
            count++;
        }
    }

    // 정렬
    qsort(words, count, sizeof(char *), compare);

    // 출력
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
        free(words[i]); // 동적 할당 해제
    }

    return 0;
}