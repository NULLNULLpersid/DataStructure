// #include <stdio.h>
// #include <stdlib.h>

// // 순열을 위한 swap 함수
// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // 모든 순열을 생성하고 각 순열로 부피를 계산하는 함수
// void calculateVolume(int *array, int start, int end) {
//     if (start == end) {
//         printf("부피 = %d x %d x %d = %d\n", array[0], array[1], array[2], array[0] * array[1] * array[2]);
//     } else {
//         for (int i = start; i <= end; i++) {
//             swap(&array[start], &array[i]);
//             calculateVolume(array, start + 1, end);
//             swap(&array[start], &array[i]); // 백트래킹
//         }
//     }
// }

// int main() {
//     int array[3];

//     // 사용자로부터 세 개의 정수 입력받기
//     printf("세 정수를 입력하세요: ");
//     for (int i = 0; i < 3; i++) {
//         scanf("%d", &array[i]);
//     }

//     // 순열 생성 및 부피 계산
//     calculateVolume(array, 0, 2);

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *element;  // 요소 배열
    int heap_size; // 현재 힙의 크기
    int capacity;  // 최대 용량
} HeapType;

// 힙 생성
HeapType* create_heap(int capacity) {
    HeapType *heap = (HeapType*)malloc(sizeof(HeapType));
    heap->element = (int*)malloc(sizeof(int) * capacity);
    heap->heap_size = 0;
    heap->capacity = capacity;
    return heap;
}

// 힙 메모리 해제
void free_heap(HeapType *heap) {
    free(heap->element);
    free(heap);
}

// 요소 삽입
void insert_max_heap(HeapType *heap, int item) {
    int i = ++heap->heap_size;
    while ((i != 1) && (item > heap->element[i / 2])) {
        heap->element[i] = heap->element[i / 2];
        i /= 2;
    }
    heap->element[i] = item;
}

// 최대 요소 삭제
int delete_max_heap(HeapType *heap) {
    int parent, child;
    int item, temp;

    item = heap->element[1];
    temp = heap->element[heap->heap_size--];
    parent = 1;
    child = 2;

    while (child <= heap->heap_size) {
        if ((child < heap->heap_size) && (heap->element[child] < heap->element[child + 1]))
            child++;
        if (temp >= heap->element[child]) break;

        heap->element[parent] = heap->element[child];
        parent = child;
        child *= 2;
    }

    heap->element[parent] = temp;
    return item;
}

int main() {
    int capacity = 50; // 최대 용량
    HeapType *heap = create_heap(capacity);

    // 힙에 요소 삽입
    insert_max_heap(heap, 10);
    insert_max_heap(heap, 30);
    insert_max_heap(heap, 5);

    // 힙에서 최대값 삭제
    printf("Deleted max: %d\n", delete_max_heap(heap));

    free_heap(heap);
    return 0;
}