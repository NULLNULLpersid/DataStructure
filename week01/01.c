#include <stdio.h>
#define SIZE 5

int iarray[SIZE];

// 배열에 값 저장 함수
void store(int i, int item) {
    iarray[i] = item;
}

// 배열에서 값 추출 함수
int retrieve(int i) {
    return iarray[i];
}

int main() {
    int i, sum = 0;

    // 정수 배열을 사용하여 배열 생성
    for (i = 0; i < SIZE; i++) {
        store(i, i + 1);
    }

    // 배열에서 값 추출하여 합 계산
    for (i = 0; i < SIZE; i++) {
        sum += retrieve(i);
    }
    
    // 배열의 인덱스 별 내용 출력
    for (i = 0; i < SIZE; i++) {
        printf("%d %d\n", i, iarray[i]);
    }
  
    // 결과 출력
    printf("%d\n", sum);
    return 0;
}