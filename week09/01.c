#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *element;
    int now_size;
    int max_size;
} HeapType;

HeapType* create_heap(int size) {
    HeapType *heap = (HeapType*)malloc(sizeof(HeapType));
    heap->element = (int*)malloc(sizeof(int) * size);
    heap->now_size = 0;
    heap->max_size = size;
    return heap;
}

// 힙 메모리 해제
void free_heap(HeapType *heap) {
    free(heap->element);
    free(heap);
}

// 요소 삽입
void insert_max_heap(HeapType *heap, int item) {
    int i = ++heap->now_size;
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
    temp = heap->element[heap->now_size--];
    parent = 1;
    child = 2;

    while (child <= heap->now_size) {
        if ((child < heap->now_size) && (heap->element[child] < heap->element[child + 1])) child++;
        if (temp >= heap->element[child]) break;

        heap->element[parent] = heap->element[child];
        parent = child;
        child *= 2;
    }
    heap->element[parent] = temp;
    return item;
}

int main() {
    int max_size = 3 , input; // 최대 용량
    HeapType *heap = create_heap(max_size);

    // 힙에 요소 삽입
    for (int i = 0; i < 3; i++) {
        scanf("%d", &input);
        insert_max_heap(heap, input);
    }

    // 힙에서 최대값 삭제
    for (int i = 0; i < 3; i++) {
        printf("<%d>", delete_max_heap(heap));
    }
    free_heap(heap);

    return 0;
}