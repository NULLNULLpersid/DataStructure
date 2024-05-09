#include <stdio.h>
#include <stdlib.h>

// 순열을 위한 swap 함수
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 모든 순열을 생성하고 각 순열로 부피를 계산하는 함수
void calculateVolume(int *array, int start, int end) {
    if (start == end) {
        printf("부피 = %d x %d x %d = %d\n", array[0], array[1], array[2], array[0] * array[1] * array[2]);
    } else {
        for (int i = start; i <= end; i++) {
            swap(&array[start], &array[i]);
            calculateVolume(array, start + 1, end);
            swap(&array[start], &array[i]); // 백트래킹
        }
    }
}

int main() {
    int array[3];

    // 사용자로부터 세 개의 정수 입력받기
    printf("세 정수를 입력하세요: ");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &array[i]);
    }

    // 순열 생성 및 부피 계산
    calculateVolume(array, 0, 2);

    return 0;
}